/******** QDMCONV.H ************* Dishlenko S.G.  *****  14/11/05 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*  Компонент      : QDMapConvertor - конвертор электронной карты   *
*                                                                  *
*******************************************************************/

#ifndef QDMCONV_H
#define QDMCONV_H

#include "qdmcompa.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ КЛАСС  - КОНВЕРТОРА ЭЛЕКТРОННОЙ КАРТЫ        +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapView;

class QDMapConvertor : public QDMapComponent
{
    Q_OBJECT

// Открыть для ПС КОНСТРУКТОР
//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)

public :

    // Для пользователя
    //-------------------------------------------
    QDMapConvertor(QWidget *parent = 0, const char *name = 0);
    ~QDMapConvertor();
    // Указатель на карту
    void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;
    // Запросить/установить название файла входных данных
    void         SetSourceName(const QString value);
    QString      GetSourceName();                     // 11/11/05
    // Запросить/установить название файла выходных данных
    void         SetDestName(const QString value);
    QString      GetDestName();
    // Запросить/установить тип входных данных
    void         SetSourceType(int value);
    int          GetSourceType();
    // Запросить/установить тип выходных данных
    void         SetDestType(int value);
    int          GetDestType();
    // Запустить процесс конвертирования данных
    void         Convert();

    // Рабочие функции и переменные
    //-------------------------------------------

public :
    QString VarSourceName;
    QString VarDestName;
    int     VarSourceType;
    int     VarDestType;
};

#endif // QDMCONV_H
