#include "MapLayer.h"

#include <QRectF>

MapLayer::MapLayer(QGraphicsItem *parent) :
    ILayer(parent)
{
}

MapLayer::~MapLayer()
{
}

void MapLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

QRectF MapLayer::boundingRect() const
{
    return QRectF();
}

void MapLayer::Rescale(qreal scale)
{
}
