/******** QDMRST.H ************** Dishlenko S.G.  ****** 14/01/03 **
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
*                 ������ ������� � ������                          *
*                                                                  *
*******************************************************************/

#ifndef QDMRST_H
#define QDMRST_H

#include "maptype.h"

class QDMapViewAcces;

//++++++++++++++++++++++++++++++++++++++++
//+++  ����� ������� � ������          +++
//++++++++++++++++++++++++++++++++++++++++

class QDMapRst
{
  public :
    QDMapRst(QDMapViewAcces *mapview);
    ~QDMapRst();
    // ��� ��������� �����
    char *GetRstFileName();
  public :
// ��� ���������� ����������� !!!!!
    int            VarNumber;
    QDMapViewAcces *VarMapView;
};


//+++++++++++++++++++++++++++++++++++++++++++++++++++
//+++  ����� ������� � ������ - ���������         +++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapRsts
{
  public :
    QDMapRsts(QDMapViewAcces *mapview);
    ~QDMapRsts();
    // ���������� ������ ��������� ���������� � ������
    int      GetRstCount();
    // ������ � ������ ��������� ���������� �� ����������� ������
    QDMapRst *GetMapRsts(int number);
    // ������ � ������ ��������� ���������� �� ������������
    QDMapRst *GetNameRsts(char *rstname);
    // �������� ��������� �����
    int      Append(char *rstfilename);
    // ������� ��������� ����� �� ������������
    void     DeleteName(char *rstfilename);
    // ������� ��������� ����� �� ����������� ������
    // ��������! ��� ��������� ��������� ����� � ������� �������
    // ������� ������ ���������.
    void Delete(int number);
  public :
 // ��� ���������� ����������� !!!!!
    QDMapRst *VarMapRst;
};

#endif  // QDMRST_H
