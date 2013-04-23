/******** QDMACTPT.H   *********** Dishlenko S.G.  ***** 14/11/05 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR QT-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*  Компонент      : QDGetMapPoint -  компонент интерактивного      *
*                   выбора точки карты                             * 
*                                                                  *
*******************************************************************/

#ifndef QDMACTPT_H
#define QDMACTPT_H

#include "qdmact.h"
#include "mapapi.h"

class QDMapObj;


//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ QDGetMapPoint -  КОМПОНЕНТ ИНТЕРАКТИВНОГО    +
//+++                  ВЫБОРА ТОЧКИ КАРТЫ          + 
//++++++++++++++++++++++++++++++++++++++++++++++++++
class QDGetMapPoint : public QDGtkAction
 {
  Q_OBJECT

public:

    QDGetMapPoint(QWidget * parent = 0, const char * name = 0);
    ~QDGetMapPoint();
    // Рабочие функции
    //---------------------------------------------------
    virtual void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MouseMove(int x, int y, int modkeys);
    virtual void MouseUp(int x, int y, int modkeys);

private :
    void PaintDot();
    void CalcCoordsForObjAndMouse(int aMouseX, int aMouseY);
    // нарисовать/стереть линию
    void LinePaint();

public:                                           // 11/11/05

    // Для пользователя
    //---------------------------------------------------
    // подсоединить обработчик к компоненту отображения карты
    virtual void StartAction();     
    // отсоединить
    virtual void StopAction();      
    // Объект для которого выбирается точка
    QDMapObj     *GetMapObj();
    void         SetMapObj(QDMapObj *mapobj);
    
    typedef enum TSELECTIONMODE
    {
      GETEXISTPOINT    = 1,      // существующая точка объекта
      GETVIRTUALPOINT  = 2       // ближайшая точка объекта
    };
    // Тип точки(TSELECTIONMODE) // 14/11/05
    int          GetTypePoint();          
    void         SetTypePoint(int type);

signals :
    // Сигнал о выборе точки
    // x, y       - координаты точки объекта в метрах
    // numpoint   - номер точки
    // numsubobj  - номер подобъекта
    void SignalSelectPoint(double x, double y, int numpoint, int numsubobj);

    // Рабочие переменные
    //---------------------------------------------------
private :
    
    bool        FIsLine;         // нарисована ли линия
    DOUBLEPOINT FPointMouse;     // коорлинаты точки мыши в метрах где рисуем
    DOUBLEPOINT FPointObj;       // коорлинаты точки объекта где рисуем
    int         FNumPoint;       // номер точки на объекте
    int         FNumSubj;        // номер подъобъекта для которого точка

    QDMapObj    *FMapObj;        // Объект для которого выбирается точка
    long int    FColorDot;       // цвет резинки
    int         FLineWidth;      // толщина резинки
    int         FDashLenght;     // длина штриха резинки
    int         FBlankLenght;    // длина пробела резинки

    PAINTPARM   FImageParm;      // параметры отрисовки
    IMGDOT      FImageObj;
    PLACEDATA   FPlaceData;      // метрика резинки
    DOUBLEPOINT FPlacePoints[2]; // координаты метрики
    long int    FPlaceCount;     // количество метрики

    int         FTypeGetPoint;   // тип точки
};

#endif // QDMACTPT_H
