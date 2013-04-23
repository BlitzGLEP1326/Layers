#pragma once

#include "ILayer.h"
#include "dll.h"

class MAP_LAYER_EXPORT MapLayer : public ILayer
{
public:
    MapLayer(QGraphicsItem *parent = NULL);
    ~MapLayer();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    void Rescale(qreal scale);
};
