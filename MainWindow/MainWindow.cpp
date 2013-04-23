#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "Manager.h"

#include "../SituationLayer/SituationLayer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(-100, -100, 200, 200);
    _ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());
    Manager *manager = new Manager(scene);

    manager->AddLayer(0, new SituationLayer());
}

MainWindow::~MainWindow()
{
    delete _ui;
}
