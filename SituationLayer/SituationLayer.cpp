#include "SituationLayer.h"

#include <QRectF>
#include <QPainter>

SituationLayer::SituationLayer(QGraphicsItem *parent) :
    ILayer(parent)
{
}

SituationLayer::~SituationLayer()
{
}

void SituationLayer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(QPointF(0, 0), 10, 10);
}

QRectF SituationLayer::boundingRect() const
{
    return QRectF(-10, -10, 20, 20);
}

void SituationLayer::Rescale(qreal scale)
{
    setScale(scale);
}
