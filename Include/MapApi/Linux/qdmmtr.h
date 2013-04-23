/******** QDMMTR.H ************** Dishlenko S.G.  ****** 20/01/03 **
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
*               ������ ������� � ������� �����                     *
*                                                                  *
*******************************************************************/

#ifndef QDMMTR_H
#define QDMMTR_H

#include "maptype.h"
#include "qdmpoina.h"

class QDMapViewAcces;
class QDMapView;

//++++++++++++++++++++++++++++++++++++++++
//+++  ����� ������� � �������         +++
//++++++++++++++++++++++++++++++++++++++++

class QDMapMtr
{
  public :
    QDMapMtr(QDMapViewAcces *mapview);
    ~QDMapMtr();
    // ��������� �� ��������� �����
    QDMapView  *GetMapView();
    // ��� ��������� �����
    char *GetMtrFileName();
    bool MapIsOK();
    // ���������/��������� ����������� �������
    bool GetMtrView();
    void SetMtrView(bool value);
    // ������� ����������� ������� ������������ �����
    int  GetMtrViewOrder();
    void SetMtrViewOrder(int value);
    // �������� ��������� �������
    bool GetMtrDesc(MTRDESCRIBE *desc);

  public :
    // ������������ ������ �� ������
    int             VarNumber;
    QDMapViewAcces  *VarMapView;
    QDMapPointAcces *VarMapPoint;
};

//++++++++++++++++++++++++++++++++++++++++++
//+++ ����� ������� � ������� - ��������� ++
//++++++++++++++++++++++++++++++++++++++++++

class  QDMapMtrs
{

public :
    QDMapMtrs(QDMapViewAcces *mapview);
    ~QDMapMtrs();

    // ���������� ������ ��������� ���������� � ������
    int      GetMtrCount();
    // ������ � ����� ��������� ���������� �� ����������� ������
    QDMapMtr *GetMapMtrs(int number);
    // ������ � ������ ��������� ���������� �� ������������
    QDMapMtr *GetNameMtrs(char *mtrname);
    // ������ � ������ ��������� ���������� �� ����������� � ������
    // Number - ����� ����� ��������� ���������� � ����������
    QDMapMtr *GetPointMtrs(QDMapPointAcces *mappoint, int number);
    // ������� ���� ��������� ����������
    int      Append(char *mtrfilename);
    // ������� ���� ��������� ���������� �� ������������
    void     DeleteName(char *mtrfilename);
    // ������� ���� ��������� ���������� �� ����������� ������
    // ��������! ��� �������� ����� ��������� ���������� � ������� �������
    // ������� ������ ���������.
    void     Delete(int number);

public :
    // ��� ���������� ����������� !!!!!
    QDMapMtr *VarMapMtr;
};

#endif // QDMMTR_H
