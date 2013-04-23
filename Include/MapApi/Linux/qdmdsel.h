/******** QDMDSEL.H ************* Dishlenko S.G.  ****** 02/07/06 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2006              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*             ��������� - ������ ������ �������                    *
*              �������� ��� ������/�����������                     *
*                                                                  *
*******************************************************************/

#ifndef QDMDSEL_H
#define QDMDSEL_H

#include "qdmcmp.h"      // 24/07/03
#include "qdmtype.h"     // 28/11/03

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ ����� ������ ������ �������                  *
//+++ �������� ��� ������/�����������              +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapSelect;

class QDMapSelectDialog : public QDMapComponent
{
    Q_OBJECT

// �������������� ��� �� "�����������"                        // 18/11/03
//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03

public :
    QDMapSelectDialog(QWidget *parent = 0, const char *name = 0);
    ~QDMapSelectDialog() {};
    // ��������� �� �����
    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;                     // 24/07/03
    bool         Execute(QDMapSelect *mapselect, bool viewoffind);

public :
    long int  VarNote;           // ����� �������� �������� � �������
    bool      VarSeekMapAll;     // ������� ������������� ������ �� ���� ��������� ������
    int       VarSeekMapNumber;  // ����� ����� ��� ������ (����� ����� � ������ VarSeekMapAll = false)
    bool      VarSeekVisual;     // ���� ������ ����� ������� �� ����� ��������
    // ������ ��� ������  !!!!!!!
    int       VarModalResult;    // ��� �������� ����� ��������� �������
};


#endif // QDMDSEL_H
