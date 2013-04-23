#pragma once

#include <QCache>
#include <QGraphicsPixmapItem>

class AbstractTileContainer : public QObject
{
    Q_OBJECT

public:

    explicit AbstractTileContainer( QRectF rect, QObject *parent = 0 );

    virtual ~AbstractTileContainer();

    void GetImageAsync(QRect rect);

    virtual bool IsDone() = 0;

	void SetScale( qreal scale );

	void ClearCache();

signals:

    void TileReady(QGraphicsPixmapItem*);

protected:

    virtual void GetTileAsync(QRect tileSize, int xIndex, int yIndex) = 0;

    void GetTileCompleted(QGraphicsPixmapItem* tile, int x, int y,
                          int xIndex, int yIndex);
private:

    static const int SideLength = 300;
	
    QCache<int, QGraphicsPixmapItem> _tiles;

    int _mapWidthInTiles;
	qreal _scale;
};
