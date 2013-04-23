/****** LOGAPI.H *************** Belenkov O.V.   ****** 16/01/06 ***
******* LOGAPI.H *************** Gustinivich N.A.****** 30/10/02 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2006              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*       �������� ������ ������� � ��'���� "������ ����������"      *
*        ��������� ��� �������� �� ������ C, PASCAL, BASIC         *
*                                                                  *
*******************************************************************/

#ifndef LOGAPI_H
#define LOGAPI_H

#ifndef MAPTYPE_H
  #include "maptype.h"
#endif


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ �������� ������� ������� � ������� ���������� +++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#ifdef __cplusplus
extern "C"
{
#endif

 // ��������� - ������� �� ������ ����������
 // 0 - �� �������, ����� - �������
 long int _MAPAPI mapGetLogAccess(HMAP hMap, HSITE hSite);

 // ���������/��������� ������� ������� ���������� (0/1)
 // ����� �������� ����� ������� ������� ���������.
 // ����������� ������������ ������ ��� ��������� ���������
 // ��������, ����� �������������� ������ �����������
 // ��������� ������ ��� ���� ������� !
 // ����� ����������� ������� ������������� ������������ �
 // ��������� ����� ������ !
 // ��� ������ ���������� ����
 long int _MAPAPI mapLogAccess(HMAP hMap, HSITE hSite,long int mode);

 // ��������� ����� ���������� � �������
 // ��� ������ ���������� ����
 long int _MAPAPI mapLogCount(HMAP hMap, HSITE hSite);

 // ��������� ���� �������� �������
 // date - ���� � ������� "YYYYMMDD"
 // time - ����� � ������� "����� ������ �� 00:00:00"
 // �� ��������� ����
 // ��� ������ ���������� ����
 long int _MAPAPI mapLogDate(HMAP hMap, HSITE hSite,
                             long int * date, long int * time);

 // ������� ������ ����������
 // type - ��� ���������� (�� 0x4000 �� 0�0FFFF - �� ���������)
 // ��� ������ ���������� ����
 long int _MAPAPI mapLogCreateAction(HMAP hMap, HSITE hSite,
                                     long int type);

 // ������ � �������� ���������� �������� �� ��������
 // ��������� ACTIONRECORD ������� � maptype.h
 // ��� ������ ���������� ����
 long int _MAPAPI mapLogPutRecord(HMAP hMap, HSITE hSite,
                                  ACTIONRECORD * record);

 // ������� ������ ����������
 void _MAPAPI mapLogCommitAction(HMAP hMap, HSITE hSite);

 // ��������� ����� ������ ����������,�����������
 // ����� ��������� ���� � �������
 // date - ���� � ������� "YYYYMMDD"
 // time - ����� � ������� "����� ������ �� 00:00:00"
 // �� ��������� ���� (�� �������� - GetSystemTime, in Coordinated Universal Time (UTC))
 // ��� ������ ���������� ����
 long int _MAPAPI mapLogGetActionNumberByTime(HMAP hMap, HSITE hSite,
                                              long int date,
                                              long int time);

 // ������� ��������� �������� ��������� �� ���������� ����������
 // ������ �� �������
 // ���� ����� ���������� ����������� ���������� �����
 // ��� ������ ���� - ���������� ����
 // ��� ������ ���������� ����,
 // ����� - ����� ����������
 long int _MAPAPI mapReadLastAction(HMAP hMap, HSITE hSite,
                                    ACTIONHEAD * head);

 // ������� ��������� �������� ��������� �� ���������� ����������
 // ������ �� �������
 // flag - ������� ������ ��������� ����������:
 // LOG_ANYACTION(0) - ��� �������, LOG_MYACTION(1) - ��������� ���������
 // ���� ���������� (���������� ���������� ������ �������������)
 // ���� ����� ���������� ����������� ���������� �����
 // ��� ������ ���� - ���������� ����
 // ��� ������ ���������� ����,
 // ����� - ����� ����������
 long int _MAPAPI mapReadLastActionEx(HMAP hMap, HSITE hSite,
                                      ACTIONHEAD * head, long int flag);

 // ������� ��������� �������� ���������� �� �������
 // number - ���������������� ����� ����������
 // (�� 1 �� Count(...)).
 // ��������� ACTIONHEAD ������� � maptype.h
 // ��� ������ ���������� ����,
 // ����� - ����� �������� � ����������
 long int _MAPAPI mapLogReadAction(HMAP hMap, HSITE hSite,
                                   long int number, ACTIONHEAD * head);

 // ��������� �������� �� ��������
 // number - ����� �������� (�� 1 �� ReadAction(...))
 // ��������� ACTIONRECORD ������� � maptype.h
 // ��� ������ ���������� ����
 long int _MAPAPI mapLogGetActionRecord(HMAP hMap, HSITE hSite,
                                        long int number,
                                        ACTIONRECORD * record);

 // ��������� ���������� �������� � ����������
 // ��� ������ ���������� ����
 long int _MAPAPI mapLogGetActionRecordCount(HMAP hMap, HSITE hSite);

 // ��������� �������� �� ������ �� ������
 // ��� ������ ���������� ����
 long int _MAPAPI mapLogIsWrite(HMAP hMap, HSITE hSite);

 // �������� ��������� ����������
 // ���� ����� ���������� ����������� ���������� �����
 // ��� ������ ���� - ���������� ����
 // ��� ������ ���������� ����,
 // ����� - ���������� ��������������� ��������
 long int _MAPAPI mapLogAbolitionLastAction(HMAP hMap, HSITE hSite);

 // �������� ��������� ����������
 // flag - ������� ������ ��������� ����������:
 // LOG_ANYACTION(0) - ��� �������, LOG_MYACTION(1) - ������������ ���������
 // ���� ���������� (���������� ���������� ������ �������������)
 // ���� ����� ���������� ����������� ���������� �����
 // ��� ������ ���� - ���������� ����
 // ��� ������ ���������� ����,
 // ����� - ���������� ��������������� ��������
 long int _MAPAPI mapLogAbolitionLastActionEx(HMAP hMap, HSITE hSite,
                                              long int flag);

 // ��������� ������ ���������� (� ����������� ����)
 void _MAPAPI mapLogFlush(HMAP hMap, HSITE hSite);

 // ��������� ������������� �������� ����������
 // ������������ � ���� Task ��������� ACTIONHEAD
 // ��� ������ ���������� ����
 long int _MAPAPI mapLogGetMyIdent(HMAP hMap, HSITE hSite);


#ifdef __cplusplus
}  // extern "C"
#endif

#endif