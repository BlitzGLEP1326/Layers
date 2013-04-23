/******* QDMPOINT.H  ************* Dishlenko S.G.  ****** 18/11/03 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2003              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*     ОПИСАНИЕ КЛАССА "КОМПОНЕНТ - ТОЧКА ЭЛЕКТРОННОЙ КАРТЫ"        *
*                                                                  *
*******************************************************************/

#ifndef QDMPOINT_H
#define QDMPOINT_H

#include "qdmcompa.h"
#include "qdmcmp.h"
#include "qdmpoina.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ КЛАСС "КОМПОНЕНТ - ТОЧКА ЭЛЕКТРОННОЙ КАРТЫ"                 ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class  QDMapPoint : public QDMapComponent
{
    Q_OBJECT

// Раскоментарить для ПС "Конструктор"                        // 18/11/03
//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03

    // Система координат на запись
    Q_PROPERTY(int PlaceIn READ GetPlaceIn WRITE SetPlaceIn)
    // Система координат на чтение
    Q_PROPERTY(int PlaceOut READ GetPlaceOut WRITE SetPlaceOut)

public :
    QDMapPoint(QWidget * parent = 0, const char * name = 0);
    ~QDMapPoint();

    int        GetPlaceIn() const;
    int        GetPlaceOut() const;

    QDMapView  *GetMapView() const;
    virtual void SetMapView(QDMapView *value);

    // Записать координату в системе PlaceIn
    bool SetPoint(double x, double y);
    // Считать  координату в системе PlaceOut
    bool GetPoint(double *x, double *y);

// Для служебного пользования !!!!!
    // Обработка событий изменения состава карт на уровне MapViewWindow
    void    MapAction(int typeaction);

public slots:
//!! конец блока для  служебного пользования !!!!!
    void SetPlaceIn(int value);
    void SetPlaceOut(int value);

public :
    // Для служебного пользования !!!!!
    QDMapPointAcces *VarMapPoint;
    QString         VarMapViewName;
    QWidget         *ParentHandle;
};

#endif // QDMPOINT_H
