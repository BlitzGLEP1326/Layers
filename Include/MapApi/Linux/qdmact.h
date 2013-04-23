/******** QDMACT.H ************* Dishlenko S.G.  ***** 11/11/05 ****
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
*    QDGtkAction -  базовый класс обработки событий от компонента  *
*                         отображения карты                        *
*                                                                  *
*******************************************************************/

#ifndef QDMACT_H
#define QDMACT_H

#include "qdmcompa.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ QDGtkAction - КЛАСС ОБРАБОТКИ СОБЫТИЙ ОТ     +
//+++ КОМПОНЕНТА ОТОБРАЖЕНИЯ КАРТЫ                 +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapView;
class QDMapWindow;

 class QDGtkAction : public QDMapComponent
 {
  Q_OBJECT

  public:

    QDGtkAction(QWidget * parent = 0, const char * name = 0);
    ~QDGtkAction();

    // Внутренее
    //---------------------------------------------
    virtual void MapAfterPaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    // Запрос - можно ли отключить обработчик
    // вызывется по инициативе компонента QDMapViewWindow
    // после выдачи StopAction
    bool DoStopActionQuery();
    // обработчик будет отключен
    // вызывется по инициативе компонента QDMapViewWindow
    // после выдачи StopAction
    virtual void DoStopAction();
    virtual void DblClick();
    virtual void KeyUp(int key, int count, int state);
    virtual void KeyDown(int key, int count, int state);
    virtual void MouseDown(int x, int y, int modkeys);
    virtual void MouseMove(int x, int y, int modkeys);
    virtual void MouseUp(int x, int y, int modkeys);

    // Для пользователя
    //---------------------------------------------
    // Активен ли в данный момент обработчик   // 11/11/05
    // false - не активен;
    // true  - активен;
    bool GetActive();      
    virtual void   SetMapView(QDMapView *value);
    QDMapView      *GetMapView() const;
    virtual void   SetMapWindow(QDMapWindow *value);
    QDMapWindow    *GetMapWindow() const;
    virtual void   StartAction();     // подсоеденить обработчик к компоненту отображения карты
    virtual void   StopAction();      // отсоеденить

 public :
    bool VarActive;

};

#endif
