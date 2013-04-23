#include <QtGui/QFileDialog>
#include <QtGui/QLabel>
#include <QtGui/QMessageBox>
#include <QDebug>

#include "MapsListWidget.h"
#include "MapWindow.h"
#include "PropertyWidget.h"
#include "HistoryModel.h"
#include "Exception/FileNotFoundException.h"
#include "Utils/Dispatcher.h"

MapsListWidget::MapsListWidget(  Atlas* const atlas, QWidget* parent )
	: QWidget( parent )
	, _atlas( atlas )
	, _visibleMapItem( 0 )
{
	_ui.setupUi( this );
	setAttribute( Qt::WA_NoMousePropagation );
		
	_rootItems.insert( Map::Vector, _ui.treeWidget->topLevelItem( 0 ) );
	_rootItems.insert( Map::Matrix, _ui.treeWidget->topLevelItem( 1 ) );
	_rootItems.insert( Map::Raster, _ui.treeWidget->topLevelItem( 2 ) );
		
	_ui.treeWidget->topLevelItem( 0 )->setExpanded( true );
	_ui.treeWidget->topLevelItem( 1 )->setExpanded( true );
	_ui.treeWidget->topLevelItem( 2 )->setExpanded( true );

	_ui.treeWidget->topLevelItem( 0 )->setSelected( true );
	_ui.treeWidget->setCurrentItem( _ui.treeWidget->topLevelItem( 0 ) );

	_filters.insert( Map::Vector, "*.map" );
	_filters.insert( Map::Matrix, "*.mtw" );
	_filters.insert( Map::Raster, "*.rsw" );

	//get maps from atlas from history
	//_atlas->setParent( this );
	QList< MapSharedPointer > mapsList;
	try
	{
		mapsList = _atlas->GetAllMaps();
	}
	catch( Exception::FileNotFoundException& e )
	{
        Utils::Dispatcher::Instance()->SendMessage(e.GetMessage(), MessageLevel::Error);
		return;
	}
	
	foreach( MapSharedPointer map, mapsList )
	{
		const int column( 0 );
		QTreeWidgetItem* const item = CreateItem( column, map );
		AddItem( _rootItems.value( map->GetType() ), item, map->GetType(), column );

		if ( _atlas->IsCurrentMap( map ) )
		{
			SetCurrentItem( item, column, map->GetType() );
		}
		else
		{
			//nothing
		}

		if ( _atlas->IsVisibleMap( map ) )
		{
			SetVisibleMapItem( item, column );
		} 
		else
		{
			//nothing
		}
	}
}

MapsListWidget::~MapsListWidget()
{
}

void MapsListWidget::on_addPushButton_clicked()
{
	QTreeWidgetItem* const parentItem(  _ui.treeWidget->currentItem() );
	const int column( _ui.treeWidget->currentColumn() );
	if ( !parentItem || !parentItem->isSelected() || !IsTopLevelItem( parentItem ) )
		return;

	Map::DataType type = _rootItems.key( parentItem );

	QTreeWidgetItem* const item = CreateItem( column, OpenMap( type ) );
	AddItem( parentItem, item, type, column );

	_ui.treeWidget->currentItem()->setExpanded( true );
}

void MapsListWidget::on_deletePushButton_clicked()
{
	QTreeWidgetItem* const deleteItem( _ui.treeWidget->currentItem() );
	const int column( _ui.treeWidget->currentColumn() );
	
	if ( !deleteItem || IsTopLevelItem( deleteItem ) )
		return;
	
	CloseMap( deleteItem->data( column, MapIdRole ).toInt() );

	if ( IsCurrentItem( deleteItem, column ) )
	{
		DeleteCurrentItem( deleteItem, column );
	}
	else
	{
		//nothing
	}

	if ( _visibleMapItem && IsVisibleMapItem( deleteItem ) )
	{
		_visibleMapItem = 0;
	}
	else
	{
		//nothng
	}

	DeleteItem( deleteItem, column );
}

void MapsListWidget::on_showPushButton_clicked()
{
	QTreeWidgetItem* const showItem( _ui.treeWidget->currentItem() );
	if ( !showItem || IsTopLevelItem( showItem ) )
		return;

	SetVisibleMapItem( showItem, _ui.treeWidget->currentColumn() );
}

void MapsListWidget::on_treeWidget_itemDoubleClicked( QTreeWidgetItem* item, int column )
{
	on_addPushButton_clicked();
	item->setExpanded( false );
	
	SetCurrentItem( item, column, _rootItems.key( item->parent() ) );
}

MapSharedPointer MapsListWidget::OpenMap( Map::DataType type )
{
	QString path( QFileDialog::getOpenFileName( this, tr( "Open" ), "../_map", _filters[ type ] ) );
	
	if ( path.isEmpty() )
		return QSharedPointer< Map >();
	
	try
	{
		return _atlas->OpenMap( path, type );
	}
	catch ( Exception::FileNotFoundException& e )
	{
		QMessageBox::warning( 0, "Ошибка", e.what() );
		return MapSharedPointer();
	}
}

void MapsListWidget::CloseMap( const int mapId ) const
{
	_atlas->CloseMap( mapId );
}

void MapsListWidget::SetMapOnScreen( const int mapId ) const
{
	_atlas->SetMapOnScreen( mapId  );
}

QTreeWidgetItem* MapsListWidget::CreateItem( const int column, QSharedPointer< Map > map ) const
{
	if ( !map )
		return 0;

	QTreeWidgetItem* const newItem = new QTreeWidgetItem( QStringList( map->GetName() ) );
	newItem->setData( column, MapIdRole, map->GetId() );
	return newItem;
}

void MapsListWidget::AddItem( QTreeWidgetItem* const parentItem, 
	QTreeWidgetItem* const item, Map::DataType type, const int column )
{
	if ( !parentItem && !item )
		return;

	parentItem->addChild( item );

	if ( !_currentItems.value( type ) )
	{
		SetCurrentItem( item, column, type );
	}
	else
	{
		//nothing
	}

	emit ShowMapsList();
}

void MapsListWidget::DeleteItem( QTreeWidgetItem* const deleteItem, const int column )
{
	_ui.treeWidget->removeItemWidget( deleteItem, column );
	delete deleteItem;
}

bool MapsListWidget::IsTopLevelItem( QTreeWidgetItem* const item ) const
{
	return ( _rootItems.key( item ) != Map::WrongDataType );
}

void MapsListWidget::SetVisibleMapItem( QTreeWidgetItem* const item, int column )
{
	if ( !item )
		return;

	if ( !IsVisibleMapItem( item ) )
	{
		if ( _visibleMapItem )
		{
			_visibleMapItem->setData( column, Qt::BackgroundRole, QVariant() );
		}
		else
		{
			//nothing
		}

		_visibleMapItem = item;
		item->setData( column, Qt::BackgroundRole, QBrush( Qt::red ) );
		
		QVariant data =item->data( column, MapIdRole );
		SetMapOnScreen( data.toInt() );
	}
	else
	{
		//nothing
	}
}

bool MapsListWidget::IsVisibleMapItem( QTreeWidgetItem* const item )
{
	return ( item == _visibleMapItem );
}

void MapsListWidget::SetCurrentItem( QTreeWidgetItem* const item, int column, Map::DataType type )
{
	if ( !item || IsTopLevelItem( item ) || IsCurrentItem( item, column ) )
		return;

	
	const int id = item->data( column, Qt::UserRole ).toInt();
	_atlas->SetCurrentMap( id );

	item->setData( column, Qt::DecorationRole, QIcon( ":/icons/check.png" ) );
		
	if ( _currentItems.value( type ) )
	{
		_currentItems[ type ]->setData( column, Qt::DecorationRole, QVariant() );
	}
	else
	{
		//nothing 
	}

	_currentItems[ type ] = item;
}

void MapsListWidget::DeleteCurrentItem( QTreeWidgetItem* const deleteItem, int column )
{
	if ( !deleteItem || IsTopLevelItem( deleteItem ) )
		return;
	
	Map::DataType deleteItemType = _rootItems.key( deleteItem->parent() );

	QTreeWidgetItem* const itemAbove = _ui.treeWidget->itemAbove( deleteItem );
	QTreeWidgetItem* const itemBelow = _ui.treeWidget->itemBelow( deleteItem );
	if ( itemAbove && itemAbove->parent() )
	{
		SetCurrentItem( itemAbove, column, deleteItemType );
	}
	else if ( itemBelow && itemBelow->parent() )
	{
		SetCurrentItem( itemBelow, column, deleteItemType );
	}
	else
	{
		_currentItems[ deleteItemType ] = 0;
	}
}

bool MapsListWidget::IsCurrentItem( QTreeWidgetItem* const item, const int column ) const
{
	if ( !item )
		return false;

	QVariant data = item->data( column, Qt::DecorationRole );
	return !data.isNull();
}
