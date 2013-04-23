/****** gpsapi.h *************** Belenkov O.V. ******** 05/08/04 ***
******* gpsapi.h *************** Shabakov D.A. ******** 15/02/05 ***
******* gpsapi.h *************** Dishlenko S.G.******** 03/08/05 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*             ЧТЕНИЕ ДАННЫХ С GPS, РАБОТА С COM-ПОРТОМ             *
*                                                                  *
*******************************************************************/

#ifndef GPSAPI_H
#define GPSAPI_H

#ifndef MAPTYPE_H
  #include "maptype.h"
#endif

#ifdef LINUXAPI // 03/08/05
  // Управление терминалом
  #include <termios.h>
#endif

typedef long int HCOMPORT;

extern "C"
{

// Открыть COM-порт для чтения GPS - сообщений в формате NMEA O183
// Для Windows:
  // portname - имя COM-порта (например, "COM1:")
  // baudrate - частота обмена с портом (например, 9600)
// Для Linux:
//   portname - имя COM-порта (например, "/dev/ttyS0"("COM1:" в Windows))
//   baudrate - частота обмена с портом (например, B9600 или B4800)
// При ошибке возвращает 0
HCOMPORT _MAPAPI gpsOpen(LPTSTR portname, long int baudrate);

// Закрыть COM-порт
void _MAPAPI gpsClose(HCOMPORT hcomport);

// Открыть COM-порт для чтения/записи
// portname - имя COM-порта (например, "COM1:")
// baudrate - частота обмена с портом (например, 4800)
// При ошибке возвращает 0
HCOMPORT _MAPAPI gpsOpenComPort(LPTSTR portname, long int baudrate);

// Закрыть COM-порт
void _MAPAPI gpsCloseComPort(HCOMPORT hcomport);

// Запросить - обновились ли координаты точки
// Это можно делать по таймеру, например, каждую секунду
long int _MAPAPI gpsIsUpdate(HCOMPORT hcomport);

// Запросить координаты текущей точки в радианах в системе 42 года
// Признак обновления координат сбрасывается
long int _MAPAPI gpsGetPoint(HCOMPORT hcomport, DOUBLEPOINT * point,
                             double * height);

// Запросить координаты текущей точки в градусах в системе GPS (WGS-84)
// Признак обновления координат сбрасывается
long int _MAPAPI gpsGetSourcePoint(HCOMPORT hcomport, DOUBLEPOINT * point,
                                   double * height);

// Запросить число используемых спутников
long int _MAPAPI gpsSatelliteCount(HCOMPORT hcomport);

//  Запросить число видимых спутников   // 04/02/05
long int _MAPAPI gpsVisibleSatelliteCount(HCOMPORT hcomport);

// Включить формирование протокола входного буфера // 06/02/05
long int _MAPAPI gpsCreateFileProtocol(HCOMPORT hcomport, char *fileName, long int sizeFileName);

// Отключить протокол входного буфера // 06/02/05
long int _MAPAPI gpsCloseFileProtocol(HCOMPORT hcomport);

// Запросить качество приема данных
long int _MAPAPI gpsQuality(HCOMPORT hcomport);

// Запросить имя открытого COM-порта
LPTSTR _MAPAPI gpsPortName(HCOMPORT hcomport);

// Запросить идентификатор открытого COM-порта
// Если порт закрыт - возвращает ноль
HANDLE _MAPAPI gpsPortHandle(HCOMPORT hcomport);

// Запросить частоту обмена с портом
// Если порт закрыт - возвращает ноль
long int _MAPAPI gpsBaudrate(HCOMPORT hcomport);

// Запросить содержимое последней записи из GPS
// buffer - адрес буфера для размещения результата
// size   - размер буфера
// При ошибке возвращает ноль
long int _MAPAPI gpsGetRecord(HCOMPORT hcomport, char * buffer, long int size);

// Передать запись в порт (некоторые GPS-устройства активизируются
// после получения команды)
// buffer - адрес буфера с отправляемой записью
// size   - размер отправляемой записи
// При ошибке возвращает ноль
long int _MAPAPI gpsPutRecord(HCOMPORT hcomport, char * buffer, long int size);

#ifdef WIN32API     // 03/08/05
// Запросить код ошибки последней операции
// При отсутствии ошибки возвращает ноль
long int _MAPAPI gpsGetLastError(HCOMPORT hcomport);


// Установить Функции обратного вызова  // 15/02/05
// mask - команда(сообщение устройства), соответствующая вызываемой функции
// call - адрес вызываемой функции (см. maptype.h),
// parm - параметр, который будет передан вызываемой функции.
// При ошибке возвращает ноль
long int _MAPAPI gpsSetMask(HCOMPORT hcomport,
                            const char * mask, MASKCALL call, long int parm);
#endif

} // extern "C"

#endif  // MAPPORT_H
