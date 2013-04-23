#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QGraphicsLineItem>
#include <QtCore/QEvent>

#include "MapImage.h"
#include "Line.h"

class VisualRoot : public QGraphicsItem
{
public:

	QRectF boundingRect() const
	{		
		return QRectF();
	}

	void paint(QPainter* , const QStyleOptionGraphicsItem* , QWidget* )
    {
	}
};

Line::Line( MapSharedPointer map, QObject* parent)
	: QObject( parent )	
	, _map(map)
	, _lastPoint(QPointF(0, 0))
    , _flagIcon(":/icons/map_pin_24.png")
{
	_group = new VisualRoot;
	_map->DrawItem(_group);

    _selectedRect = new QGraphicsEllipseItem(-10, -10, 20, 20);
    _selectedRect->setPen(Qt::NoPen);
    _selectedRect->setBrush(Qt::red);
    _selectedRect->setOpacity(0.5);
    _map->DrawItem(_selectedRect);

	connect(_map.data(), SIGNAL(MousePositionChanged( QPointF )), this, SLOT(MousePositionChanged( QPointF )));
    connect(_map.data(), SIGNAL(scaleHasChanged(qreal)), this, SLOT(ChangeScale(qreal)));

    ChangeScale(_map->GetBaseScale() / _map->GetScale());

//    _fuckLine = new QGraphicsLineItem(0, 0, 0, 0);
//    _map->DrawItem(_fuckLine);
    SetVisible(false);
//    SetVisibleFuckLine(false);
}

Line::~Line() 
{
	_map->SetCursor( QCursor( Qt::OpenHandCursor ) );

	DeleteAllItems();
	delete _group;
//    delete _fuckLine;
    delete _selectedRect;
}

void Line::SetPoints( QList< QPointF > points )
{
	DeleteAllItems();

    typedef QList< QPointF >::const_iterator Point;
    for ( Point point = points.constBegin(); point != points.constEnd(); ++point ) {

		if ( point != points.constBegin() )
		{
            new QGraphicsLineItem( QLineF( *( point - 1 ), *point ), _group );
		}

        QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem( _flagIcon, _group );
        pixmapItem->setOffset( - QPointF( _flagIcon.width() / 2, _flagIcon.height() ) );
		pixmapItem->setFlag( QGraphicsItem::ItemIgnoresTransformations );
        pixmapItem->setPos( *point );
	}

//	_lastPoint = points.count() > 0 ? points.last() : QPointF();
}

void Line::DeleteAllItems()
{
	foreach ( QGraphicsItem* item, _group->childItems() ) {
		delete item;
	}
}

void Line::SetVisible( bool isVisible )
{
	_group->setVisible(isVisible);
//	_fuckLine->setVisible(isVisible);
	if (isVisible)
    {
        _map->SetCursor( QCursor( Qt::CrossCursor ) );
    }
	else
        _map->SetCursor( QCursor( Qt::OpenHandCursor ) );
}

//void Line::SetVisibleFuckLine(bool isVisible)
//{
//    _fuckLine->setVisible(isVisible);
//    qreal opacity = isVisible ? 0.5 : 0;
//    _selectedRect->setOpacity(opacity);
//}

void Line::MarkPoint(QPointF startPoint)
{
    qreal opacity = (!startPoint.isNull()) ? 0.5 : 0;
    _lastPoint = startPoint;
    _selectedRect->setOpacity(opacity);
//    MousePositionChanged(_lastPoint);//уберет линию
    _selectedRect->setPos(_lastPoint);
}

void Line::Activate(bool isActivated)
{
    if (isActivated)
    {
        _map->SetCursor( QCursor( Qt::CrossCursor ) );
    }
    else
        _map->SetCursor( QCursor( Qt::OpenHandCursor ) );
}

void Line::ChangeScale(qreal scale)
{
    _selectedRect->setScale(1 / scale);
}

void Line::MousePositionChanged( QPointF /*point*/ )
{
    if (!_lastPoint.isNull())
    {
//        _fuckLine->setLine(_lastPoint.x(), _lastPoint.y(), point.x(), point.y());
    }
}
