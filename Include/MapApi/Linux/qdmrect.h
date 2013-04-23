/******** QDMRECT.H ************* Dishlenko S.G.  ***** 14/11/05 ***
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
*  Компонент      : QDMapSelectRect - выбор участка открытой карты *
*                                                                  *
*******************************************************************/

#ifndef QDMRECT_H
#define QDMRECT_H

#include "qdmact.h"
#include "mapapi.h"             // 28/11/03

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ QDMapSelectRect - КЛАСС ВЫБОРА УЧАСТКА КАРТЫ +
//++++++++++++++++++++++++++++++++++++++++++++++++++

 class QDMapSelectRect : public QDGtkAction
 {
  Q_OBJECT

  public:

    // Для пользователя
    //---------------------------------
    QDMapSelectRect(QWidget * parent = 0, const char * name = 0);
    ~QDMapSelectRect();

    // Для пользователя
    virtual void StartAction();     // подсоединить обработчик к компоненту отображения карты
    virtual void StopAction();      // отсоединить
    // Запрос/установка системы координат     // 01/11/05
    void SetPlaceRect(int pp);
    int  GetPlaceRect();

    // Служебные
    //---------------------------------
    virtual void MapAfterPaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MouseDown(int x, int y, int modkeys);
    virtual void MouseMove(int x, int y, int modkeys);
    virtual void MouseUp(int x, int y, int modkeys);

    //  Построить контур фрагмента по угловым точкам
    void BuildFrame();
    //  Нарисовать на карте рамку фрагмента
    void PaintFrame();
    DOUBLEPOINT GetMapPoint(int x, int y);
    int         GetSelRect(MAPDFRAME *dframe, int pp);           // 26/10/05

signals :
    // Для пользователя
    //---------------------------------
    // Сигнал об окончании построения рамки
    // параметры - координаты верхнего левого и
    // правого нижнего угла рамки
    void SignalAfterBuildRect(double left, double top,            // 1/11/05
                              double right, double bottom);

public :
  // Служебные
  //---------------------------------
  PAINTPARM Form;   // Вид контура фрагмента на экране
                    // (пунктирная линия 5/2 инверсная)
  PLACEDATA Frame;  // Описание фрагмента карты

  IMGDOT Image;     // Описание пунктирной линии (контур фрагмента)

  struct Border
  {
    DOUBLEPOINT UpLeft;     // Координаты первой точки (Map)
    DOUBLEPOINT UpRight;    // Координаты второй точки
    DOUBLEPOINT DownRight;  // Координаты третьей точки
    DOUBLEPOINT DownLeft;   // Координаты четвертой точки
    DOUBLEPOINT UpLeftLast; // Координаты последней точки (Map)
  }
    Border;

  long PointCount;         // Число точек, описывающих фрагмент
  int  SelectedPoints;     // Выбрано точек

  DOUBLEPOINT First;      // Координаты первого угла (Map)
  DOUBLEPOINT Second;     // Координаты второго угла (Map)

  int FlagClear;          // Признак "контур стерт"
  int VarPlace;           // Текущая система координат  // 08/11/05
};

#endif
