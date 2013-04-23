#include <QPainter>
#include <QPainterPath>

#include "MapInfoWidget.h"

MapInfoWidget::MapInfoWidget( QWidget* parent )
	: QWidget( parent )
{
	_ui.setupUi( this );

	setWindowFlags( Qt::FramelessWindowHint );
}

MapInfoWidget::~MapInfoWidget()
{
}

void MapInfoWidget::paintEvent( QPaintEvent* paintEvent )
{
 	QPainterPath path;
	path.setFillRule( Qt::WindingFill );
	path.addRect( rect() );

	QPainter painter( this );
    painter.fillPath( path, QColor( 154, 166, 153, 230 ) );

	QWidget::paintEvent( paintEvent );
}


void MapInfoWidget::MousePositionChanged( QPointF logicPoint )
{
	if ( !_visibleMap )
		return;
	
    QPointF planePoint( _visibleMap->Convert( logicPoint, Map::LogicToPlane ) );
    QPointF gkPoint( _visibleMap->Convert( planePoint, Map::PlaneToGK ) );

    const QString x( QString::number( gkPoint.x(), 'f', 1 ) );
    const QString y( QString::number( gkPoint.y(), 'f', 1 ) );
	_ui.xLabel->setText( QString( "X = " ) + x );
 	_ui.yLabel->setText( QString( "Y = " ) + y );
 
 	if ( _currentMatrixMap && -111111.0 != _currentMatrixMap->GetHeight( planePoint ) )
 	{
		QString height( QString::number( _currentMatrixMap->GetHeight( planePoint ), 'f', 1 ) );
 		_ui.hLabel->setText( QString( "H = " ) + height );
 	}
 	else
 	{
 		_ui.hLabel->setText( QString( "H = Нет данных" ) );
	}
}

void MapInfoWidget::ScaleHasChanged( const qreal scale )
{
	const QString scaleString( QString::number( scale, 'f', 0 ) );
	_ui.scaleLabel->setText( QString( "Масштаб = 1 : " ) + scaleString );
}

void MapInfoWidget::showEvent( QShowEvent* e )
{
	if ( !_visibleMap )
		return;
	
	_ui.scaleLabel->setText( QString( "Масштаб = 1 : " ) + 
		QString::number( _visibleMap->GetScale(), 'f', 0 ) );
	
	QWidget::showEvent( e );
}

void MapInfoWidget::closeEvent( QCloseEvent* e )
{
	_ui.xLabel->setText( QString( "X = 0" ) );
	_ui.yLabel->setText( QString( "Y = 0" ) );
	_ui.hLabel->setText( QString( "H = Нет данных" ) );
	_ui.scaleLabel->setText( QString( "Scale - 1 : 0" ) );

	QWidget::closeEvent( e );
}

void MapInfoWidget::VisibleMapHasChanged( MapSharedPointer map )
{
	_visibleMap =  map;

	if ( map )
	{
		connect( map.data(), SIGNAL( MousePositionChanged( QPointF ) ), 
			this, SLOT( MousePositionChanged( QPointF ) ) );

		connect( map.data(), SIGNAL( ScaleHasChanged( qreal ) ), 
			this, SLOT( ScaleHasChanged( qreal ) ) );

		show();
	}
	else
	{
		hide();
	}
}

void MapInfoWidget::CurrentMapHasChanged( MapSharedPointer map, Map::DataType type )
{
	if ( Map::Matrix != type )
		return;

	_currentMatrixMap = map;
}
