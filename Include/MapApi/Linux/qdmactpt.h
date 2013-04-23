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
*  ���������      : QDGetMapPoint -  ��������� ��������������      *
*                   ������ ����� �����                             * 
*                                                                  *
*******************************************************************/

#ifndef QDMACTPT_H
#define QDMACTPT_H

#include "qdmact.h"
#include "mapapi.h"

class QDMapObj;


//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ QDGetMapPoint -  ��������� ��������������    +
//+++                  ������ ����� �����          + 
//++++++++++++++++++++++++++++++++++++++++++++++++++
class QDGetMapPoint : public QDGtkAction
 {
  Q_OBJECT

public:

    QDGetMapPoint(QWidget * parent = 0, const char * name = 0);
    ~QDGetMapPoint();
    // ������� �������
    //---------------------------------------------------
    virtual void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MouseMove(int x, int y, int modkeys);
    virtual void MouseUp(int x, int y, int modkeys);

private :
    void PaintDot();
    void CalcCoordsForObjAndMouse(int aMouseX, int aMouseY);
    // ����������/������� �����
    void LinePaint();

public:                                           // 11/11/05

    // ��� ������������
    //---------------------------------------------------
    // ������������ ���������� � ���������� ����������� �����
    virtual void StartAction();     
    // �����������
    virtual void StopAction();      
    // ������ ��� �������� ���������� �����
    QDMapObj     *GetMapObj();
    void         SetMapObj(QDMapObj *mapobj);
    
    typedef enum TSELECTIONMODE
    {
      GETEXISTPOINT    = 1,      // ������������ ����� �������
      GETVIRTUALPOINT  = 2       // ��������� ����� �������
    };
    // ��� �����(TSELECTIONMODE) // 14/11/05
    int          GetTypePoint();          
    void         SetTypePoint(int type);

signals :
    // ������ � ������ �����
    // x, y       - ���������� ����� ������� � ������
    // numpoint   - ����� �����
    // numsubobj  - ����� ����������
    void SignalSelectPoint(double x, double y, int numpoint, int numsubobj);

    // ������� ����������
    //---------------------------------------------------
private :
    
    bool        FIsLine;         // ���������� �� �����
    DOUBLEPOINT FPointMouse;     // ���������� ����� ���� � ������ ��� ������
    DOUBLEPOINT FPointObj;       // ���������� ����� ������� ��� ������
    int         FNumPoint;       // ����� ����� �� �������
    int         FNumSubj;        // ����� ����������� ��� �������� �����

    QDMapObj    *FMapObj;        // ������ ��� �������� ���������� �����
    long int    FColorDot;       // ���� �������
    int         FLineWidth;      // ������� �������
    int         FDashLenght;     // ����� ������ �������
    int         FBlankLenght;    // ����� ������� �������

    PAINTPARM   FImageParm;      // ��������� ���������
    IMGDOT      FImageObj;
    PLACEDATA   FPlaceData;      // ������� �������
    DOUBLEPOINT FPlacePoints[2]; // ���������� �������
    long int    FPlaceCount;     // ���������� �������

    int         FTypeGetPoint;   // ��� �����
};

#endif // QDMACTPT_H
