/****** MAPSUPP.H ************** Kruzhkov A.E.   ****** 02/10/02 ***
******* MAPSUPP.H ************** Belenkov O.V.   ****** 18/10/05 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                  FOR  WINDOWS95 & WINDOWS NT                     *
*                                                                  *
********************************************************************
*                                                                  *
*              �������� ������ �������������� ������               *
*        ��������� ��� �������� �� ������ C, PASCAL, BASIC         *
*                        GISSUPP.DLL                               * 
*                                                                  *
*******************************************************************/

#ifndef MAPSUPP_H
#define MAPSUPP_H

#ifndef MAPTYPE_H
  #include "maptype.h"   // �������� �������� ���������� MAPAPI
#endif

#ifndef MAPAPI_H
  #include "mapapi.h"
#endif


// �������� ��������� ��� �������������� ����������� ������
typedef struct CHANGEPOINT
{
  DOUBLEPOINT  PointIn1 ; // ���������� ������ ����� �������� �����
  DOUBLEPOINT  PointIn2 ; // ���������� ������ ����� �������� �����
  DOUBLEPOINT  PointOut1; // ���������� ������ ����� �������� �����
  DOUBLEPOINT  PointOut2; // ���������� ������ ����� �������� �����

  double       Scale    ; // ���������� �����������  ��������������
  double       Angle    ; // ���� �������� ��������������
  long         Error    ; // ����������� �������� ������ ��������������
}
  CHANGEPOINT;


// �������� ��������� ��� ��������� ����� �������
typedef struct DECORATEOBJECTPARM
{
  long ObjectCode;       // ��� �������, �������������� �� ������ (0 - �� �����������)
  long TitleCode;        // ��� ������� "������� ���������"       (0 - �� �����������)

  long FirstTitleNumber; // �������� ������ �������              (>=1)
  long Subject;          // ����� ����������                     (>=0)
                         // (-1 - ���������� �� ������� � ���� �����������,
                         //       BeginPoint,EndPoint - ������������)
  long BeginPoint;       // ��������� � �������� ����� ��������� (>=1)
  long EndPoint;         //  (0 - ���������� �� ����� �������)

  long ComplexTitle;     // ������ �������� �������� ���������
                         //  (0 - ������� �� ������ �����)
                         //  (1 - ������� � ������������)
  long Reserve;          // ������

  double Distance;       // ���������� �� ����� �� �������       (>=1)
                         //  (��������� � ������ ������ - � �������� ��������)
}
  DECORATEOBJECTPARM;


extern "C"
{

 // �������������� ���������� ����� �� ����� �������
 // ��������� � ������
 // ���������� ��������� CHANGEPOINT ��� ����������� ���� ��������
 // � ����������� ������������ ��� �������������� �� ������� � �������
 // ��� ������ ������������ ����

 long int _export WINAPI mapInitChangePoint(CHANGEPOINT * changepoint);

 // ��������� ���������� ����� � ����� ������� � ������� �������� �
 // ���������������
 // ��� ������ ������������ ����

 long int _export WINAPI mapChangePoints(CHANGEPOINT * chahgepoint,
                                         DOUBLEPOINT * point);

 // ��������� ����� ������� obj
 // ������� ���� ������� � ������������ ��� ���������
 // �������� �� ������ ��������� ��������� ������� +
 // �������� ������� �� ������ ��������� ��������� �������
 // � ����� site
 // ��� ������ ���������� 0

 long int _export WINAPI mapNumerationPoints(HMAP map, HSITE site, HOBJ obj,
                                             DECORATEOBJECTPARM* parm);

}       // extern "C"


//-----------------------------------------------------------------
// ��������� ��� �������� ��������� � ������������ ����� �������
//-----------------------------------------------------------------
typedef struct OBJECTSCHEME
{
  char* NameTxt;  // ��� �������� �������� ����� � �������� �������
  char* NameWmf;  // ��� ��������� ���������
  long  Width;    // ������ �������� � ��
  long  Height;   // ������ �������� � ��
  long  Scale;    // ����������� �������� ����������� �������
                  // (����������� � gsGetScaleObjectMetricTxtToWmfGetScalePictObject)
  long  Border;   // ���� ������� ����� (1 - ����, 0 - ���)
  long  Image;    // ��� ��������� ������ (0 - �� ��������,
                  //  1 - �����,  2 - ���������� � ������)
}
 OBJECTSCHEME;

//-----------------------------------------------------------------
// �������� ���������� ����� � �������� ������� :
//
//  10               // ����� �����
// 6345.35  6456.46  // ���������� ������� � ������
//-----------------------------------------------------------------
 

extern "C"
{

 // ��������� �������������� ������� ����� �������
 // ����������� �������� ��������� � ���� Scale ��������� OBJECTSCHEME
 // ��� ������ ���������� ����

 long int _export WINAPI gsGetScaleObjectMetricTxtToWmf(OBJECTSCHEME* data);


 // ������� �������� �� ������ �������
 // ��� ������ ���������� ����

 long int _export WINAPI gsObjectMetricTxtToWmf(OBJECTSCHEME* data);

}


#endif  // MAPSUPP_H
