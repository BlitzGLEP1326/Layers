/******* QDMWINA.H ************** Dishlenko S.G.  ****** 01/04/07 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2007              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR QT-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*        ОПИСАНИЕ КЛАССА ДОСТУПА К ФУНКЦИЯМ ОТОБРАЖЕНИЯ            *
*                     ЭЛЕКТРОННОЙ КАРТЫ                            *
*                                                                  *
*******************************************************************/

#ifndef QDMWINA_H
#define QDMWINA_H

#include <qlist.h>
#include "qdmviewa.h"
#include "qdmcompa.h"

class QDMapSelect;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++ КЛАСС "ИНТЕРФЕЙС ОТОБРАЖЕНИЯ ЭЛЕКТРОННОЙ КАРТОЙ" +++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class  QDMapViewWindow : public QDMapViewAcces
{
   Q_OBJECT

    // Разрешить/запретить отображать карты
    Q_PROPERTY(bool MapVisible READ GetMapVisible WRITE SetMapVisible)

public :
   QDMapViewWindow(QWidget *parent = 0, const char *name = 0, WFlags f = 0);  // 11/12/07);
   ~QDMapViewWindow();

    bool         GetMapVisible() const;
    // Запросить/установить верхнюю левую позицию начала отображения
    void         GetMapLeftTop(int *left, int *top);
    void         SetMapLeftTop(int left, int top);
    // Внесение компонента mapcomponent в список компонент
    void AppendMapObject(QDMapComponent *mapcomponent);
    // Удаление компонента mapcomponent из списка компонент
    void DeleteMapObject(QDMapComponent *mapcomponent);
    // Запросить/установить текущий масштаб отображения
    virtual int     GetViewScale();
    virtual int     SetViewScale(int value);
    // Функция изменения масштаба относительно текущей точки
    //   Параметры: value - реальный масштаб, который желают получить
    int             SetViewScaleInPoint(int value);                        // 25/11/03

    // Определить габариты всего набора карт в пикселах
    virtual RECT    GetRegionRect();
    // Определить габариты всего набора карт в указанной системе координат
    virtual MAPDFRAME GetRegionDFrame(int pointplace);
    // Выделить объекты карты, удовлетворяющие QDMapSelect
    void            DoViewSelect(QDMapSelect *select, COLORREF color);
    // Условия отображения
    void            SetViewSelect(QDMapSelect *value);
    // Установить параметры группового выделения объектов для ViewSelect
    void            SetViewSelected(bool view);
    // Разрешить/запретить отображение карты в соответсвии с контекстом
    // условий отображения
    void            SetSelecting(bool value);
    // Конвертировать координаты из dframein система координат placein
    // в систему координат placeout
    virtual MAPDFRAME ConvertDFrame(MAPDFRAME dframein, int placein, int placeout);  // 03/02/03
    // Конвертировать координаты из  системы координат placein
    // в систему координат placeout
    virtual int ConvertMetric(double *x, double *y, int placein, int placeout);
    // Установить параметры группового выделения объетов не используя VarViewSelect
    void            SetObjSelected(QDMapSelect *objselect, COLORREF color,
                                   bool repaint);
    // Выполнить настройку на новые габариты изображения района
    // Если габариты действительно изменились то возвращает true
    bool UpdatePictureBorder();
    virtual void Repaint();
    // Разрешить/запретить перерисовку карты
    void  SetRendering(bool value);
    bool  GetRendering();
    // установить/отсоеденить текущий обработчик событий 
    // от элемента отображения картой
    bool SetCurrentAction(QWidget *gtkaction);                      // 21/11/03
    // actionquery - надо ли сначала запросить разрешение 
    // на отсоединение
    bool DeleteAction(QWidget *gtkaction, bool actionquery);

public slots:
    void         SetMapVisible(bool visible);

signals :
    // Сигналы от мыши :
    // x, y - позиция курсора в системе координат окна отображения карты (пикселы)
    // modkeys - состояние клавиш модификаторов и кнопок мыши
    void SignalMouseMove(int x, int y, int modkeys);
    void SignalMousePress(int x, int y, int modkeys);
    void SignalMouseRelease(int x, int y, int modkeys);
    void SignalMouseDoubleClick(int x, int y, int modkeys);
    // Сигналы от клавиатуры :
    // key     - код клавиши,
    // count   - количество нажатий клавиши,
    // modkeys - модифицированные флаги, которые существовали перед тем,
    // как только произошло событие
    void SignalKeyPress(int key, int count, int state);
    void SignalKeyRelease(int key, int count, int state);
    // Сигналы от окна отображениякарты :                                  // 25/10/06
    void SignalAfterPaint(QPainter* p, int cx, int cy, int cw, int ch);


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Блок функций для внутреннего использования
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

protected :
    // Переопределния для работы QDGtkAction и сигналов
    //  Системная функция Qt :
    //  Обработать сообщение
    //  Перемещение мыши
    void viewportMouseMoveEvent(QMouseEvent * e);
    //  Системная функция Qt :
    //  Обработать сообщение нажатие кнопки мыши
    void viewportMousePressEvent(QMouseEvent * e);
    //  Системная функция Qt :
    //  Обработать отжатие кнопки мыши
    void viewportMouseReleaseEvent(QMouseEvent * e);
    //  Системная функция Qt :
    //  Обработать двойное нажатие кнопки мыши
    void viewportMouseDoubleClickEvent ( QMouseEvent * e );
    //  Системная функция Qt :
    //  Нажата клавиша
    void keyPressEvent(QKeyEvent *k );
    //  Системная функция Qt :
    //  Клавиша отпущена
    void keyReleaseEvent(QKeyEvent *k );

public :
    virtual void drawContents(QPainter* p, int cx, int cy, int cw, int ch);  // 01/04/07

    // Обработка событий изменения состава карт и их отображения
    // на уровне MapViewWindow
    virtual void    AllMapRef(int typeaction);
    // Обработка событий изменения состава карт на уровне MapViewWindow
    virtual void    MapAction(int typeaction);
    // Установить текщий Select для отображения
    void SetViewSelectNow(QDMapSelect *mapselect, bool alwaysnew);
    // Стандартная процедура таймера (Qt)
    virtual void timerEvent(QTimerEvent *e);
    // Перерисовка окна средствами ядра  mapacces
    void PaintOfMapAcces();
    // Обработчик сообщений
    long int MessageHandler(long int context, long int code,
                            long int wp, long int lp, long int typemsg = 0);
    //  Обработать сообщение окну карты
    int   DoMapWindowMsg(long int code, long int param);
    //  Переместить карту в заданную точку
    int   MoveMap(long int wparam, long int lparam);
    // Установить координаты левого верхнего угла карты
    void  SetPicturePoint(POINT& point);
    // Отправить сообщение окну карты
    int   MapWindowPort(int command, int parm);
    // Вызывается перед отрисовкой карты                                   // 21/11/03
    void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    // Вызывается после отрисовки карты
    void MapAfterPaint(QObject *sender, HWND canvas, RECT mappaintrect);

public :
    // Пользователю только на чтение
    bool                  VarSelecting;        // Разрешить/запретить отображение карты в
                                               // соответствии с контекстом условий отображения
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Блок переменных для внутреннего использования
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    DFRAME                VarMapFrame;
    int                   VarPlace;
    RECT                  VarMapRec;
    HDC                   VarHDC;
    void                  *PointerVarXDC;
    int                   VarHorzPos;
    int                   VarVertPos;
    bool                  VarMapVisible;
    QList<QDMapComponent> VarMapObjects;
    QDMapSelect           *VarViewSelectLast;  // Какой именно QDMapSelect установлен
                                               // последним для отображения в ядро
    QDMapSelect           *VarViewSelect;
    bool                  VarViewSelected;     // Признак необходимости группового выделения
                                               // используя ViewSelect
    int                   VarColorSelected;    // Цвет группового выделения
    QDMapSelect           *VarObjSelect;       // Параметры выделения объектов
    QRect                 RectDraw;            // Область отрисовки карты
    int                   VarPaintEnabled;     // Флаг отрисовки карты
    bool                  VarRendering;
    // текущий обработчик событий от окна карты типа QDGtkAction // 21/11/03
    QWidget               *VarCurrentGtkAction;
//!!!!!!!!!!!!!!!!!!!!
// Окончание блока
//!!!!!!!!!!!!!!!!!!!
};

#endif // QDMWINA_H
