/******** QDMTYPE.H ************* Dishlenko S.G.  *****  18/09/06 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2006              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*               Объявления типов и переменных                      *
*                                                                  *
*******************************************************************/

#ifndef QDMTYPE_H
#define QDMTYPE_H

#include "maptype.h"

// Тип возвращаемого параметра для QDMapSelectDialog
enum MAPSELECTDIALOGRETCODE
{
   MRCANCEL  = 0,
   MROK      = 1,
   MRALLMARK = 2
};

// Типы событий для компонент карты
typedef enum MAPACTIONTYPE
{
    ACTBEFOREPAINT            = 1,
    ACTAFTERPAINT             = 2,
    ACTBEFORECLOSE            = 3,
    ACTAFTEROPEN              = 4,
    ACTAFTERAPPENDSITE        = 5,
    ACTBEFOREDELETESITE       = 6,
    ACTDOREPAINTFORCHANGEDATA = 7, // изменились данные и надо перевывести
    ACTAFTERCHANGEBORDER      = 8
} MAPACTIONTYPE;

// Типы операций для компонент карты
typedef enum MAPOPERATION
{
    OPREMOVE           = 1,
} MAPOPERATION;

enum  TSEMANTICSTYLE // Способ выдачи значений семантики объектов карты
{
   SS_NODECODE     = 0,     // Значения не раскодируются
   SS_NORMALDECODE = 1,     // Значения раскодируются
   SS_FULLDECODE   = 2      // Значения раскодируются с добавлением единицы измерения
};

// Типы конвертируемых файлов источников
enum TCONVERTERTYPESOURCE
{
  TS_VIEW      = 0,
  TS_MAP       = 1,
  TS_DIRSXFWIN = 2,
  TS_SXFWIN    = 3,
};

// Типы конвертируемых файлов приемников
enum TCONVERTERTYPEDEST
{
  TD_VIEW      = 0,
  TD_MAP       = 1,
  TD_DIRSXFWIN = 2,
  TD_SXFWIN    = 3,
};

// Загрузка SXF, DIR в формат MAP
typedef long int (* QDLoadSxf2Map)(char* lpszsource,
                                   char* lpsztarget,
                                   TASKPARM* parm);
typedef long int (* QDLoadDir2Map)(char* lpszsource,
                                   char* lpsztarget,
                                   TASKPARM* parm);

// Выгрузка DIR
typedef long int (* QDSaveMap2Dir)(HMAP hmap,
                                   const char* lpsztarget, TASKPARM* parm);
// Выгрузка SXF
typedef long int (* QDSaveMap2Sxf)(HMAP hmap,
                                   const char* lpsztarget, TASKPARM* parm);

// Описание выбранного объекта из классификатора карты  // 18/09/06
typedef struct
{
   int             NumbSite;  // Номер карты (для основной = 0)
   int             Incode;    // Внутренний код объекта
   int             ExCode;    // КЛАССИФИКАЦИОННЫЙ КОД
   int             Local;     // ХАРАКТЕР ЛОКАЛИЗАЦИИ
   int             Segment;   // НOМЕР СЛОЯ
   char            *Name;     // название объекта
   char            *KeyName;  // Уникальное имя объекта в класс-ре
   char            *Key;      // ключ
}
  TMAPOBJECTINFO;

#endif // QDMTYPE_H
