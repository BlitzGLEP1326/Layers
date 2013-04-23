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
*        �������� ������ ������� � �������� �����������            *
*                     ����������� �����                            *
*                                                                  *
*******************************************************************/

#ifndef QDMWINA_H
#define QDMWINA_H

#include <qlist.h>
#include "qdmviewa.h"
#include "qdmcompa.h"

class QDMapSelect;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++ ����� "��������� ����������� ����������� ������" +++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class  QDMapViewWindow : public QDMapViewAcces
{
   Q_OBJECT

    // ���������/��������� ���������� �����
    Q_PROPERTY(bool MapVisible READ GetMapVisible WRITE SetMapVisible)

public :
   QDMapViewWindow(QWidget *parent = 0, const char *name = 0, WFlags f = 0);  // 11/12/07);
   ~QDMapViewWindow();

    bool         GetMapVisible() const;
    // ���������/���������� ������� ����� ������� ������ �����������
    void         GetMapLeftTop(int *left, int *top);
    void         SetMapLeftTop(int left, int top);
    // �������� ���������� mapcomponent � ������ ���������
    void AppendMapObject(QDMapComponent *mapcomponent);
    // �������� ���������� mapcomponent �� ������ ���������
    void DeleteMapObject(QDMapComponent *mapcomponent);
    // ���������/���������� ������� ������� �����������
    virtual int     GetViewScale();
    virtual int     SetViewScale(int value);
    // ������� ��������� �������� ������������ ������� �����
    //   ���������: value - �������� �������, ������� ������ ��������
    int             SetViewScaleInPoint(int value);                        // 25/11/03

    // ���������� �������� ����� ������ ���� � ��������
    virtual RECT    GetRegionRect();
    // ���������� �������� ����� ������ ���� � ��������� ������� ���������
    virtual MAPDFRAME GetRegionDFrame(int pointplace);
    // �������� ������� �����, ��������������� QDMapSelect
    void            DoViewSelect(QDMapSelect *select, COLORREF color);
    // ������� �����������
    void            SetViewSelect(QDMapSelect *value);
    // ���������� ��������� ���������� ��������� �������� ��� ViewSelect
    void            SetViewSelected(bool view);
    // ���������/��������� ����������� ����� � ����������� � ����������
    // ������� �����������
    void            SetSelecting(bool value);
    // �������������� ���������� �� dframein ������� ��������� placein
    // � ������� ��������� placeout
    virtual MAPDFRAME ConvertDFrame(MAPDFRAME dframein, int placein, int placeout);  // 03/02/03
    // �������������� ���������� ��  ������� ��������� placein
    // � ������� ��������� placeout
    virtual int ConvertMetric(double *x, double *y, int placein, int placeout);
    // ���������� ��������� ���������� ��������� ������� �� ��������� VarViewSelect
    void            SetObjSelected(QDMapSelect *objselect, COLORREF color,
                                   bool repaint);
    // ��������� ��������� �� ����� �������� ����������� ������
    // ���� �������� ������������� ���������� �� ���������� true
    bool UpdatePictureBorder();
    virtual void Repaint();
    // ���������/��������� ����������� �����
    void  SetRendering(bool value);
    bool  GetRendering();
    // ����������/����������� ������� ���������� ������� 
    // �� �������� ����������� ������
    bool SetCurrentAction(QWidget *gtkaction);                      // 21/11/03
    // actionquery - ���� �� ������� ��������� ���������� 
    // �� ������������
    bool DeleteAction(QWidget *gtkaction, bool actionquery);

public slots:
    void         SetMapVisible(bool visible);

signals :
    // ������� �� ���� :
    // x, y - ������� ������� � ������� ��������� ���� ����������� ����� (�������)
    // modkeys - ��������� ������ ������������� � ������ ����
    void SignalMouseMove(int x, int y, int modkeys);
    void SignalMousePress(int x, int y, int modkeys);
    void SignalMouseRelease(int x, int y, int modkeys);
    void SignalMouseDoubleClick(int x, int y, int modkeys);
    // ������� �� ���������� :
    // key     - ��� �������,
    // count   - ���������� ������� �������,
    // modkeys - ���������������� �����, ������� ������������ ����� ���,
    // ��� ������ ��������� �������
    void SignalKeyPress(int key, int count, int state);
    void SignalKeyRelease(int key, int count, int state);
    // ������� �� ���� ���������������� :                                  // 25/10/06
    void SignalAfterPaint(QPainter* p, int cx, int cy, int cw, int ch);


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ���� ������� ��� ����������� �������������
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

protected :
    // �������������� ��� ������ QDGtkAction � ��������
    //  ��������� ������� Qt :
    //  ���������� ���������
    //  ����������� ����
    void viewportMouseMoveEvent(QMouseEvent * e);
    //  ��������� ������� Qt :
    //  ���������� ��������� ������� ������ ����
    void viewportMousePressEvent(QMouseEvent * e);
    //  ��������� ������� Qt :
    //  ���������� ������� ������ ����
    void viewportMouseReleaseEvent(QMouseEvent * e);
    //  ��������� ������� Qt :
    //  ���������� ������� ������� ������ ����
    void viewportMouseDoubleClickEvent ( QMouseEvent * e );
    //  ��������� ������� Qt :
    //  ������ �������
    void keyPressEvent(QKeyEvent *k );
    //  ��������� ������� Qt :
    //  ������� ��������
    void keyReleaseEvent(QKeyEvent *k );

public :
    virtual void drawContents(QPainter* p, int cx, int cy, int cw, int ch);  // 01/04/07

    // ��������� ������� ��������� ������� ���� � �� �����������
    // �� ������ MapViewWindow
    virtual void    AllMapRef(int typeaction);
    // ��������� ������� ��������� ������� ���� �� ������ MapViewWindow
    virtual void    MapAction(int typeaction);
    // ���������� ������ Select ��� �����������
    void SetViewSelectNow(QDMapSelect *mapselect, bool alwaysnew);
    // ����������� ��������� ������� (Qt)
    virtual void timerEvent(QTimerEvent *e);
    // ����������� ���� ���������� ����  mapacces
    void PaintOfMapAcces();
    // ���������� ���������
    long int MessageHandler(long int context, long int code,
                            long int wp, long int lp, long int typemsg = 0);
    //  ���������� ��������� ���� �����
    int   DoMapWindowMsg(long int code, long int param);
    //  ����������� ����� � �������� �����
    int   MoveMap(long int wparam, long int lparam);
    // ���������� ���������� ������ �������� ���� �����
    void  SetPicturePoint(POINT& point);
    // ��������� ��������� ���� �����
    int   MapWindowPort(int command, int parm);
    // ���������� ����� ���������� �����                                   // 21/11/03
    void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    // ���������� ����� ��������� �����
    void MapAfterPaint(QObject *sender, HWND canvas, RECT mappaintrect);

public :
    // ������������ ������ �� ������
    bool                  VarSelecting;        // ���������/��������� ����������� ����� �
                                               // ������������ � ���������� ������� �����������
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ���� ���������� ��� ����������� �������������
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
    QDMapSelect           *VarViewSelectLast;  // ����� ������ QDMapSelect ����������
                                               // ��������� ��� ����������� � ����
    QDMapSelect           *VarViewSelect;
    bool                  VarViewSelected;     // ������� ������������� ���������� ���������
                                               // ��������� ViewSelect
    int                   VarColorSelected;    // ���� ���������� ���������
    QDMapSelect           *VarObjSelect;       // ��������� ��������� ��������
    QRect                 RectDraw;            // ������� ��������� �����
    int                   VarPaintEnabled;     // ���� ��������� �����
    bool                  VarRendering;
    // ������� ���������� ������� �� ���� ����� ���� QDGtkAction // 21/11/03
    QWidget               *VarCurrentGtkAction;
//!!!!!!!!!!!!!!!!!!!!
// ��������� �����
//!!!!!!!!!!!!!!!!!!!
};

#endif // QDMWINA_H
