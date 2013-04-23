#include <QtCore/qmath.h>

#include "AbstractTileContainer.h"

AbstractTileContainer::AbstractTileContainer( QRectF rect, QObject *parent ) :
    QObject( parent ),
    _tiles( 150 ),
	_scale( 1 )
{    
	_mapWidthInTiles = qCeil( rect.width() / SideLength );
}

AbstractTileContainer::~AbstractTileContainer()
{
	// забираем владение tile'ами у кэша, т.к. scene все удалит, наверное
	foreach(int key, _tiles.keys())
	{
		_tiles.take(key);
	}
}

void AbstractTileContainer::SetScale( qreal scale )
{
	_scale = scale;
	ClearCache();
}

void AbstractTileContainer::GetImageAsync( QRect rect )
{
    int x1Index = qFloor( rect.left() / SideLength );
    int x2Index = qCeil( rect.right() / SideLength ) + 1;

    int y1Index = qFloor( rect.top() / SideLength );
    int y2Index = qCeil( rect.bottom() / SideLength ) + 1;

    for ( int j = y1Index; j < y2Index; ++j )
    {
        for ( int i = x1Index; i < x2Index; ++i )
        {
            int x = i * SideLength;
            int y = j * SideLength;

            const int key = j* _mapWidthInTiles + i;

            if ( !_tiles.contains( key ) )
            {                
                GetTileAsync( QRect( x, y, SideLength + 1, SideLength + 1 ), i, j );
            }
            else
            {
				emit TileReady( _tiles.object( key ) );    
            }
        }
    }
}

void AbstractTileContainer::GetTileCompleted( QGraphicsPixmapItem *tile, int /*x*/, int /*y*/, int xIndex, int yIndex )
{
//	tile->setPos( x / _scale, y / _scale );
        tile->setPos( xIndex * SideLength / _scale - 1, yIndex * SideLength / _scale - 1);
	tile->setScale( 1.0 / _scale);
	
	_tiles.insert( yIndex * _mapWidthInTiles + xIndex, tile );

	emit TileReady( tile );
}

void AbstractTileContainer::ClearCache()
{
	_tiles.clear();
}
