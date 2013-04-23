/******* QDMOBJ.H  ************* Dishlenko S.G.   ****** 14/09/06  *
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
*     ОПИСАНИЕ КЛАССА "КОМПОНЕНТ - ОБЪЕКТ ЭЛЕКТРОННОЙ КАРТЫ"       *
*                                                                  *
*******************************************************************/

#ifndef QDMOBJ_H
#define QDMOBJ_H

#include "qdmobja.h"
#include "qdmcmp.h"
#include "qdmpoint.h"
#include "mapapi.h"             // 28/11/03

class QDMapSemantic;
class QDMapMetric;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ КЛАСС "КОМПОНЕНТ - ОБЪЕКТ ЭЛЕКТРОННОЙ КАРТЫ"                ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapObj : public QDMapObjAcces
{
  Q_OBJECT

// Раскоментарить для ПС "Конструктор"                        // 18/11/03
//  Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03

  public :
    QDMapObj(QWidget * parent = 0, const char * name = 0);
    ~QDMapObj();

    // Создать объект карты по его описанию (для совместимости со старыми версиями)
    void CreateObject(int site, int kind, bool text, int list, int excode, int local);
    // Создать пустой объект
    void CreateNullObj(int sitenumber);
    // Записать изменения в карту
    void Commit();
    // Удалить объект из карты
    void Delete();
    // Найти объект карты по его уникальным параметрам
    int  SeekObject(char *listname, int key);
    // Переместить отображение объекта карты в центр окна
    void Center();

    enum  TOBJECTSTYLE   // Способ визуализации объектов карты
    {
      OS_NOVIEW = 1,       // Объект не отображается
      OS_NORMAL = 2,       // Отображаются в нормально виде
      OS_SELECT = 3        // Объект выделяется заданным способом
    };

    enum TOBJECTSTYLESELECT   // Тип Специального (выделенного) отображения объекта карты
    {
      SEL_LINE     = 1    // Выделение линией. Параметры Image, Mode, Parm игнорируются
                           // пользователем параметров Image, Mode, Parm
                           // рисуются утолщенной линией в 2 пиксела (функция IMGLINE)
    };

    int            GetKey();
    int            GetExCode();
    int            GetInCode();
    int            GetLocal();
    char *         GetObjName();
    int            GetImage();
    int            GetMode();
    char *         GetParm();
    char *         GetListName();
    char *         GetText(int subobj);
    bool           GetTextType();
    double         GetSquare();
    double         GetPerimeter();
    double         GetLength();
    int            GetSiteNumber();
    // Возвращает идентификатор пользовательской карты
    HSITE          GetSiteHandle();
    int            GetListNumber();
    int            GetPlaceOut();
    // Возвращает габариты объекта в указанной системе координат
    MAPDFRAME      GetObjFrame(int place);
    int            GetLayerNumber();
    void           SetStyle(int value);
    void           SetColorImage(int value);
    // Установить тип выделенного отображения объекта карты
    void           SetStyleSelect(int value);
    void           SetText(int subobj, char * value);
    void           SetObjHandle(HOBJ value);
    // Установить/запросить верхнюю и нижнюю границу масштаба
    void           SetBotTopScale(int bot, int top);
    void           GetBotTopScale(int *bot, int *top);
    virtual void   SetMapView(QDMapView *value);
    QDMapView      *GetMapView() const;                           // 24/07/03
    // Установить описание объекта используя диалог              // 14/09/06 
    // Вход    acreate - надо ли после успешного выполнения диалога сформировать описание
    //                QDMapObj (вид объекта, метрика, семантика) Заново или же установить
    //                только вид
    // Выход = true - вид объекта и карта установлены
    bool           SetObjectByDLg(bool acreate);

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Блок функций для внутреннего использования
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Перерисовать объект карты
    void           Repaint();
    void           MapAction(int acttype);
    void           Paint(HDC dc, RECT rect);
    void           RepaintPrivate(QDMapViewAcces *mapview);
    // Освободить текущий объект карты
    void           FreeCurrentObj();

public :
    // Пользователю только на чтение !!!!!!!!
    bool             VarOldFrame;
    int              VarStyle;
    MAPDFRAME        VarObjFrame;
    int              VarPlace;           // система координат по MapApi PP_
    PAINTPARM        VarImage;
    int              VarColorImage;
    int              VarColorImageLin;
    int              VarInCodeImage;
    int              VarStyleSelect;     // тип выделения
    QDMapSemantic    *VarSemantic;
    QDMapMetric      *VarMetric;
    char             StrVal[256];        // 18/10/05
};

#endif // QDMOBJ_H
