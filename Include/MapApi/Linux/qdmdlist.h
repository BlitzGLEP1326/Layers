/******** QDMDLIST.H ************* Dishlenko S.G.  ****** 14/11/05 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*        КОМПОНЕНТ - ДИАЛОГ "СПИСОК ДАННЫХ ЭЛЕКТРОННОЙ КАРТЫ"      *
*                                                                  *
*******************************************************************/

#ifndef QDMDLIST_H
#define QDMDLIST_H

#include "qdmcmp.h"
#include "listapi.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ КЛАСС ДИАЛОГА                                +
//+++ "СПИСОК ДАННЫХ ЭЛЕКТРОННОЙ КАРТЫ"            +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapDataList : public QDMapComponent
{
    Q_OBJECT

// Раскоментарить для ПС "Конструктор"
// Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)

public :
    // Для пользователя
    //------------------------------
    QDMapDataList(QWidget *parent = 0, const char *name = 0);
    ~QDMapDataList() {};
    // Выполнить диалог 
    void         Execute();
    // Указатель на карту
    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;                     

    // Служебные
    //------------------------------
    // Заполнить структуру для вызова задачи
    void InitTaskParm(TASKPARM *taskparm, MAPLISTPARM* maplistparm);
};

#endif // QDMDLIST_H
