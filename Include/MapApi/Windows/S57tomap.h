/****  S57TOMAP.H *************  Belenkov O.V. *******  31/08/05 ***
*****  S57TOMAP.H ************* Gheleznykov A.V. ****** 20/10/05 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                     All Rights Reserved                          *
*                                                                  *
********************************************************************
*                                                                  *
*                   FOR  WINDOWS2000 & WINDOWS XP                  *
*                                                                  *
********************************************************************
*                                                                  *
*            ������ ���� �� ������� S57 �������� 3                 *
*                       (S57TOGIS.DLL)                             *
*                                                                  *
*******************************************************************/

#if !defined(S57TOMAP_H)
#define S57TOMAP_H

#ifndef MAPTYPE_H
  #include "maptype.h"
#endif

extern "C"
{

// ----------------------------------------------------------------
// ��������� ����� �� ������� S57 
// source - ���� � ����� ������� S57 (*.000 ��� *.CAT)
// target - ���� � ������������ ����� (MAP ��� SIT) (������ 260 ��������),
//          ����� ���� �������� � ������� �������� 
// parm   - ��������������� ���������
// ��� ������ ��������� ��������� ������������� s57navy.rsc
// ��� ����������� ���� ����� ���������� ����������� ������ s57navy.iml
// ----------------------------------------------------------------
__declspec(dllimport)long int WINAPI LoadS57ToMap(const char * source,
                                                  char       * target,
                                                  TASKPARM   * parm);


// 20/10/2005
// ----------------------------------------------------------------
// ��������� ����� �� ������� S57 � ��������� �������������� �����
// source - ���� � ����� ������� S57 (*.000 ��� *.CAT)
// target - ���� � ������������ ����� (MAP ��� SIT) (������ 260 ��������),
//          ����� ���� �������� � ������� �������� 
// rscname - ���� � ������������� �������������� �����,
//          ����� ���� �������� � ������� �������� 
// parm   - ��������������� ���������
// ��� ������ ��������� ��������� ������������� s57navy.rsc
// ��� ����������� ���� ����� ���������� ����������� ������ s57navy.iml
// ----------------------------------------------------------------
__declspec(dllimport)long int WINAPI LoadS57ToMapForRsc(const char * source,
                                                        char       * target,
                                                        char* rscname,
                                                        TASKPARM   * parm);

}       // extern "C"

#endif  

