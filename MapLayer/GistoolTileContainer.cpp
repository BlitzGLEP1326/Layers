#include <QtCore/QtConcurrentRun>

#include "GistoolTileContainer.h"

GistoolTileContainer::GistoolTileContainer(QSharedPointer< const Data > mapData,
                                           QRectF mapRect, QObject *parent)
    :AbstractTileContainer(mapRect, parent),
     _mapData(mapData)
{
    connect( &_futureWatcher, SIGNAL( finished() ), this, SLOT( ReceiveImage() ) );
}

GistoolTileContainer::~GistoolTileContainer()
{
    _future.waitForFinished();
}

bool GistoolTileContainer::IsDone()
{
    return _requestsQueue.isEmpty();
}

void GistoolTileContainer::GetTileAsync(QRect tileSize, int xIndex, int yIndex)
{
    TileRequest r( tileSize, QPoint( xIndex, yIndex ) );
    _requestsQueue.append(r);

    if ( _requestsQueue.count() == 1 )
    {
        RunThread( r );
    }
}

void GistoolTileContainer::RunThread(GistoolTileContainer::TileRequest r)
{
    _future = QtConcurrent::run( this, &GistoolTileContainer::GetTile, _mapData->GetId(), r.first, r.second );
    _futureWatcher.setFuture( _future );
}

GistoolTileContainer::DataImageWithIndex GistoolTileContainer::GetTile(GisToolWrapper::DataId mapId, 
																	   QRect tileSize, QPoint tileIndex)
{
    GisToolWrapper::DataImage dataImage = GisToolWrapper::GetImage(mapId, tileSize);

    QRect rect;
    rect.setX(0);
    rect.setY(0);
    rect.setWidth(dataImage.first.width() - 1);
    rect.setHeight(dataImage.first.height() - 1);
    dataImage.first = dataImage.first.copy(rect);

    return DataImageWithIndex(dataImage, tileIndex);
}

void GistoolTileContainer::ReceiveImage()
{
    GistoolTileContainer::DataImageWithIndex dataImageWithIndex = _futureWatcher.result();

    GisToolWrapper::DataImage dataImage = dataImageWithIndex.first;
    QImage img = dataImage.first;
    QGraphicsPixmapItem* tile = new QGraphicsPixmapItem(QPixmap::fromImage(img));

    QRect tileSize = dataImage.second;
    QPoint index = dataImageWithIndex.second;

    GetTileCompleted(tile, tileSize.left(), tileSize.top(), index.x(), index.y());

    _requestsQueue.removeFirst();
    if (!_requestsQueue.isEmpty())
    {
        RunThread(_requestsQueue.first());
    }
}


