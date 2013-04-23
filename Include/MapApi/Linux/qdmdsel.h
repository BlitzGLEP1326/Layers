/******** QDMDSEL.H ************* Dishlenko S.G.  ****** 02/07/06 **
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
*             КОМПОНЕНТ - ДИАЛОГ ВЫБОРА СОСТАВА                    *
*              ОБЪЕКТОВ ДЛЯ ПОИСКА/ОТОБРАЖЕНИЯ                     *
*                                                                  *
*******************************************************************/

#ifndef QDMDSEL_H
#define QDMDSEL_H

#include "qdmcmp.h"      // 24/07/03
#include "qdmtype.h"     // 28/11/03

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ КЛАСС ДИАЛОГ ВЫБОРА СОСТАВА                  *
//+++ ОБЪЕКТОВ ДЛЯ ПОИСКА/ОТОБРАЖЕНИЯ              +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapSelect;

class QDMapSelectDialog : public QDMapComponent
{
    Q_OBJECT

// Раскоментарить для ПС "Конструктор"                        // 18/11/03
//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03

public :
    QDMapSelectDialog(QWidget *parent = 0, const char *name = 0);
    ~QDMapSelectDialog() {};
    // Указатель на карту
    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;                     // 24/07/03
    bool         Execute(QDMapSelect *mapselect, bool viewoffind);

public :
    long int  VarNote;           // Номер активной закладки в диалоге
    bool      VarSeekMapAll;     // Признак необходимости поиска по всем доступным картам
    int       VarSeekMapNumber;  // Номер карты для поиска (имеет смысл в случае VarSeekMapAll = false)
    bool      VarSeekVisual;     // Флаг поиска среди видимых на карте объектов
    // Только для чтения  !!!!!!!
    int       VarModalResult;    // Код возврата после выпонения диалога
};


#endif // QDMDSEL_H
