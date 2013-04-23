#include "ObjectsListWidget.h"
#include "MapWindow.h"

ObjectsListWidget::ObjectsListWidget( QWidget* parent )
        : QWidget( parent )
{
	_ui.setupUi( this );
	setAttribute( Qt::WA_NoMousePropagation );
}

ObjectsListWidget::~ObjectsListWidget()
{
	qDeleteAll( _objectModelsTable );
}

 
void ObjectsListWidget::on_layersListWidget_itemClicked( QListWidgetItem* layerItem )
{
	if ( !layerItem )
		return;
	
	ShowObjects( layerItem );
}

void ObjectsListWidget::on_layersListWidget_currentItemChanged( QListWidgetItem* currentItem, QListWidgetItem* previousItem )
{
	if ( !currentItem || !previousItem)
		return;

	ShowObjects( currentItem );
}

void ObjectsListWidget:: on_layersListWidget_itemChanged( QListWidgetItem* layerItem  )
{
	if ( !layerItem )
		return;
	
	SetCheckStateAllObjectItems( layerItem, layerItem->checkState() );

	_ui.applyButton->setEnabled( true );
}

void ObjectsListWidget::ObjectItemChanged( QStandardItem* objectItem )
{
	if ( !objectItem )
		return;

	const int countCheckObjectItems( CalculateCheckObjectItems( objectItem->model() ) );
	SetCheckStateLayerItemByCheckStateObjectItem( _objectModelsTable.key( objectItem->model() ),
		countCheckObjectItems );

	_ui.applyButton->setEnabled( true );
}

void ObjectsListWidget::on_uncheckAllLayerButton_clicked()
{
	SetCheckStateAllLayerItems( Qt::Unchecked );
}

void ObjectsListWidget::on_checkAllLayerButton_clicked()
{
	SetCheckStateAllLayerItems( Qt::Checked );
}

void ObjectsListWidget::on_uncheckAllObjectButton_clicked()
{
	SetCheckStateAllObjectItems( _ui.layersListWidget->currentItem(), Qt::Unchecked );
}

void ObjectsListWidget::on_checkAllObjectButton_clicked()
{
	SetCheckStateAllObjectItems( _ui.layersListWidget->currentItem(), Qt::Checked );
}

void ObjectsListWidget::on_applyButton_clicked()
{
 	_ui.applyButton->setEnabled( false );
	WriteLayers();
}

void ObjectsListWidget::SetCheckStateAllLayerItems( Qt::CheckState checkState )
{
	foreach ( QListWidgetItem* const layerItem, _objectModelsTable.keys() )
	{
		layerItem->setCheckState( checkState );
	}
}

void ObjectsListWidget::SetCheckStateAllObjectItems( QListWidgetItem* const layerItem, Qt::CheckState checkState )
{
	QStandardItemModel* const objectsModel( _objectModelsTable.value( layerItem ) );
	if ( !layerItem || !objectsModel )
		return;
	
	const int countRow( objectsModel->rowCount() );
	for ( int row = 0; row < countRow; ++row )
	{
		objectsModel->item( row )->setCheckState( checkState );
	}
	_ui.objectsListView->update();
}

int ObjectsListWidget::CalculateCheckObjectItems( const QStandardItemModel* const objectsModel )
{
	if ( !objectsModel )
		return 0;

	int countCheckObjectItems( 0 );
	for ( int row = 0; row < objectsModel->rowCount(); ++row )	
	{
		QStandardItem* const objectItem = objectsModel->item( row );

		if ( objectItem && objectItem->checkState() == Qt::Checked )
		{
			++countCheckObjectItems;
		}
		else
		{
			continue;
		}
	}

	return countCheckObjectItems;
}

void ObjectsListWidget::SetCheckStateLayerItemByCheckStateObjectItem( QListWidgetItem* const layerItem, 
															   const int checkObjectItemsCount ) 
{
	if ( checkObjectItemsCount > 0 && layerItem->checkState() == Qt::Unchecked ) 
	{
		_ui.layersListWidget->blockSignals( true );
		layerItem->setCheckState( Qt::Checked );
		_ui.layersListWidget->blockSignals( false );
	}
	else if ( checkObjectItemsCount == 0 && layerItem->checkState() == Qt::Checked )
	{
		_ui.layersListWidget->blockSignals( true );
		layerItem->setCheckState( Qt::Unchecked );
		_ui.layersListWidget->blockSignals( false );
	}
	else
	{
		//nothing
	}
}

void ObjectsListWidget::showEvent( QShowEvent* e )
{
	_ui.layersListWidget->clear();
	qDeleteAll( _objectModelsTable );
	_objectModelsTable.clear();
	
	activateWindow();
	
	if ( !_map )
		return;

	ReadLayers();
	ShowLayers();
	
    QWidget::showEvent( e );
}

void ObjectsListWidget::SetDefaultState()
{
	_ui.applyButton->setEnabled( false );
}

void ObjectsListWidget::closeEvent( QCloseEvent* e )
{
	SetDefaultState();
        QWidget::closeEvent( e );
}

void ObjectsListWidget::ReadLayers()
{
	QSharedPointer< Map > map( _map.toStrongRef() ); 
	if ( !map )
		return;

	QStringList layerNamesList( map->GetListNamesLayers() );
	foreach ( QString layerName, layerNamesList )
	{
		QListWidgetItem* const layerItem( new QListWidgetItem( layerName ) );

		if ( map->IsVisibleLayer( layerName ) )
		{
			layerItem->setCheckState( Qt::Checked );
		}
		else 
		{
			layerItem->setCheckState( Qt::Unchecked );
		}
		ReadObjects( layerItem );
	}
}

void ObjectsListWidget::ReadObjects( QListWidgetItem* const layerItem )
{
	QSharedPointer< Map > map( _map.toStrongRef() ); 
	if ( !layerItem || !map )
		return;

	QStringList objectNamesList( map->GetListNamesObjects( layerItem->text() ) );
	QStandardItemModel* const objectsModel( new QStandardItemModel() ); 
	
	int row( 0 );
	foreach ( const QString objectName, objectNamesList )
	{
		QStandardItem* const objectItem( new QStandardItem( objectName ) );
		if ( _map.toStrongRef()->IsVisibleObject( layerItem->text(), objectName ) )
		{
			objectItem->setCheckState( Qt::Checked );
		}
		else 
		{
			objectItem->setCheckState( Qt::Unchecked );
		}

		objectItem->setCheckable( true );
		objectItem->setEditable( false ); 

		objectsModel->setItem( row, objectItem );
		_objectModelsTable.insert( layerItem, objectsModel );

		++row;
	}

	connect( objectsModel, SIGNAL( itemChanged( QStandardItem* ) ), 
		this, SLOT( ObjectItemChanged( QStandardItem* ) ) );
}

void ObjectsListWidget::ShowLayers()
{
	foreach ( QListWidgetItem* const layerItem, _objectModelsTable.keys() )
	{
		_ui.layersListWidget->addItem( layerItem );
	}

	const int firstRow( 0 );
	_ui.layersListWidget->setCurrentRow( firstRow );
	on_layersListWidget_itemClicked( _ui.layersListWidget->item( firstRow ) );
}

void ObjectsListWidget::ShowObjects( QListWidgetItem* const layerItem )
{
	QStandardItemModel* const objectsModel( _objectModelsTable.value( layerItem ) );

	if ( !objectsModel )
		return;

	_ui.objectsListView->setModel( objectsModel );
}

void ObjectsListWidget::WriteLayers()
{
	QSharedPointer< Map > map( _map.toStrongRef() ); 
	if ( !map )
		return;

	foreach ( QListWidgetItem* const layerItem, _objectModelsTable.keys() )
	{
		if ( !layerItem )
			continue;
		
		const QString layerName( layerItem->text() );
		
		if ( layerItem->checkState() == Qt::Checked )
		{
			map->EnableLayer( layerName );
			WriteObjects( layerItem );
		}
		else if ( layerItem->checkState() == Qt::Unchecked && 
				  map->IsVisibleLayer( layerName ) )
		{
			map->DisableLayer( layerName );
		}
		else
		{
			//nothing
		}
	}

	map->Update();
}

void ObjectsListWidget::WriteObjects( QListWidgetItem* const layerItem )
{
	QSharedPointer< Map > map( _map.toStrongRef() ); 
	QStandardItemModel* const objectsModel( _objectModelsTable.value( layerItem ) );

	if ( !map || !objectsModel )
		return;

	const int objectsCount( objectsModel->rowCount() );
	for ( int objectNumber = 0; objectNumber < objectsCount; ++objectNumber )
	{
		const QStandardItem* const objectItem( objectsModel->item( objectNumber ) );

		if ( !objectItem )
			continue;

		QString nameObject( objectItem->text() );
		if ( objectItem->checkState() == Qt::Checked && 
			!map->IsVisibleObject( layerItem->text(), nameObject ) )
		{
			map->EnableObject( layerItem->text(), nameObject );
		}
		else if ( objectItem->checkState() == Qt::Unchecked &&
			map->IsVisibleObject( layerItem->text(), nameObject ) )
		{
			map->DisableObject( layerItem->text(), nameObject );
		}
		else
		{
			//nothing
		}
	}
}

void ObjectsListWidget::VisibleMapHasChanged( MapSharedPointer map )
{
	_map = map;
}