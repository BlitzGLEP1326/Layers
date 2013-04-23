#pragma once

#include "ILayer.h"
#include "dll.h"

class SITUATION_LAYER_EXPORT SituationLayer : public ILayer
{
public:
    SituationLayer(QGraphicsItem *parent = NULL);
    ~SituationLayer();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    void Rescale(qreal scale);
};
