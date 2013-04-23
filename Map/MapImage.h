#ifndef MAPPLANE_H
#define MAPPLANE_H

#include <QtGui/QGraphicsItemGroup>
#include <QtCore/QFutureWatcher>
#include <QtCore/QFuture>
#include <QtGui/QLabel>

#include "Map.h"
#include "Data.h"
#include "ImageProperty.h"

#include "AbstractTileContainer.h"

class MapImage : public QObject, public QGraphicsItemGroup /*QGraphicsObject*/
{

	Q_OBJECT
    //Q_INTERFACES( QGraphicsItem )

public:
    explicit MapImage( QSharedPointer< const Data > data, QGraphicsItem* parent = 0 );
	~MapImage();

    QRectF boundingRect() const;
	void paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0 );

	void Update();
public:
    void NoDrawing(bool flNoDraw); // ����� �������. ����� �� ������������. ���������!
    void Wait();

signals:
	void MousePositionChanged( QPointF pos );
	void MouseClick( Qt::MouseButton, QPointF );

private slots:
	void ScaleChanged( qreal );
    void ReceiveImage( QGraphicsPixmapItem* tile );

private:
	friend class Map;
	
	void hoverMoveEvent( QGraphicsSceneHoverEvent* event );  
	void mousePressEvent( QGraphicsSceneMouseEvent * event );
	void SetBoudingRect();

	QSharedPointer< const Data > _data;
	ImageProperty _imageProperty;
    
	QRectF _boudingRect;
	bool _wasManualUpdate;
    bool _flNoDraw;

    AbstractTileContainer* _tileContainer;
    QRect _oldRect;
	qreal _scale;
};

#endif // MAPPLANE_H