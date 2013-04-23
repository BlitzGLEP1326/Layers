/******* QDMVIEWA.H ************* Dishlenko S.G.  ****** 11/12/07 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2007              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*       ОПИСАНИЕ БАЗОВОГО КЛАССА ДОСТУПА К ОБ'ЕКТУ                 *
*                     "ЭЛЕКТРОННАЯ КАРТА"                          *
*                                                                  *
*******************************************************************/

#ifndef QDMVIEWA_H
#define QDMVIEWA_H

#include <qscrollview.h>
#include <qtextcodec.h>
#include "qdmtype.h"                                   // 28/11/03

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++ БАЗОВЫЙ КЛАСС "ИНТЕРФЕЙС УПРАВЛЕНИЯ ЭЛЕКТРОННОЙ КАРТОЙ" ++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class  QDMapViewAcces : public QScrollView
{
   Q_OBJECT

public :
   QDMapViewAcces(QWidget *parent = 0, const char *name = 0, WFlags f = 0);  // 11/12/07

   // Получить идентификатор карты
   virtual HMAP GetMapHandle();

   // Получить объект доступа к карте
   virtual QDMapViewAcces *GetMapViewAcces();

public :
   // Для внутреннего использования
   HMAP       VarMapHandle;   // Реальный идентификатор карты
   QTextCodec *MainCodec;     // 02/06/06
};

#endif  // QDMVIEWA

