#pragma once

#include <QGraphicsObject>

#include "dll.h"

class LAYERS_MANAGER_EXPORT ILayer : public QGraphicsObject
{
public:
    ILayer(QGraphicsItem *parent = NULL) : QGraphicsObject(parent) {}
    virtual ~ILayer() {}

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    virtual QRectF boundingRect()const = 0;

    virtual void Rescale(qreal scale) = 0;
};
