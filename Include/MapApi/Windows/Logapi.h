/****** LOGAPI.H *************** Belenkov O.V.   ****** 16/01/06 ***
******* LOGAPI.H *************** Gustinivich N.A.****** 30/10/02 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2006              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*       ОПИСАНИЕ КЛАССА ДОСТУПА К ОБ'ЕКТУ "ЖУРНАЛ ТРАНЗАКЦИЙ"      *
*        ИНТЕРФЕЙС ДЛЯ ПРОГРАММ НА ЯЗЫКАХ C, PASCAL, BASIC         *
*                                                                  *
*******************************************************************/

#ifndef LOGAPI_H
#define LOGAPI_H

#ifndef MAPTYPE_H
  #include "maptype.h"
#endif


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ ОПИСАНИЕ ФУНКЦИЙ ДОСТУПА К ЖУРНАЛУ ТРАНЗАКЦИЙ +++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#ifdef __cplusplus
extern "C"
{
#endif

 // Запросить - ведется ли журнал транзакций
 // 0 - не ведется, иначе - ведется
 long int _MAPAPI mapGetLogAccess(HMAP hMap, HSITE hSite);

 // Запретить/Разрешить ведение журнала транзакций (0/1)
 // После открытия карты ведение журнала разрешено.
 // Допускается использовать только при потоковой обработке
 // объектов, когда быстродействие важнее возможности
 // сохранить данные при сбое системы !
 // Перед отключением журнала рекомендуется позаботиться о
 // резервной копии данных !
 // При ошибке возвращает ноль
 long int _MAPAPI mapLogAccess(HMAP hMap, HSITE hSite,long int mode);

 // Запросить число транзакций в журнале
 // При ошибке возвращает ноль
 long int _MAPAPI mapLogCount(HMAP hMap, HSITE hSite);

 // Запросить дату создания журнала
 // date - дата в формате "YYYYMMDD"
 // time - время в формате "число секунд от 00:00:00"
 // на указанную дату
 // При ошибке возвращает ноль
 long int _MAPAPI mapLogDate(HMAP hMap, HSITE hSite,
                             long int * date, long int * time);

 // Открыть запись транзакции
 // type - тип транзакции (от 0x4000 до 0х0FFFF - за Панорамой)
 // При ошибке возвращает ноль
 long int _MAPAPI mapLogCreateAction(HMAP hMap, HSITE hSite,
                                     long int type);

 // Внести в описание транзакции сведения об операции
 // Структура ACTIONRECORD описана в maptype.h
 // При ошибке возвращает ноль
 long int _MAPAPI mapLogPutRecord(HMAP hMap, HSITE hSite,
                                  ACTIONRECORD * record);

 // Закрыть запись транзакции
 void _MAPAPI mapLogCommitAction(HMAP hMap, HSITE hSite);

 // Запросить номер первой транзакции,выполненной
 // после указанных даты и времени
 // date - дата в формате "YYYYMMDD"
 // time - время в формате "число секунд от 00:00:00"
 // на указанную дату (по Гринвичу - GetSystemTime, in Coordinated Universal Time (UTC))
 // При ошибке возвращает ноль
 long int _MAPAPI mapLogGetActionNumberByTime(HMAP hMap, HSITE hSite,
                                              long int date,
                                              long int time);

 // Считать заголовок описания последней не отмененной транзакции
 // задачи из журнала
 // Если после транзакции выполнялась сортировка карты
 // или журнал пуст - возвращает ноль
 // При ошибке возвращает ноль,
 // иначе - номер транзакции
 long int _MAPAPI mapReadLastAction(HMAP hMap, HSITE hSite,
                                    ACTIONHEAD * head);

 // Считать заголовок описания последней не отмененной транзакции
 // задачи из журнала
 // flag - условия выбора последней транзакции:
 // LOG_ANYACTION(0) - нет условий, LOG_MYACTION(1) - считывать последнюю
 // свою транзакцию (пропускать транзакции других пользователей)
 // Если после транзакции выполнялась сортировка карты
 // или журнал пуст - возвращает ноль
 // При ошибке возвращает ноль,
 // иначе - номер транзакции
 long int _MAPAPI mapReadLastActionEx(HMAP hMap, HSITE hSite,
                                      ACTIONHEAD * head, long int flag);

 // Считать заголовок описания транзакции из журнала
 // number - последовательный номер транзакции
 // (от 1 до Count(...)).
 // Структура ACTIONHEAD описана в maptype.h
 // При ошибке возвращает ноль,
 // иначе - число операций в транзакции
 long int _MAPAPI mapLogReadAction(HMAP hMap, HSITE hSite,
                                   long int number, ACTIONHEAD * head);

 // Запросить сведения об операции
 // number - номер операции (от 1 до ReadAction(...))
 // Структура ACTIONRECORD описана в maptype.h
 // При ошибке возвращает ноль
 long int _MAPAPI mapLogGetActionRecord(HMAP hMap, HSITE hSite,
                                        long int number,
                                        ACTIONRECORD * record);

 // Запросить количество операций в транзакции
 // При ошибке возвращает ноль
 long int _MAPAPI mapLogGetActionRecordCount(HMAP hMap, HSITE hSite);

 // Запросить доступен ли журнал на запись
 // При ошибке возвращает ноль
 long int _MAPAPI mapLogIsWrite(HMAP hMap, HSITE hSite);

 // Отменить последнюю транзакцию
 // Если после транзакции выполнялась сортировка карты
 // или журнал пуст - возвращает ноль
 // При ошибке возвращает ноль,
 // иначе - количество восстановленных операций
 long int _MAPAPI mapLogAbolitionLastAction(HMAP hMap, HSITE hSite);

 // Отменить последнюю транзакцию
 // flag - условия выбора последней транзакции:
 // LOG_ANYACTION(0) - нет условий, LOG_MYACTION(1) - обрабатывать последнюю
 // свою транзакцию (пропускать транзакции других пользователей)
 // Если после транзакции выполнялась сортировка карты
 // или журнал пуст - возвращает ноль
 // При ошибке возвращает ноль,
 // иначе - количество восстановленных операций
 long int _MAPAPI mapLogAbolitionLastActionEx(HMAP hMap, HSITE hSite,
                                              long int flag);

 // Сохранить журнал транзакций (и переоткрыть файл)
 void _MAPAPI mapLogFlush(HMAP hMap, HSITE hSite);

 // Запросить идентификатор текущего компьютера
 // Записывается в поле Task структуры ACTIONHEAD
 // При ошибке возвращает ноль
 long int _MAPAPI mapLogGetMyIdent(HMAP hMap, HSITE hSite);


#ifdef __cplusplus
}  // extern "C"
#endif

#endif