#include <QScrollBar>

#include "ui_MapWindow.h"
#include "MapMenuWidget.h"
#include "MapInfoWidget.h"
#include "MapWindow.h"

MapWindow::MapWindow( QWidget *parent )
    : QWidget( parent )
	, _ui( new Ui::MapWindowClass )
	, _mapMenu( 0 )
	, _mapInfo( 0 )
	, _distanceWidget( 0 )
{
	_ui->setupUi( this );

	_ui->graphicsView->installEventFilter( this );
	//_ui->graphicsView->setTransformationAnchor( QGraphicsView::NoAnchor );
	
	_mapInfo = new MapInfoWidget( this );
	_mapInfo->close();
	
	Atlas* const atlas( new Atlas(this) );
	
	Utils::Dispatcher::Instance()->Register(atlas, "Atlas");
        Utils::Dispatcher::Instance()->Register(this, "MapWindow");
	
	connect( atlas, SIGNAL( VisibleMapHasChanged( MapSharedPointer ) ),
		_mapInfo, SLOT( VisibleMapHasChanged( MapSharedPointer ) ) );
	
	connect( atlas, SIGNAL( CurrentMapHasChanged( MapSharedPointer, Map::DataType ) ),
		_mapInfo, SLOT( CurrentMapHasChanged( MapSharedPointer, Map::DataType ) ) );

	connect( atlas, SIGNAL( VisibleMapHasChanged( MapSharedPointer ) ),
		this, SLOT( VisibleMapHasChanged( MapSharedPointer ) ) );

	_mapMenu = new MapMenuWidget( atlas, _ui->graphicsView );
	_mapMenu->move( 10, 10 );

	QAction *distanceAction = new QAction(this);
	distanceAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_L));
	connect(distanceAction, SIGNAL(triggered()), this, SLOT(ShowDistanceWidget()));
	this->addAction(distanceAction);

	new  ZonePresenter( this );
	new  TracePresenter( this );
}

MapWindow::~MapWindow()
{
    Utils::Dispatcher::Instance()->Unregister("Atlas");
    Utils::Dispatcher::Instance()->Unregister("MapWindow");
	if (_map) {
		QRectF rect = _ui->graphicsView->rect();
		QPointF pos = _ui->graphicsView->mapToScene(rect.center().toPoint());
		_map->SetPos(pos);
    }
}

void MapWindow::VisibleMapHasChanged( MapSharedPointer map )
{
	if (_map == map)
		return;

	_map = map;
	
	if ( map )
	{
		setWindowTitle( map->GetName() );
		map->Show( _ui->graphicsView );
	}
	else
	{
		setWindowTitle( "Окно карты" );
	}
}

int uu = 0;
bool MapWindow::eventFilter( QObject* object, QEvent* event )
{
	if ( ( event->type() == QEvent::Resize ) && object->inherits( "QGraphicsView" ) )
    {
        _mapInfo->move( _ui->graphicsView->rect().bottomLeft() - QPoint( -20, 45 ) );
        if (_distanceWidget != NULL)
            _distanceWidget->move( _ui->graphicsView->rect().bottomLeft() - QPoint( -20, 80 ) );
        // при старте программмы, четвертое изменение размера является окончательным :)))
        if (uu < 4 && !_map.isNull()) {
            _map->SetPos(_map->GetPos());
            uu++;
        }
        emit WidgetResize( _ui->graphicsView->rect() );
    }

    return false;
}

void MapWindow::ShowDistanceWidget()
{
	if (_distanceWidget == NULL)
	{		
		_distanceWidget = new DistanceWidget(this);
		_distanceWidget->move( _ui->graphicsView->rect().bottomLeft() - QPoint( -20, 80 ) );
	}
	else
	{
		delete _distanceWidget;
		_distanceWidget = NULL;
	}
}
