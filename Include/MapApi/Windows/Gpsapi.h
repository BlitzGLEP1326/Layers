/****** gpsapi.h *************** Belenkov O.V. ******** 05/08/04 ***
******* gpsapi.h *************** Shabakov D.A. ******** 15/02/05 ***
******* gpsapi.h *************** Dishlenko S.G.******** 03/08/05 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*             ������ ������ � GPS, ������ � COM-������             *
*                                                                  *
*******************************************************************/

#ifndef GPSAPI_H
#define GPSAPI_H

#ifndef MAPTYPE_H
  #include "maptype.h"
#endif

#ifdef LINUXAPI // 03/08/05
  // ���������� ����������
  #include <termios.h>
#endif

typedef long int HCOMPORT;

extern "C"
{

// ������� COM-���� ��� ������ GPS - ��������� � ������� NMEA O183
// ��� Windows:
  // portname - ��� COM-����� (��������, "COM1:")
  // baudrate - ������� ������ � ������ (��������, 9600)
// ��� Linux:
//   portname - ��� COM-����� (��������, "/dev/ttyS0"("COM1:" � Windows))
//   baudrate - ������� ������ � ������ (��������, B9600 ��� B4800)
// ��� ������ ���������� 0
HCOMPORT _MAPAPI gpsOpen(LPTSTR portname, long int baudrate);

// ������� COM-����
void _MAPAPI gpsClose(HCOMPORT hcomport);

// ������� COM-���� ��� ������/������
// portname - ��� COM-����� (��������, "COM1:")
// baudrate - ������� ������ � ������ (��������, 4800)
// ��� ������ ���������� 0
HCOMPORT _MAPAPI gpsOpenComPort(LPTSTR portname, long int baudrate);

// ������� COM-����
void _MAPAPI gpsCloseComPort(HCOMPORT hcomport);

// ��������� - ���������� �� ���������� �����
// ��� ����� ������ �� �������, ��������, ������ �������
long int _MAPAPI gpsIsUpdate(HCOMPORT hcomport);

// ��������� ���������� ������� ����� � �������� � ������� 42 ����
// ������� ���������� ��������� ������������
long int _MAPAPI gpsGetPoint(HCOMPORT hcomport, DOUBLEPOINT * point,
                             double * height);

// ��������� ���������� ������� ����� � �������� � ������� GPS (WGS-84)
// ������� ���������� ��������� ������������
long int _MAPAPI gpsGetSourcePoint(HCOMPORT hcomport, DOUBLEPOINT * point,
                                   double * height);

// ��������� ����� ������������ ���������
long int _MAPAPI gpsSatelliteCount(HCOMPORT hcomport);

//  ��������� ����� ������� ���������   // 04/02/05
long int _MAPAPI gpsVisibleSatelliteCount(HCOMPORT hcomport);

// �������� ������������ ��������� �������� ������ // 06/02/05
long int _MAPAPI gpsCreateFileProtocol(HCOMPORT hcomport, char *fileName, long int sizeFileName);

// ��������� �������� �������� ������ // 06/02/05
long int _MAPAPI gpsCloseFileProtocol(HCOMPORT hcomport);

// ��������� �������� ������ ������
long int _MAPAPI gpsQuality(HCOMPORT hcomport);

// ��������� ��� ��������� COM-�����
LPTSTR _MAPAPI gpsPortName(HCOMPORT hcomport);

// ��������� ������������� ��������� COM-�����
// ���� ���� ������ - ���������� ����
HANDLE _MAPAPI gpsPortHandle(HCOMPORT hcomport);

// ��������� ������� ������ � ������
// ���� ���� ������ - ���������� ����
long int _MAPAPI gpsBaudrate(HCOMPORT hcomport);

// ��������� ���������� ��������� ������ �� GPS
// buffer - ����� ������ ��� ���������� ����������
// size   - ������ ������
// ��� ������ ���������� ����
long int _MAPAPI gpsGetRecord(HCOMPORT hcomport, char * buffer, long int size);

// �������� ������ � ���� (��������� GPS-���������� ��������������
// ����� ��������� �������)
// buffer - ����� ������ � ������������ �������
// size   - ������ ������������ ������
// ��� ������ ���������� ����
long int _MAPAPI gpsPutRecord(HCOMPORT hcomport, char * buffer, long int size);

#ifdef WIN32API     // 03/08/05
// ��������� ��� ������ ��������� ��������
// ��� ���������� ������ ���������� ����
long int _MAPAPI gpsGetLastError(HCOMPORT hcomport);


// ���������� ������� ��������� ������  // 15/02/05
// mask - �������(��������� ����������), ��������������� ���������� �������
// call - ����� ���������� ������� (��. maptype.h),
// parm - ��������, ������� ����� ������� ���������� �������.
// ��� ������ ���������� ����
long int _MAPAPI gpsSetMask(HCOMPORT hcomport,
                            const char * mask, MASKCALL call, long int parm);
#endif

} // extern "C"

#endif  // MAPPORT_H
