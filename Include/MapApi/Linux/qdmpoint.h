/******* QDMPOINT.H  ************* Dishlenko S.G.  ****** 18/11/03 *
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
*     �������� ������ "��������� - ����� ����������� �����"        *
*                                                                  *
*******************************************************************/

#ifndef QDMPOINT_H
#define QDMPOINT_H

#include "qdmcompa.h"
#include "qdmcmp.h"
#include "qdmpoina.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ ����� "��������� - ����� ����������� �����"                 ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class  QDMapPoint : public QDMapComponent
{
    Q_OBJECT

// �������������� ��� �� "�����������"                        // 18/11/03
//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03

    // ������� ��������� �� ������
    Q_PROPERTY(int PlaceIn READ GetPlaceIn WRITE SetPlaceIn)
    // ������� ��������� �� ������
    Q_PROPERTY(int PlaceOut READ GetPlaceOut WRITE SetPlaceOut)

public :
    QDMapPoint(QWidget * parent = 0, const char * name = 0);
    ~QDMapPoint();

    int        GetPlaceIn() const;
    int        GetPlaceOut() const;

    QDMapView  *GetMapView() const;
    virtual void SetMapView(QDMapView *value);

    // �������� ���������� � ������� PlaceIn
    bool SetPoint(double x, double y);
    // �������  ���������� � ������� PlaceOut
    bool GetPoint(double *x, double *y);

// ��� ���������� ����������� !!!!!
    // ��������� ������� ��������� ������� ���� �� ������ MapViewWindow
    void    MapAction(int typeaction);

public slots:
//!! ����� ����� ���  ���������� ����������� !!!!!
    void SetPlaceIn(int value);
    void SetPlaceOut(int value);

public :
    // ��� ���������� ����������� !!!!!
    QDMapPointAcces *VarMapPoint;
    QString         VarMapViewName;
    QWidget         *ParentHandle;
};

#endif // QDMPOINT_H
