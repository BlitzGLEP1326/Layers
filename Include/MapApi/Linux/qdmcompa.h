/*******  QDMCOMPA.H ************* Dishlenko S.G.  ****** 21/11/03 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2003              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR QT-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*     ОПИСАНИЕ БАЗОВОГО КЛАССА КОМПОНЕНТ ДОСТУПА К                 *
*                     ЭЛЕКТРОННОЙ КАРТЫ                            *
*                                                                  *
*******************************************************************/

#ifndef QDMCOMPA_H
#define QDMCOMPA_H

#include <qwidget.h>
#include "qdmviewa.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ БАЗОВЫЙ КЛАСС КОМПОНЕНТ ДОСТУПА К ЭЛЕКТРОННОЙ КАРТЕ         ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class  QDMapComponent : public QWidget
{
    Q_OBJECT

public :
    QDMapComponent(QWidget *parent = 0, const char *name = 0);
    ~QDMapComponent();
    void SetMapViewAcces(QDMapViewAcces *value);
    // Обработка событий изменения состава карт на уровне MapViewWindow
    virtual void    MapAction(int typeaction) {};
    // Для служебного пользования  !!!!!!!!!
    void SetMapWindowAcces(QDMapViewAcces *value); // установка VarMapWindow      // 21/11/03
    // Получить объект типа QDMapViewWindow в котором отбражается карта (QDMapView or QDMapWindow)
    QDMapViewAcces *GetMapViewWindow();                                           // 21/11/03
    virtual void    Notification(QObject *component, int operation);

public :
    //  Для пользователя только на чтение
    QDMapViewAcces *VarMapView;
    // Для служебного пользования  !!!!!!!!!
    // Объект типа TMapWindow к которому подключен данный компонент и в который идет отображение
    QDMapViewAcces *VarMapWindow;
};

#endif  // QDMCOMPA_H
