/******** QDMDGTOB.H   *********** Dishlenko S.G.  ****** 18/09/06 *
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
*                     ��������� - ������                           *
*          "������ ���� ������� �� ��������������"                 *
*                                                                  *
*******************************************************************/

#ifndef QDMDGTOB_H
#define QDMDGTOB_H

#include "qdmcompa.h"

class QDMapView;
class QDMapObj;

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ ����� �������                                +
//+++ "����� ���� ������� �� ��������������"       +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapSelectObjectRsc : public QDMapComponent
{
    Q_OBJECT

public :
    // ��� ������������
    //------------------------------
    QDMapSelectObjectRsc(QWidget *parent = 0, const char *name = 0);
    ~QDMapSelectObjectRsc() {};
    // ��������� �� �����
    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;                     
    // ��������� ������ ��� ���������� QDMapObj
    // ���� mapobj  - ��������� QDMapObj - ���� �� �������� �� ����� ���� ��� �������
    //                �� ��������������, �� ��� ������ ������ ����� �������� �� ����
    //   createflag - ���� �� ����� ��������� ���������� ������� ������������ ��������
    //                QDMapObj (��� �������, �������, ���������) ������ ��� �� ����������
    //                ������ ���
    bool         ExecuteForMapObj(QDMapObj *mapobj, bool createflag);

    // ��� ���������� ����������� !!!!!
    //------------------------------
    // ��������� ������ � ��������� ��������� �������� �������
    // ����� = true  - ������� � ��������� objinfo
    //         false - ����������
    bool         Execute(TMAPOBJECTINFO *objinfo);
    //  ����������  ������� ������ ����� � �������  �� �������� ���� � �����������
    //  ���� - sitenumber - ����� ����� � ������ (��� -1 - ������ �� ���� ���������������)
    //       - excode     - ���� ��� �������
    //       - local      - ������������ (��� -1 - ����������� �����)
    bool         SetBeginObjectForExcode(int sitenumber, int excode, int local);
    //  ����������  ������� ������ ����� � ������� �� �������� � �����������
    //  ���� - sitenumber - ����� ����� � ������ (��� -1 - ������ �� ���� ���������������)
    //       - nameobj      - �������� �������
    //       - local      - ������������ (��� -1 - ����������� �����)
    bool         SetBeginObjectForName(int sitenumber, char *nameobj, int local);

private :
    
    bool    FHelpEnabled;              // ���� ����������� ������ ������ � �������
    int     FRetSite;                  // ����� ����� ���������� �������
    HOBJ    ObjH;                      // ������������� ������������ �������

public :
    // ��� ������������
    //------------------------------
    char    FCaption[256];             // ��������� �������
    int     FSiteNumber;               // ����� ����� � ������� ���������� ��� �������
    int     FRetIncode;                // ���������� ��� ���������� �������
    int     FLocals[6];                // ����������� ��������� � �������
    bool    FMapEditEnabled;           // ���� ����������� ����, ������� �������� �������������
    bool    FRestoreEnabled;           // ����� �� ��������������� ��������� �������
};

#endif // QDMDGTOB_H

