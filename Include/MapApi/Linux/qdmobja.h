/******* QDMOBJA.H  ************* Dishlenko S.G.   ****** 31/01/03 *
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
*     ОПИСАНИЕ БАЗОВОГО КЛАССА ОБЪЕКТА ЭЛЕКТРОННОЙ КАРТЫ           *
*                                                                  *
*******************************************************************/

#ifndef QDMOBJA_H
#define QDMOBJA_H

#include "qdmcompa.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ БАЗОВЫЙ КЛАСС ОБЪЕКТА ЭЛЕКТРОННОЙ КАРТЫ                  +++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapObjAcces : public QDMapComponent
{
  Q_OBJECT

  public :
    QDMapObjAcces(QWidget * parent = 0, const char * name = 0);
    ~QDMapObjAcces();
     // Возвращает идентификатор объекта
     HOBJ GetObjHandle();

  public :
   // Для служебного пользования
   HOBJ  VarObjHandle;  // Идентификатор объекта карты
};

#endif  //  QDMOBJA_H
