/******** QDMDPRN.H  ************* Dishlenko S.G.  ****** 23/05/06 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2006              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*        ��������� - ������ "������������ ����� POSTSCRIPT"        *
*                                                                  *
*******************************************************************/

#ifndef QDMDPRN_H
#define QDMDPRN_H

#include "qdmcmp.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ ����� �������                                +
//+++ "������������ ����� POSTSCRIPT"              +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapBuildEps : public QDMapComponent
{
    Q_OBJECT

    // ����������\��������� �������� ����� ������ ������� �����      // 23/05/06
    Q_PROPERTY(bool AllRectActive READ GetAllRectActive WRITE SetAllRectActive)

public :
    // ��� ������������
    //------------------------------
    QDMapBuildEps(QWidget *parent = 0, const char *name = 0);
    ~QDMapBuildEps() {};
    // ��������� ������
    void         Execute();
    // ��������� �� �����
    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;
    // ����������\��������� �������� ����� ������ ������� �����
    // true  - ��� �����(�� ���������)
    // false - ������������� �������, �������� �������� SetMapRect
    void  SetAllRectActive(bool value);
    bool  GetAllRectActive() const;
    // ���������� ������� ������� ����� � ��������
    // ����� �������������� ������ ������ ����������
    // ���������� ���� ������ ������� ����� � 0
    // left, top     -  ����� ������� ����
    // right, bottom -  ������ ������
    void SetMapRect(int left, int top, int right, int bottom);

public:
    // ���������
    //------------------------------

    // ���� ������ ������� �����
    // true  - ��� ����� (�� ���������)
    // false - ������������� �������, �������� �������� SetMapRect
    bool  AllRectActive;
    RECT  MapRect;
};

#endif // QDMDPRN_H
