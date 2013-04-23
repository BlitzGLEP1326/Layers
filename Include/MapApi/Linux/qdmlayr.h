/******* QDMLAYR.H ************** Dishlenko S.G.  ****** 31/01/03 **
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
*                 ������ ������� � ����� �����                     *
*                                                                  *
*******************************************************************/

#ifndef QDMLAYR_H
#define QDMLAYR_H

#include "maptype.h"

class QDMapViewAcces;
class QDMapView;
class QDMapObjAcces;
class QDMapSite;

//++++++++++++++++++++++++++++++++++++++++
//+++  ����� ������� � ����� �����     +++
//++++++++++++++++++++++++++++++++++++++++

class QDMapLayer
{

public :
    QDMapLayer(QDMapViewAcces *mapview, QDMapSite *mapsite);
    ~QDMapLayer();

    HRSC  GetRscHandle();
     // ��������� �� ��������� �����
    QDMapView  *GetMapView();
     // ��������� �� ��������� ���������������� �����
    QDMapSite  *GetMapSite();
     // ������������ ����
    char  *GetLayerName();
    // ���������� ������������ ���� - ����
    char  *GetLayerKey();
    // ���������� �������� ��������� � ��������������
    int    GetObjCount();
    // �������� �������� ��������
    char   *GetObjName(int number);
    // ������� ��� �������
    int    GetObjExCode(int number);
    // ���������� ��� �������
    int    GetObjInCode(int number);
    // �������� ����������� �������
    int    GetObjLocal(int number);
    // ���������� �������� ������� (����)
    char   *GetObjKey(int number);

public :
    // ������������ ������ �� ������
    QDMapViewAcces *VarMapView;
    int            VarNumber;        // ������� ����� ����
    QDMapSite      *VarMapSite;      // Site � ������� ��������  ����� ������ ��������� �� ��������� � VarRsc
    HRSC           VarHRsc;          // RSC � ������� �������� (���� FMapSite<>nil �� rsc ����������� �� Site)
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//+++  ����� ������� � ����� ����� - ���������    +++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapLayers
{

public :
    QDMapLayers(QDMapViewAcces *mapview, QDMapSite *mapsite);
    QDMapLayers(HRSC rsc);
    ~QDMapLayers();

    // ���������� �����
    int        GetLayerCount();
    // ���� �� ����������� ������
    QDMapLayer *GetMapLayers(int number);
    // ���� �� ������� �����
    QDMapLayer *GetObjLayers(QDMapObjAcces *mapobj);
    // ���� �� ����������� �������� - �����
    QDMapLayer *GetKeyLayers(char *keyname);
    void       SetRscHandle(HRSC rsc);

public :
   // ��� ����������� �������������
   QDMapLayer *VarMapLayer;
};

#endif  // QDMLAYR_H
