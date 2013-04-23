#include <QPainter>
#include <QPainterPath>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QWidgetAction>

#include "MapsListWidget.h"
#include "PropertyWidget.h"
#include "ObjectsListWidget.h"
#include "ScaleWidget.h"
#include "MapMenuWidget.h"
#include "Utils/Dispatcher.h"

MapMenuWidget::MapMenuWidget( Atlas* const atlas, QWidget* parent )
    : QWidget( parent )
	, _mapMenuBar( 0 )
	, _mapsListMenu( 0 )
	, _objectsList( 0 )
    , _propertys( 0 )
	, _background( 154, 166, 153, 200 )
{
    _ui.setupUi( this );
	
	setWindowFlags( Qt::FramelessWindowHint );
    setAttribute( Qt::WA_TranslucentBackground );

 	connect( atlas, SIGNAL( VisibleMapHasChanged( MapSharedPointer ) ), 
 		_ui.scaleWidget, SLOT( VisibleMapHasChanged( MapSharedPointer ) ) );
	
	_mapMenuBar = new QMenuBar( this );
	_ui.gridLayout->addWidget( _mapMenuBar, 0, 1 );
	
	MapsListWidget* const mapsListWidget( new MapsListWidget( atlas, this ) );
	connect( mapsListWidget, SIGNAL( ShowMapsList() ), this, SLOT( ShowMapsList() ) );

	_objectsList = new ObjectsListWidget( this );
	_propertys = new PropertyWidget( this );

	_mapsListMenu = CreateMenu( mapsListWidget, "Список карт" );
	CreateMenu( _objectsList, "Список объектов" );
    CreateMenu( _propertys, "Свойства" );

    // TODO шило
    _distanceButton = new QPushButton("Линейка");
    _distanceButton->setCheckable(true);
    _distanceButton->setMinimumWidth(75);
    _distanceButton->setMaximumHeight(21);
    _ui.gridLayout->addWidget(_distanceButton, 0, 2);
    connect(_distanceButton, SIGNAL(clicked()), this, SIGNAL(ShowDistanceWidget()));
    Utils::Dispatcher::Instance()->Connect(this, SIGNAL(ShowDistanceWidget()),
        "MapWindow", SLOT(ShowDistanceWidget()));

    Utils::Dispatcher::Instance()->Register(this, "MapMenu");

 	connect( atlas, SIGNAL( VisibleMapHasChanged( MapSharedPointer ) ),
 		this, SLOT( VisibleMapHasChanged( MapSharedPointer ) ) );

	connect( atlas, SIGNAL( VisibleMapHasChanged( MapSharedPointer ) ),
		_objectsList, SLOT( VisibleMapHasChanged( MapSharedPointer ) ) );

	connect( atlas, SIGNAL( VisibleMapHasChanged( MapSharedPointer ) ),
		_propertys, SLOT( VisibleMapHasChanged( MapSharedPointer ) ) );

	CreateWidgetGeometry();
}

MapMenuWidget::~MapMenuWidget()
{
    Utils::Dispatcher::Instance()->Unregister("MapMenu");
}

void MapMenuWidget::SetEnableDistance(bool isEnabled)
{    
    _distanceButton->setEnabled(isEnabled);
    _distanceButton->setChecked(false);
    if(!isEnabled)
        emit ShowDistanceWidget();
}

void MapMenuWidget::paintEvent( QPaintEvent* paintEvent )
{
    QPainterPath path;
	path.setFillRule( Qt::WindingFill );
	path.addRegion( mask() );

	QPainter painter( this );
	painter.fillPath( path, _background );

    QWidget::paintEvent( paintEvent );
}

void MapMenuWidget::CreateWidgetGeometry()
{
	QPolygon poligon;
	
	const int indent( _ui.gridLayout->margin() );

	const int bottom( indent + _ui.hideButton->sizeHint().height() + 
		_ui.verticalSpacer->sizeHint().height() + _ui.scaleWidget->height() + indent );
	const int right( indent + _ui.hideButton->width() + 
        _mapMenuBar->sizeHint().width() + _distanceButton->width() + indent );

	const int width( indent + _ui.scaleWidget->width() + indent );
    const int height( indent + _mapMenuBar->sizeHint().height() + indent );

	poligon << QPoint( 0, 0 )
		<< QPoint( 0, bottom )
		<< QPoint( width, bottom )
		<< QPoint( width, height )
		<< QPoint( right, height )
		<< QPoint( right, 0 );

	QRegion widgetRegion( poligon );
	setMask( widgetRegion );
}

void MapMenuWidget::ShowMapsList()
{
	_mapsListMenu->exec();
}

void MapMenuWidget::VisibleMapHasChanged( MapSharedPointer map )
{
    _objectsList->setDisabled( map.isNull() );
    _propertys->setDisabled( map.isNull() );
    _distanceButton->setDisabled( map.isNull() );
    _ui.scaleWidget->setDisabled( map.isNull() );
}

QMenu* MapMenuWidget::CreateMenu( QWidget* const widget, const QString& menuName ) const
{
	QMenu* menu( 0 );

	if ( !_mapMenuBar || !widget )
		return menu;
	
	menu = _mapMenuBar->addMenu( menuName );
	
	QWidgetAction*  widgetAction = new QWidgetAction( _mapMenuBar );
	widget->adjustSize();
	widgetAction->setDefaultWidget( widget );
	menu->addAction( widgetAction );

	return menu;
}

void MapMenuWidget::on_hideButton_clicked( bool checked )
{
	if ( checked )
	{
		_ui.scaleWidget->hide();
		_mapMenuBar->hide();
        _distanceButton->hide();
		_ui.hideButton->setText( ">>" );
        _ui.hideButton->setToolTip( "Показать меню карты" );
		_background.setAlpha( 0 );
	}
	else
	{
		_ui.scaleWidget->show();
		_mapMenuBar->show();
        _distanceButton->show();
		_ui.hideButton->setText( "<<" );
        _ui.hideButton->setToolTip( "Скрыть меню карты" );
		_background.setAlpha( 200 );
	}
}
