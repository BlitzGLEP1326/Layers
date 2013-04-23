#pragma once

#include <QtCore/QFutureWatcher>
#include <QtCore/QFuture>
#include <QPoint>
#include <QPair>
#include <QList>

#include "AbstractTileContainer.h"
#include "Data.h"
#include "GisToolWrapper.h"

class GistoolTileContainer : public AbstractTileContainer
{
    Q_OBJECT

public:
    GistoolTileContainer(QSharedPointer< const Data > mapData, QRectF mapRect, QObject *parent = 0);
    ~GistoolTileContainer();

    bool IsDone();

private:

    typedef QPair<GisToolWrapper::DataImage, QPoint> DataImageWithIndex;

    void GetTileAsync(QRect tileSize, int xIndex, int yIndex);

    typedef QPair<QRect, QPoint> TileRequest;
    void RunThread(TileRequest r);

	DataImageWithIndex GetTile(GisToolWrapper::DataId mapId, QRect tileSize, QPoint tileIndex);

private slots:

    void ReceiveImage();

private:

    QSharedPointer< const Data > _mapData;
    QFuture< DataImageWithIndex > _future;
    QFutureWatcher< DataImageWithIndex > _futureWatcher;

	// т.к. gistool плохо работает в многопоточности, 
	// используем последовательную очередь запросов к gistool за tile'ами
    QList<TileRequest> _requestsQueue;
};
