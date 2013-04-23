/******* QDMFIND.H  ************* Dishlenko S.G.  ****** 18/11/03 **
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
*  ОПИСАНИЕ КЛАССА "КОМПОНЕНТ ПОИСКА ОБ'ЕКТА ЭЛЕКТРОННОЙ КАРТА"    *
*                                                                  *
*******************************************************************/

#ifndef QDMFIND_H
#define QDMFIND_H

#include "qdmcmp.h"         // 24/07/03
#include "qdmobj.h"         // 24/07/03

class QDMapPointAcces;
class QDMapSelect;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ КЛАСС "КОМПОНЕНТ ПОИСКА ОБ'ЕКТА ЭЛЕКТРОННОЙ КАРТА"          ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapFind : public QDMapComponent
{
    Q_OBJECT

// Раскоментарить для ПС "Конструктор"                        // 18/11/03
//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03
//    Q_PROPERTY(QDMapObj  MapObj  READ GetMapObj  WRITE SetMapObj  FROMSTRL def TOSTRL def ORDER 2)  // 24/07/03

public  :
    QDMapFind(QWidget * parent = 0, const char * name = 0);
    ~QDMapFind();

    bool           GetActive() const;
    QDMapPointAcces *GetPoint();
    double         GetRadius();
    int            GetPlaceIn();
    int            GetPlaceOut();
    void           GetCoordPoint(double *x, double *y);
    void           SetPlaceIn(int value);
    void           SetPlaceOut(int value);
    void           SetCoordPoint(double x, double y);
    // Указатель на объект карты
    void           SetMapObj(QDMapObj *value);
    QDMapObj       *GetMapObj()  const;                     // 24/07/03
    virtual void   SetMapView(QDMapView *value);
    QDMapView      *GetMapView() const;                     // 24/07/03
    // Установить/запросить условия поиска                  // 20/01/03
    void           SetMapSelect(QDMapSelect *value);
    QDMapSelect    *GetMapSelect();
    HSELECT        GetMapSelectHandle();
    // Включить/выключить режим поиска в заданной точке
    void           SetFindPoint(bool value);
    bool           GetFindPoint();
    void           SetRadius(double value);
    int            SeekInPoint(HOBJ obj, int flag);
    int            SeekInMap(HOBJ obj, int flag);
    bool           First();
    bool           Prior();
    bool           Next();
    bool           Last();
    // Установить объект в центр окна
    void           Center();
    // Определить - находится ли система поиска на первом элементе
    bool           GetBOF();
    // Определить - вышла ли система за последний элемент
    bool           GetEOF();

    // Для внутреннего использования
    void           MapAction(int acttype);
    virtual void   Notification(QObject *component, int operation);
    // -----------------------------
public slots:
    void           SetActive(bool value);

public :
    // Пользователю на чтение
    QDMapSelect     *VarMapSelect;
    // Для внутреннего использования
    QDMapObj        *VarMapObj;
    bool            VarActive;
    bool            VarBOF;
    bool            VarEOF;
    bool            VarFindPoint;
    QDMapPointAcces *VarMapPoint;
    MAPDFRAME       VarFrame;
    double          VarRadius;
};


#endif //QDMFIND_H
