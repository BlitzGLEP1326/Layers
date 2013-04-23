#include <QtGui/QStyleOptionGraphicsItem>
#include <QtGui/QPainter>
#include <QtCore/QtConcurrentRun>
#include <QtGui/QGraphicsSceneMouseEvent>
#include <QtGui/QGraphicsPixmapItem>

#include "GistoolTileContainer.h"

#include "MapImage.h"


MapImage::MapImage( QSharedPointer< const Data > data, QGraphicsItem* parent /*= 0 */ )
    : QGraphicsItemGroup( parent )
    , _data( data )
    , _imageProperty( data )
    , _wasManualUpdate( false )
    , _tileContainer( new GistoolTileContainer( data, GisToolWrapper::GetImageSize( _data->GetId() ), this ) )
{
    setFlag( QGraphicsItem::ItemUsesExtendedStyleOption );
    setFlag( QGraphicsItem::ItemClipsToShape );

    setZValue( -10 ); //to do: hack transparent zone

    setAcceptHoverEvents( true );

    SetBoudingRect();

    connect( _tileContainer, SIGNAL( TileReady( QGraphicsPixmapItem* ) ), this, SLOT( ReceiveImage( QGraphicsPixmapItem* ) ) );
}

MapImage::~MapImage()
{
    //_future.waitForFinished();
}

QRectF MapImage::boundingRect() const
{
    scene()->setSceneRect( _boudingRect );
    return _boudingRect;
}

void MapImage::paint( QPainter* painter, const QStyleOptionGraphicsItem* , QWidget* )
{
    const qreal scalingCoefficient = QStyleOptionGraphicsItem::levelOfDetailFromTransform(painter->worldTransform());
    QRect viewRect = scene()->views()[ 0 ]->mapToScene( scene()->views()[ 0 ]->rect() ).boundingRect().toRect();
    QRect currentRect(viewRect.topLeft() * scalingCoefficient, viewRect.bottomRight() * scalingCoefficient);

    // request image asynchronously
    bool positionChanged = currentRect != _oldRect;
    if ( ( positionChanged || _wasManualUpdate ) &&  _tileContainer->IsDone() )
    {
        _tileContainer->GetImageAsync( currentRect );
        _oldRect = currentRect;
        _wasManualUpdate = false;
    }
}

void MapImage::NoDrawing(bool flNoDraw)
{
    _flNoDraw=flNoDraw;
}

void MapImage::Wait()
{
    //    if(!_future.isFinished())
    //        _future.waitForFinished();
}

void MapImage::ReceiveImage(QGraphicsPixmapItem* tile)
{
    /*tile->setPos( tile->pos().x() / _scale, tile->pos().y() / _scale );
 tile->setScale( 1.0 / _scale);*/

    tile->setOpacity( _imageProperty.GetTransparent() );
    tile->setAcceptedMouseButtons(Qt::NoButton);
    addToGroup( tile );

    //scene()->addItem(tile);
}

void MapImage::ScaleChanged( qreal scaleCoef )
{
    _scale = scaleCoef;

    _tileContainer->SetScale( scaleCoef );
    Update();
}

void MapImage::hoverMoveEvent( QGraphicsSceneHoverEvent* event )
{
    const QPointF mousePosition( event->pos().x(), event->pos().y() );
    emit MousePositionChanged( mousePosition );

    QGraphicsItem::hoverMoveEvent( event );
}

void MapImage::mousePressEvent( QGraphicsSceneMouseEvent * event )
{
    const QPointF mousePosition( event->pos().x(), event->pos().y() );
    emit MouseClick( event->button(), mousePosition );

    QGraphicsItem::mousePressEvent( event );
}

void MapImage::Update()
{
    _tileContainer->ClearCache();
    _wasManualUpdate = true;
    update();
}

void MapImage::SetBoudingRect()
{
    _boudingRect = GisToolWrapper::GetImageSize(  _data->GetId() );
}

