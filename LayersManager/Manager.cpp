#include "Manager.h"

#include <QMessageBox>
#include <QObject>

#include "ILayer.h"

Manager::Manager(QGraphicsScene *scene) :
    _scene(scene)
{
}

Manager::~Manager()
{
    qDeleteAll(_layers);
    _layers.clear();
}

void Manager::AddLayer(int key, ILayer *layer)
{
    _layers.insert(key, layer);
    if (_scene != NULL)
        _scene->addItem(layer);
}

void Manager::RemoveLayer(int key)
{
    _layers.remove(key);
}

ILayer *Manager::GetLayer(int key)
{
    return _layers.value(key, NULL);
}

void Manager::SetScene(QGraphicsScene *scene)
{
    if (scene != NULL)
        foreach (ILayer *layer, _layers)
            _scene->addItem(layer);

    _scene = scene;
}
