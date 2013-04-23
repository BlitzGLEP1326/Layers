#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QHash>

#include "dll.h"

class ILayer;

class LAYERS_MANAGER_EXPORT Manager : public QObject
{
    Q_OBJECT

public:
    explicit Manager(QGraphicsScene *scene = NULL);
    ~Manager();

    void AddLayer(int key, ILayer *layer);
    void RemoveLayer(int key);
    ILayer *GetLayer(int key);

    void SetScene(QGraphicsScene *scene);

private:
    QHash<int,ILayer *> _layers;
    QGraphicsScene *_scene;
};
