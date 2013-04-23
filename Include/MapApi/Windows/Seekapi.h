/****** SEEKAPI.H ************** Belenkov O.V.   ****** 02/02/06 ***
******* SEEKAPI.H ************** Sokolova T.O.   ****** 29/01/03 ***
******* SEEKAPI.H ************** Nefedieva O.A.  ****** 02/09/04 ***
******* SEEKAPI.H ************** Gustinovich N.A.****** 02/10/02 ***
******* SEEKAPI.H ************** Tarakanova I.R. ****** 06/10/05 ***
******* SEEKAPI.H ************** Kruzhkov A.E.   ****** 31/01/06 ***
******* SEEKAPI.H ************** Vitsko D.A.     ****** 22/11/05 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2006              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*            �������� ������� ������� ��'����� �����               *
*        ��������� ��� �������� �� ������ C, PASCAL, BASIC         *
*                                                                  *
********************************************************************
*                                                                  *
*    �������������� ������� � Windows :                            *
*                                                                  *
*    // �������� ����������                                        *
*    HINSTANCE libInst = ::LoadLibrary("gisacces.dll");            *
*                                                                  *
*    // ����� �������                                              *
*    HMAP (WINAPI * lpfn_OpenMap)(const char*, long int);          *
*    (FARPROC)lpfn_OpenMap = GetProcAddress(libInst, "OpenMap");   *
*    HMAP hMap = (*lpfn_OpenMap)("Noginsk.map",0);                 *
*                                                                  *
*    // �������� ����������                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

#ifndef SEEKAPI_H
#define SEEKAPI_H

#ifdef __cplusplus
extern "C"
{
#endif

  /*********************************************************
  *                                                        *
  *        ������� ������ ��'����� ����������� �����       *
  *                                                        *
  *     ����� ����� ����������� � �������� ��������� :     *
  *       ����������� (Picture)  - � ��������,             *
  *       �����,��� ������ (Map) - � ���������,            *
  *       � ������������� ��                               *
  *       ��������� (Plane)      - � ������,               *
  *       � ������������� ��                               *
  *       ��������� (Geo)        - � ��������.             *
  *                                                        *
  *********************************************************/

 // ������, ������������ ������� ������ ��������
 // ������ � �������,���������,��������� �� �������� �����,
 // ����������, ������ c ����������, ������ � �������� �����.
 // ���� ������� WO_INMAP - ����� ����� ������������
 // �� HSELECT !
 // ����� ���������� � ������� WO_FIRST ��� WO_LAST (���� ���
 // ������� � �������� ���������� �����), ����� �����������
 // ������ WO_NEXT ��� WO_BACK (��������, � �����).
 // enum SEEKTYPE { WO_FIRST  = 0,  WO_LAST  = 2,
 //                 WO_NEXT   = 4,  WO_BACK  = 8,
 //                 WO_CANCEL = 16, WO_INMAP = 32 };


 // ������ ��'���� �� �������� �����������
 // hMap - ������������� �������� �����.
 // info - ������������� ������� � ������,
 //        �������������� ���������� �������� mapCreateObject()
 //        ��� mapCreateSiteObject(),
 //        � ������� ����� �������� ��������� ������.
 // ����� ���������� ����� ��� ��������,������� ����� �� ������ !
 // frame - ������������� ������� ������ ������� � ������� ���������,
 //         �������� ���������� place (PP_PLANE,PP_GEO, ...)
 // flag - ������� ������ �������� (WO_FIRST, WO_NEXT...)
 // ����� ������� � "�����" ����� �������� � ����������, ��
 // ���� ����, ��� ��������� ������ ��������� (��� ���� ���������
 // ������� ������).
 // ��� ������ � �������� WO_NEXT,WO_BACK �������� info ������
 // ��������� ��������� ����������� ������.
 // place - ������� ���������.
 // ���� ������ �� ������ - ���������� ����,
 // ����� - ���������� �������� info !
#ifdef __cplusplus
_MAPIMP HOBJ _MAPAPI mapWhatObject(HMAP hMap,HOBJ info,MAPDFRAME * frame,
                            long int flag = WO_LAST,
                            long int place = PP_MAP);
#else
_MAPIMP HOBJ _MAPAPI mapWhatObject(HMAP hMap,HOBJ info,MAPDFRAME * frame,
                            long int flag,
                            long int place);
#endif

#ifdef __cplusplus
 // ������ ��'���� �� �������� ����������� ����� �������� ��������
 // ����� ���������� ����� ��� ��������,������� ����� �� ������ !
 // �������� ������� - �������� ��� �������������� ������ (����������)
 // ��������� ������� ������ ����������� �������� mapSetSiteActiveSelect()
 // hMap  - ������������� �������� �����,
 // info  - ������������� ������� � ������,
 //         �������������� ���������� �������� mapCreateObject()
 //         ��� mapCreateSiteObject(),
 //         � ������� ����� �������� ��������� ������.
 // frame - ������������� ������� ������ ������� � ������� ���������,
 //         �������� ���������� place (PP_PLANE,PP_GEO, ...)
 // flag  - ������� ������ �������� (WO_FIRST, WO_NEXT...)
 // place - ������� ���������.
 // ���� ������ �� ������ - ���������� ����

_MAPIMP long int _MAPAPI mapWhatActiveObject(HMAP hMap,HOBJ info,MAPDFRAME * frame,
                                             long int flag = WO_LAST,
                                             long int place = PP_MAP);
#endif

 // ���������� ������� ������ ��������
 // hMap  - ������������� �������� �����.
 // place - ������� ������ �������,
 // ���� ����� ����, �� ��� �������� � �������� ������� (WO_LAST,
 // WO_PREV) ������� ����� ���� �������,
 // ���� �� ����� ����, �� ��� ������ ������ (WO_FIRST, WO_NEXT)
 // ������� ����� �������
 // ��-��������� ������� � ����� ���������� ���������� (��� WO_LAST),
 // �.�. place = 1

_MAPIMP void _MAPAPI mapSetTextPlace(HMAP hMap, long int place);
_MAPIMP long int _MAPAPI mapGetTextPlace(HMAP hMap);

 // ������ ��'���� �� �������� �����������
 // hMap - ������������� �������� �����.
 // info - ������������� ������� � ������,
 //        �������������� ���������� �������� mapCreateObject()
 //        ��� mapCreateSiteObject(),
 //        � ������� ����� �������� ��������� ������.
 // ����� ���������� ����� ��� ��������,�������
 // ������������� �������� HSELECT !
 // select- �������� ������� ������ ��������,
 // place - ������� ���������,
 // frame - ������������� ������� ������ ������� � ������� ���������,
 //         �������� ���������� place (PP_PLANE,PP_GEO, ...)
 // flag  - ������� ������ �������� (WO_FIRST, WO_NEXT...)
 // ����� ������� � "�����" ����� �������� � ����������, ��
 // ���� ����, ��� ��������� ������ ��������� (��� ���� ���������
 // ������� ������).
 // ��� ������ � �������� WO_NEXT,WO_BACK �������� info ������
 // ��������� ��������� ����������� ������.
 // ���� ������ �� ������ - ���������� ����,
 // ����� - ���������� �������� info !
#ifdef __cplusplus
_MAPIMP HOBJ _MAPAPI mapWhatObjectBySelect(HMAP hMap,HOBJ info,
                                    MAPDFRAME * frame,
                                    HSELECT select,
                                    long int flag = WO_LAST,
                                    long int place = PP_MAP);
#else
_MAPIMP HOBJ _MAPAPI mapWhatObjectBySelect(HMAP hMap,HOBJ info,
                                    MAPDFRAME * frame,
                                    HSELECT select,
                                    long int flag,
                                    long int place);
#endif

 // ����� ������� �� ����� ����� (������������) � ������ �������
 // ����� ���� ����
 // hMap - ������������� �������� �����.
 // info - ������������� ������������� �������,
 //        � ������� ����� �������� ��������� ������.
 // listname - �������� (������������) �����,
 // key      - ������������� ������� � �����,
 // ��� ������ ���������� ����

_MAPIMP HOBJ _MAPAPI mapSeekObject(HMAP hMap,HOBJ info,
                            const char * listname, long int key);

_MAPIMP HOBJ _MAPAPI mapSeekObjectInList(HMAP hMap, HSITE hSite, HOBJ info,
                                  long int list, long int key);


 // ����� ������ ������� �� ����� ����� (������������) � ������ �������
 // ����� ���� ���� (� ������� �� ������ ������� ���������� ����� �������
 // � ��� ��������� ��������, ���� �� ���� ���������� �����)
 // hMap     - ������������� �������� �����,
 // listname - �������� (������������) �����,
 // key      - ������������� ������� � �����.
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSeekObjectNumber(HMAP hMap,
                                      const char * listname, long int key);


 // ����� �������� �� �������� �������� ����� ���� ��������
 // hMap     - ������������� �������� �����,
 // info     - ������������� ������������� �������,
 //            � ������� ����� �������� ��������� ������.
 // select   - ������� ������ �������
 // flag     - ������� ������ �������� (WO_FIRST, WO_NEXT...)
 // ��� ������ � �������� WO_NEXT,WO_BACK �������� info ������
 // ��������� ��������� ����������� ������.
 // ���� ������ �� ������ - ���������� ����
#ifdef __cplusplus
_MAPIMP HOBJ _MAPAPI mapSeekSelectObject(HMAP hMap,HOBJ info,HSELECT select,
                                  long int flag = WO_FIRST);
#else
_MAPIMP HOBJ _MAPAPI mapSeekSelectObject(HMAP hMap,HOBJ info,HSELECT select,
                                  long int flag);
#endif


 // ����� �������� �� �������� �������� ����� ������������ ��������
 // (����������� �������� ������� � ��������� �����������)
 // hMap     - ������������� �������� �����,
 // info     - ������������� ������������� �������,
 //            � ������� ����� �������� ��������� ������.
 // select   - ������� ������ �������
 // flag     - ������� ������ �������� (WO_FIRST, WO_NEXT...)
 // ���� ������ �� ������ - ���������� ����

#ifdef __cplusplus
_MAPIMP HOBJ _MAPAPI mapSeekViewObject(HMAP hMap,HOBJ info,HSELECT select,
                                long int flag = WO_FIRST);
#else
_MAPIMP HOBJ _MAPAPI mapSeekViewObject(HMAP hMap,HOBJ info,HSELECT select,
                                long int flag);
#endif


 //  ����� ��'����, �������� � ������ ��'����� ������� ������� .
 //  ����� ������� � �����, ��� ��������� ��������� ������
 //  ���� ������ �� ������ - ���������� ����.
 //  hMap     - ������������� �������� �����,
 //  info     - ������������� ������������� �������,
 //             ��� �������� ���� ����� ������� �������
 //  target   - ��������� �� ������������ ������ TObjectInfo,
 //             � ������� ����� �������� ��������� ������.
 //  ��� ������ � �������� WO_NEXT,WO_BACK �������� target ������
 //  ��������� �� ��������� ����������� ������.
 //  select   - ������� ������ �������
 //  delta    - ������ �� ������� � ������ (����� ��������� 0)
 //             � ��������� MAPADJACENTSECTION ���� number 
 //             ��� ���������� ������ ������ ���� ������ 0.
 //  flag     - ������� ������ �������� (WO_FIRST, WO_NEXT...)
 //  ��� ������ � �������� WO_NEXT,WO_BACK �������� info ������
 //  ��������� ��������� ����������� ������.
 //  ���� ������ �� ������ - ���������� ����,
 //  ����� - ���������� ����� ������� � ����������� ��������� MAPADJACENTSECTION
 //  (��. MAPTYPE.H)
 //  subject = 0 ������ ������� ������ � ������� ��������
 // ( 1- � ������ �����������, ��������� ����� ������� � ����������� - ��������)
#ifdef __cplusplus
_MAPIMP long int _MAPAPI mapSeekAdjacentObject(HMAP hMap,HOBJ info,
                                    HOBJ target,
                                    MAPADJACENTSECTION * section,
                                    HSELECT select,
                                    double delta = 0.0,
                                    long int flag = WO_FIRST | WO_INMAP,
                                    long int subject = 0);
#else
_MAPIMP long int _MAPAPI mapSeekAdjacentObject(HMAP hMap,HOBJ info,
                                    HOBJ target,
                                    MAPADJACENTSECTION * section,
                                    HSELECT select,
                                    double delta,
                                    long int flag,
                                    long int subject);
#endif


 //  ����� �������, ������� � ������ ��'����� ������� ������� .
 //  ����� ������� � �����, ��� ��������� ��������� ������
 //  ���� ������ �� ������� - ���������� ����,
 //  ����� - ���������� �������.
 //  hMap  - ������������� �������� �����,
 //  info  - ������������� ������������� �������,
 //          ��� �������� ���� ����� ������� �������
 //  MAPADJACENTLISTEX - ������ ��� �������
 //  count - ������������ ���������� ������� ��������
 //  select - ������� ������ �������� ��� ������
 //  delta - ������ �� ������� � ������
 //  point - ��������� ������,���������� �������������� �������:
 //  0 - �������� � ������, 1 - ���
 //  subject - 0 ������ ������� ������ � ������� ��������
 // ( 1- � ������ �����������, ��������� ����� ������� � ����������� - ��������)
#ifdef __cplusplus
_MAPIMP long int _MAPAPI mapSeekAdjacentListEx(HMAP hMap,HOBJ info,
                                       MAPADJACENTLISTEX * list,
                                       long int count,
                                       HSELECT select,
                                       double delta = 0.0,
                                       long int point = 0,
                                       long int subject = 0);
#else
_MAPIMP long int _MAPAPI mapSeekAdjacentListEx(HMAP hMap,HOBJ info,
                                       MAPADJACENTLISTEX * list,
                                       long int count,
                                       HSELECT select,
                                       double delta,
                                       long int point,
                                       long int subject);
#endif


 // ��������� - �������� �� ������ ��� ������� ������/�����������
 // ���� �������� ���������� ��������� ��������
 // hMap     - ������������� �������� �����,
 // select   - ������� ������/����������� 
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapTestObject(HOBJ info,HSELECT select);


 // ����� ������� �� ������ ����� � ����������������� ������ �������
 // (������ ������ � ������� ��� ��������)
 // hMap     - ������������� �������� �����,
 // hSite    - ������������� �������� ���������������� �����,
 // info     - ������������� ������������� �������,
 //            � ������� ����� �������� ��������� ������;
 // list     - ����� ����� (��� ���������������� ����� ������ 1);
 // object   - ���������������� ����� ������� � �����
 // (������� � 1 �� mapGetObjectCount(...) ��� mapGetSiteObjectCount(...)).
 // ���� ������ ����� ������� "������" - ���������� 1 !!!
 // ��� �������� ���������� ���������� �������� info.
 // ��� ������ ���������� ����

_MAPIMP HOBJ _MAPAPI mapReadObjectByNumber(HMAP hMap,HSITE hSite,HOBJ info,
                                    long int list,long int object);

 // ����� ������� �� ������ ����� � ����������� ������ �������
 // ���� ������ ����� ������� "������" - ���������� 1 !!!
 // ��� �������� ���������� ���������� �������� info.
 // hMap     - ������������� �������� �����,
 // hSite    - ������������� �������� ���������������� �����,
 // info     - ������������� ������������� �������,
 //            � ������� ����� �������� ��������� ������;
 // list     - ����� ����� (��� ���������������� ����� ������ 1);
 // key      - ���������� ����� �������.
 // ��� ������ ���������� ����

_MAPIMP HOBJ _MAPAPI mapReadObjectByKey(HMAP hMap, HSITE hSite, HOBJ info,
                                 long int list, long int key);


  /*********************************************************
  *                                                        *
  * ������� ����������� ������ ��'����� ����������� �����  *
  *                                                        *
  *********************************************************/

 // ��������� ������� ����������� ������ �� ������
 // hMap - ������������� �������� �����,
 // ���� ��������� = -1, ����� ����� ����������� �� ���� ������
 // (0 - ����� ���������, 1...n - ���������������� �����)
 // ��� ������ ���������� ����� (-2)

_MAPIMP long int _MAPAPI mapGetTotalSeekMapRule(HMAP hMap);


 // ���������� ������� ����������� ������ �� ������
 // hMap     - ������������� �������� �����,
 // number   - ����� �����, �� ������� ����������� �����,
 // ���� number == -1, ����� ����� ����������� �� ���� ������
 // (0 - ����� ���������, 1...n - ���������������� �����)
#ifdef __cplusplus
_MAPIMP void _MAPAPI mapSetTotalSeekMapRule(HMAP hMap,long int number = -1);
#else
_MAPIMP void _MAPAPI mapSetTotalSeekMapRule(HMAP hMap,long int number);
#endif


 // ���������� ������� ����������� ������ ���
 // ������������ �������� �����
 // hMap - ������������� �������� �����,
 // ���� view == 0, ����� ����������� ����� ���� ��������
 // �����, ����� - ����� ������������ (SeekViewObject())
#ifdef __cplusplus
_MAPIMP void _MAPAPI mapSetTotalSeekViewRule(HMAP hMap,long int view = 0);
#else
_MAPIMP void _MAPAPI mapSetTotalSeekViewRule(HMAP hMap,long int view);
#endif
 long int _MAPAPI mapGetTotalSeekViewRule(HMAP hMap);


 // ���������� ������� ������/��������� �������� �� ����� �����
 // � ������ ������� � �����
 // hMap     - ������������� �������� �����,
 // listname - ��� ����� ����� (����� ���������� �������������)
 // key      - ����� ������� � ����� (BaseKey)
 // ���� ��� ����� ����������� ������� ������ �� ������� ��������,
 // �� ��������� ������� (����,�����������...) ������������.
 // ���� ����� �� ������� - ���������� ����

_MAPIMP long int _MAPAPI mapSetTotalSeekSample(HMAP hMap,const char* listname,
                                        long int key);


 // ���������� ������� ������/��������� �������� �� ���� ������
 // (���������������� � ����� ���������)
 // hMap     - ������������� �������� �����,
 // acceess  - ������� ������ �������� :
 // =  0 - ��������� ����� ���� �������� ���� ���� (��������� ��� �����������),
 // != 0 - ��� ������� �������� ��� ������ � mapTotalSeekObject().
 // (������������ �������� ������� ������ ��� ���� ����;
 //  ����� ����������� mapSetTotalSeekSample ������ ����� ���� ��������)
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetTotalSeekAccess(HMAP hMap, long int access);


 // �������� �� ����� �������, ��������������� ��������
 // ����������� ������
 // hMap     - ������������� �������� �����,
 // hDC      - �������� ���������� �����������,  
 // rect     - ���������� ��������� ����� (Draw) � ����������� (Picture)
 // color    - ����, ������� ����� ���������� ������� �� �����
 // ������� ����� ������� ���������
 //              ::SetViewportOrgEx(hDC, dx , dy, 0),
 // ��� dx,dy - ��������� ������������� ��������� � ���������
 // ������� !
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapTotalPaintSelect95(HMAP hMap,HDC hDC, RECT * rect,
                                        COLORREF color);


 // �������� �� ����� �������, ��������������� ��������
 // ����������� ������
 // hMap   - ������������� �������� ������,
 // hwnd   - ������������� ���� ������,
 // color  - ����, ������� ����� ���������� ������� �� �����,
 // point - ���������� �������� ������ ���� ���� �� �����
 // � �������������� ��������� place ������� ���������.
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapTotalViewSelect(HMAP hMap, HWND hwnd,
                                     DOUBLEPOINT * point,
                                     COLORREF color,
                                     long int place /*= PP_PLANE*/);


 // ���������� ������� �������� ������������� ��������
 // ����������� ������
 // hMap     - ������������� �������� �����,
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapTotalSeekObjectCount(HMAP hMap);


 // ���������� ����� �������� �� �������� ��������
 // ������� ����������� ������ �������� �������
 // (������������ ������� mapGetSiteViewSelect(),mapGetSiteSeekSelect()...)
 // hMap - ������������� �������� �����,
 // info - ��������� �� ������������ ������ TObjectInfo
 // flag - ������� ������ �������� (WO_FIRST, WO_NEXT...)
 // ��� ������ � �������� WO_NEXT,WO_BACK �������� info ������
 // ��������� �� ��������� ����������� ������.
 // ���� ������ �� ������ - ���������� ����

_MAPIMP HOBJ _MAPAPI mapTotalSeekObject(HMAP hMap,HOBJ info,
                                 long int flag);


 // ���������� ������� ��������� �������� �� ����������
 // �������� ������
 // hMap - ������������� �������� �����,
 // flag = -1, ����� ����� ����������� �� ���� ������
 // (0 - ����� ���������, 1...n - ���������������� �����)
 // �������� �������� ����� ���������� �������� �� ����������
 // ����������� ��� ����� ����� ���������� ��������

_MAPIMP void _MAPAPI mapSetTotalSelectFlag(HMAP hMap, long int flag);


 // ��������� ������� ��������� �������� �� ����������
 // �������� ������
 // hMap - ������������� �������� �����,
 // ���� ��������� = -1, ����� ����� ����������� �� ���� ������
 // (0 - ����� ���������, 1...n - ���������������� �����)

_MAPIMP long int _MAPAPI mapGetTotalSelectFlag(HMAP hMap);


 // ���������� ����� �������� ��������, ��������������� ��������
 // ��������
 // �������� �������������� � ������
 // hMap   - ������������� �������� �����,
 // border - ���������� �������������� ������� ��� ��������.
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetTotalSeekBorder(HMAP hMap, DFRAME * border);



 /*********************************************************
 *                                                        *
 * ������� ��������/�������� ��������� ������/����������� *
 *                                                        *
 *********************************************************/

  // ������� �������� (�������� �������) ������/�����������
  // �������� �����
  // � ������ ������� ������ �������� ������ : ����, ����,
  // �����������, �������� ������� ��������, ��������������
  // (���������) �������, ������� ������������ (�������) �������
  // � ��������� ��������� �������� ��� ������� ����� ��� ����������
  // ������������� ������� 10 �� �����,
  // ���� ������ ������� ������ �� ������� � ��������� - �� 300 ��
  // ������ ��������� �������� ������ ���� ������, �����
  // �� ������ �� ������������
  // hMap   - ������������� �������� �����,
  // �������� hmap ���������, ����� ��������������� ������� ������/
  // ����������� �� ���������
  // ��� ������ ���������� ����

_MAPIMP  HSELECT _MAPAPI mapCreateMapSelectContext(HMAP hmap);


  // ������� ����� ��������� (�������� �������) ������/�����������
  // �������� �����
  // select - �������� �������� (�������� �������) ������/�����������.
  // ������ ��������� �������� ������ ���� ������, �����
  // �� ������ �� ������������
  // ��� ������ ���������� ����

_MAPIMP  HSELECT _MAPAPI mapCreateCopySelectContext(HSELECT select);


  // ���������� �������� (�������� �������) ������/�����������
  // � ������������ �������� ������/�����������
  // target - �������� ������� ������, ���� ����������� �����������;
  // source - ���������� �������� ������.
  // (������ ��������� �������� ������ ���� ������, �����
  // �� ������ �� ������������)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCopySelectContext(HSELECT target, HSELECT source);


  // ���������� ������ �� ���� ����� ������
  // ��������� ������/�����������
  // select - �������� (�������� �������) ������/�����������.
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapClearSelectContext(HSELECT select);


  // ������� �������� (�������� �������) ������/�����������
  // �������� �����
  // select - �������� (�������� �������) ������/�����������.

_MAPIMP  void _MAPAPI mapDeleteSelectContext(HSELECT select);


  // ����������/��������� ������� �������������� ������� ������
  // select - �������� (�������� �������) ������/�����������.
  // flag   - ������� ��������������

_MAPIMP  long int _MAPAPI mapSetInversionSelect(HSELECT select, long int flag);

_MAPIMP  long int _MAPAPI mapGetInversionSelect(HSELECT select);


  // ���������� ������ � �������� � �������� �������
  // ���� (��������)
  // select - �������� ������� ������
  // layer  - ����� ����(��������), ���������� � 0 (!),
  // ���� ����� -1 (0xFFFFFFFF), �� ���������������
  // ������ �� ���� ����� �����;
  // check  - ����������� ���� (0 - ��� �������, != 0 - ����)
  // ������ Layer ������� ��������� ����� Segment

_MAPIMP  void _MAPAPI mapSelectLayer(HSELECT select, long int layer,
                              long int check);


  // ��������� �������� �� ������� � �������� �������
  // ���� (��������)
  // select - �������� ������� ������
  // layer  - ����� ����(��������)
  // ���� ����� -1 (0xFFFFFFFF), �� �����������
  // ������ �� ���� ����� ����� (0 - ���-�� ����������);
  // ������ Layer ������� ��������� ����� Segment
  // ����������� ���� : 0 - ��� �������, != 0 - ����.

_MAPIMP  long int _MAPAPI mapCheckLayer(HSELECT select, long int layer);


  // ���������� ������ � �������� � �������� �����
  // select - �������� ������� ������
  // list   - ����� ����� �����, ���������� � 1,
  // ���� ����� -1 (0xFFFFFFFF), �� ���������������
  // ������ �� ���� ������ �����;
  // check  - ����������� ����� (0 - ��� �������, != 0 - ����)

_MAPIMP  void _MAPAPI mapSelectList(HSELECT select, long int list,
                             long int check);


  // ��������� �������� �� ������� � �������� �����
  // select - �������� ������� ������
  // list   - ����� �����
  // ���� ����� -1 (0xFFFFFFFF), �� �����������
  // ������ �� ���� ������ ����� (0 - ���-�� ����������);
  // ����������� ����� : 0 - ��� �������, != 0 - ����.

_MAPIMP  long int _MAPAPI mapCheckList(HSELECT select, long int list);


  // ���������� ������ � �������� c �������� ��������
  // (���������� �����)
  // select - �������� ������� ������
  // object - ������ ������� �����, ���������� � 1,
  // ���� ����� -1 (0xFFFFFFFF), �� ���������������
  // ������ �� ���� �������� �����;
  // check  - ����������� ������� (0 - ��� �������, != 0 - ����)

_MAPIMP  void _MAPAPI mapSelectObject(HSELECT select, long int object,
                               long int check);


  // ��������� �������� �� ������� � �������� ��������
  // (���������� �����)
  // select - �������� ������� ������
  // object - ������ �������
  // ���� ����� -1 (0xFFFFFFFF), �� �����������
  // ������ �� ���� �������� ����� (0 - ���-�� ����������);
  // ����������� ������� : 0 - ��� �������, != 0 - ����.

_MAPIMP  long int _MAPAPI mapCheckObject(HSELECT select, long int object);


  // ���������� ������ � �������� c �������� ������������
  // (0 - ��������,1 - ���������,2-��������,3-�������,
  //  4 - ��������� (����� � 2-�� �������),
  //  5 - ������ (������� �������) )
  // select - �������� ������� ������
  // local  - ��� �����������, ���������� � 0,
  // ���� ����� -1 (0xFFFFFFFF), �� ���������������
  // ������ �� ���� ������������ �����;
  // check  - ����������� ����������� (0 - ��� �������, != 0 - ����)

_MAPIMP  void _MAPAPI mapSelectLocal(HSELECT select, long int local,
                              long int check);


  // ��������� �������� �� ������� � �������� ������������
  // select - �������� ������� ������
  // local  - ��� �����������, ���������� � 0 (��������,...),
  // ���� ����� -1 (0xFFFFFFFF), �� �����������
  // ������ �� ���� ������������ ����� (0 - ���-�� ����������);
  // ����������� ����������� : 0 - ��� �������, != 0 - ����.

_MAPIMP  long int _MAPAPI mapCheckLocal(HSELECT select, long int local);


  // ���������� ������ � �������� � ��������� ��������
  // select  - �������� ������� ������
  // min,max - �������� ������� ������, ���������� � 0,
  // ���� ��� ����� ����� -1 (0xFFFFFFFF), �� ���������������
  // ������ �� ���� ������� �����;

_MAPIMP  void _MAPAPI mapSelectKey(HSELECT select,
                            unsigned long int min,
                            unsigned long int max);


  // ��������� �������� �� ������� � �������� �������
  // select - �������� ������� ������
  // key    - ����� �������,
  // ���� ����� -1 (0xFFFFFFFF), �� �����������
  // ������ �� ���� ������� ����� (0 - ���-�� ����������);
  // ����������� ������ : 0 - ��� �������, != 0 - ����.

_MAPIMP  long int _MAPAPI mapCheckKey(HSELECT select,
                               unsigned long int key);


  // ��������� ����������� ����� � ��������� ������
  // select - �������� ������� ������
  // ����� ��������� 0, ����� �������� ��� ������ ��������

_MAPIMP  unsigned long int _MAPAPI mapGetMinKey(HSELECT select);


  // ��������� ������������ ����� � ��������� ������
  // select - �������� ������� ������

_MAPIMP  unsigned long int _MAPAPI mapGetMaxKey(HSELECT select);


  // �������� ������� � ������
  // select - �������� ������� ������
  // code   - ���� ������� (1-LESS,3-MORE, ... - ��. MAPTYPE.H)
  // value  - �������� ��� �������
  // ��� ������ ���������� ����, ����� - ����� �������

_MAPIMP  long int _MAPAPI mapSelectSemanticAppend(HSELECT select,long int code,
                                           long int semcode,
                                           const char * value);

  // ������� ��� ������� �� ������ ��������
  // select - �������� ������� ������

_MAPIMP  void _MAPAPI mapSelectSemanticClear(HSELECT select);


  // ��������� ���������� ������������� ������� �� ���������
  // select - �������� ������� ������

_MAPIMP  long int _MAPAPI mapSelectSemanticCount(HSELECT select);


  // ��������� ��� ������� ��� ��������� �� ����������������� ������
  // select - �������� ������� ������
  // number - ���������������� ����� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSelectSemanticCondition(HSELECT select,
                                              long int number);

  // ��������� ��� ��������� �� ����������������� ������
  // �������� : 4 - ���.������, 9 - ��������, ...
  // select - �������� ������� ������
  // number - ���������������� ����� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSelectSemanticCode(HSELECT select,
                                         long int number);


  // ������� ������� �� ������
  // select - �������� ������� ������
  // number - ����� ������� � ������ (�� 1 �� mapSelectSemanticCount())
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSelectSemanticDelete(HSELECT select,
                                           long int number);


  // ����������/��������� ���������� ������� ��� ������ ��������
  // select - �������� ������� ������
  // code - ��� ������� :
  // 16 - CMOR : ����������� ���� �� ����,
  // 32 - CMAND : ����������� ���, ��. MAPTYPE.H

_MAPIMP  void _MAPAPI mapSelectSemanticLink(HSELECT select,
                                     long int code);

_MAPIMP  long int _MAPAPI mapGetSelectSemanticLink(HSELECT select);


  // ��������� �������� ��������� �� ����������������� ������
  // select - �������� ������� ������
  // number - ���������������� ����� ���������
  // place  - ����� ������, � ������� ������������ ���������
  // size   - ������ �������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSelectSemanticValue(HSELECT select,long int number,
                                          char * place,long int size);


  // ��������� ���������� ������������� ������� �� ���������� ��������
  // select - �������� ������� ������
  // (�����, ��������, �������, ������)

_MAPIMP  long int _MAPAPI mapSelectMeasureCount(HSELECT select);


  // ������� ��� ������ �� ������ ���������
  // select - �������� ������� ������

_MAPIMP  void _MAPAPI mapSelectMeasureClear(HSELECT select);


  // �������� ��������� � ������
  // select - �������� ������� ������
  // measurecode - ��� ��������� ������� : �����, ��������, �������, ������ (��. MAPTYPE.H)
  // condition - ���� ������� (1-CMLESS,3-CMMORE, ... - ��. MAPTYPE.H)
  // value - �������� ��������� � ������, ��� ������� - � ��. ������.
  // ���� ������ ������ condition1 � value1, � condition2 = 0,
  // ����������� ������������ �������� ���������.
  // ��� ������� ��������� ��������, ������������� ����������� condition2 � value2.
  // � ���� ������ condition1 ������ ��������� CMMOREEQ (>=),
  // condition2 - CMLESSEQ (<=) !
  // ��� ������ ���������� ����, ����� - ����� ������� � ������

_MAPIMP  long int _MAPAPI mapSelectMeasureAppend(HSELECT select, long int measurecode,
                                          long int condition1,   // ������ ������� ������(>,<,>=,...)
                                          double   value1,       // ������ ��������(� ���������, ��� ������ � ������)
                                          long int condition2,   // ������ ������� ������(>,<,>=,...)
                                          double   value2) ;     // ������ ��������(� ���������, ��� ������ � ������)


  // ��������� ���������� �� ��� ��������� �������� ��������
  // �� ����������������� ������ � ������.
  // select - �������� ������� ������
  // number - ����� ���������
  // ���������� 1 - ����������� ������������ ��������;
  //            2 - ���������� �������� ��������;
  //            0 - ��� ������.

_MAPIMP  long int _MAPAPI mapIsSelectMeasureRange(HSELECT select, long int number);


  // ����������/��������� ���������� ������� ��� ������ ���������
  // select   - �������� ������� ������
  // linkcode - ��� ������� :
  // 16 - CMOR : ����������� ���� �� ����,
  // 32 - CMAND : ����������� ��� (��. MAPTYPE.H)

_MAPIMP  void _MAPAPI mapSelectMeasureLink(HSELECT select, long int linkcode);

_MAPIMP  long int _MAPAPI mapGetSelectMeasureLink(HSELECT select);


  // ��������� ��� ��������� �� ����������������� ������
  // select - �������� ������� ������
  // number - ����� ���������
  // �������� : �������, ����� � �.�. (��. MAPTYPE.H)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSelectMeasureCode(HSELECT select, long int number);


  // ��������� �������� ��������� �� ����������������� ������ � ������
  // select - �������� ������� ������
  // number - ����� ���������
  // pvalue1,pvalue2 - ������ ��� ���������� ����������.
  // pvalue2 �����������, ���� ���������� �������� ��������
  // ���������� 1 - ���������� ���� ��������;
  //            2 - ���������� ��� ��������;
  //            0 - ��� ������.

_MAPIMP  long int _MAPAPI mapSelectMeasureValue(HSELECT select, long int number,
                                         double *pvalue1,double *pvalue2);


  // ��������� ��� ������� ��� ��������� �� ����������������� ������
  // select - �������� ������� ������
  // number - ����� ���������
  // pcondition1,pcondition2 - ������ ��� ���������� ����������.
  // ���������� 1 - ���������� ���� ��������;
  //            2 - ���������� ��� ��������;
  //            0 - ��� ������.

_MAPIMP  long int _MAPAPI mapSelectMeasureCondition(HSELECT select, long int number,
                                             long int *pcondition1,
                                             long int *pcondition2);


  // ��������� ������ ������, ����������� ��� ���������� ������� ������
  // select - �������� ������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetSelectRecordSize(HSELECT select);


  // ������������ ������ ��� ���������� ������� ������
  // select - �������� ������� ������
  // buffer - ����� ������
  // length - ����� ������,��� ���������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetSelectRecord(HSELECT select,char * buffer,
                                      long int length);


  // ��������� ������� ������ �� ������
  // select - �������� ������� ������
  // buffer - ����� ������
  // length - ����� ������ ��� ������,����������� ������ (�� ������ ������)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapPutSelectRecord(HSELECT select,char * buffer,
                                      long int length);


  // �������� ������� ������ �������� � ��������� ������� ������/�����������
  // ������ �������� �������� ����� ����� � ����� �������
  // � �����
  // select - �������� ������� ������
  // ���� ������ �������� �� ����������,���������� ����

_MAPIMP  long int _MAPAPI mapIsSample(HSELECT select);


  // ��������� ����� �������� � ������ ��� ���������� ����� �����
  // select - �������� ������� ������
  // list   - ����� �����
  // ���� ������ �������� �� ����������,���������� ����

_MAPIMP  long int _MAPAPI mapGetSampleCount(HSELECT select, long int list);


  // ��������� ���������� ����� ������� �� ������ �� ����������� ������ �
  // ���������� ����� �����
  // select - �������� ������� ������
  // list   - ����� ����� � �����
  // number - ���������� ����� ������� � ������ ��������� �������� �����
  // ���� ������ �������� �� ����������,���������� ����

_MAPIMP  long int _MAPAPI mapGetSampleByNumber(HSELECT select, long int list,
                                        long int number);


  // �������� ������ �������� � ��������� ������� ������/�����������
  // ������ �������� �������� ����� ����� � ����� �������
  // � �����
  // select - �������� ������� ������
  // ����������� ��� ������ ��������,�������� ������� �����������
  // �� ������� ����� ������

_MAPIMP  void _MAPAPI mapClearSample(HSELECT select);


  // ���������� ������� ���������� ��������� ������� �������� �
  // ��������� �� �����������, �����, ��������� � ��.
  // select - �������� ������� ������
  // complex - ������� ���������� ��������� (0/1)
  // ���������� ���������� ��������

_MAPIMP  long int _MAPAPI mapSetSampleComplex(HSELECT select, long int complex);


  // ������������� ������ ���������� �������� � ��������� ������� ������ // 02/09/04
  // select - �������� ������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapInvertSample(HSELECT select);


  // ��������� ������ �������� ����� �������� ��������, ������� ����
  // �� �����
  // select - �������� ������� ������
  // list   - ����� �����, � �������� ������� �������
  // ����� � ������ (hMap, hSite) ��������������� ��� �������� ���������
  // ��� ��� ������ ��������� � �����
  // ���������� ����� ��������, ���������� � ������ ��� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetSampleAllObjects(HSELECT select, long int list);


  // ���������� ������� ����������� ������� �� ����� ����� �����
  // � ������ ������� � �����.
  // hMap     - ������������� �������� �����,
  // listname - ��� ����� �����,
  // key - ���������� ����� ������� � �����.
  // ��� ������ ���������� ����.

_MAPIMP  long int _MAPAPI mapSelectViewSample(HMAP hMap, const char * listname,
               
                        long int key);

  // ���������� ������� ������ ������� �� ����� ����� �����
  // � ������ ������� � �����.
  // hMap     - ������������� �������� �����,
  // listname - ��� ����� �����,
  // key - ���������� ����� ������� � �����.
  // ��� ������ ���������� ����.

_MAPIMP  long int _MAPAPI mapSelectSeekSample(HMAP hMap,const char * listname,
                                       long int key);


  // ���������� ������ � ��������� ������� ��������� ����� �����.
  // select   - �������� ������� ������
  // listname - ��� ����� �����,
  // key - ���������� ����� ������� � �����.
  // ��� ������ ���������� ����.

_MAPIMP  long int _MAPAPI mapSelectSample(HSELECT select, const char * listname,
                                   long int key);


  // ���������� ������ � ��������� ������� ��������� ����� �����.
  // select - �������� ������� ������
  // list   - ����� ����� �����,
  // key    - ���������� ����� ������� � �����.
  // ��� ������ ���������� ����.

_MAPIMP  long int _MAPAPI mapSelectSampleByList(HSELECT select, long int list,
                                         long int key);


  // ���������� ������ � ��������� ������� ��������� ����� �����.
  // select - �������� ������� ������
  // list   - ����� ����� �����,
  // number - ����� ������� � �����.
  // � ��������� ������� ������ ������ ���� ����������� �����.
  // ��� ������ ���������� ����.

_MAPIMP  long int _MAPAPI mapSelectSampleByNumber(HSELECT select, long int list,
                                            long int number);


  // ��������� ������ � ��������� ������� ��������� ����� �����
  // select   - �������� ������� ������
  // listname - ��� ����� �����
  // key      - ���������� ����� ������� � �����
  // � ��������� ������� ������ ������ ���� ����������� �����.
  // ��� ������ ���������� ����.

_MAPIMP  long int _MAPAPI mapUnselectSample(HSELECT select, const char * listname,
                                     long int key);


  // ��������� ������ � ��������� ������� ��������� ����� �����.
  // select - �������� ������� ������
  // list   - ����� ����� �����,
  // key    - ���������� ����� ������� � �����
  // � ��������� ������� ������ ������ ���� ����������� �����.
  // ��� ������ ���������� ����.

_MAPIMP  long int _MAPAPI mapUnselectSampleByList(HSELECT select, long int list,
                                           long int key);


  // ��������� ������ � ��������� ������� ��������� ����� �����.
  // select - �������� ������� ������
  // list   - ����� ����� �����,
  // number - ����� ������� � �����.
  // � ��������� ������� ������ ������ ���� ����������� �����.
  // ��� ������ ���������� ����.

_MAPIMP  long int _MAPAPI mapUnselectSampleByNumber(HSELECT select, long int list,
                                             long int number);


  // ���������� ��������� ������ �������� �� �������.
  // hMap     - ������������� �������� �����,
  // object   - ������-������� ������
  // distance - ���������� ������ � ������
  // ������,����������� �������� ������ :
  // filter  - ���������/�� ���������(1/0) ������ ��������
  //           (��������� ������� ������ ���� ����������� �������
  //           � ��������� ������)
  // inside  - ������� ������ �������� �� ������� :
  //           1 - ������ �������, 2 - ������� ������ �������,
  //           0 - �� ����������.
  // visible - � ������/��� �����(1/0) ��������� �������� �� �����
  // listname - ��� ����� ������. listname = 0,���� ���������������
  //            ����� �� ���� ������.
  // action   - ������� ������ �������� :
  //            0 - ���������������� ����� �� ���� ������� ��������,
  //            1 - ��������������� ����� ���� �������� (��������
  //            ���� ���������� ���������� WM_PROGRESSBAR - maptype.h),
  //            �������� ������������ ������ ���������� ��������;
#ifdef __cplusplus
_MAPIMP  long int _MAPAPI mapSelectArea(HMAP hMap, HOBJ object,
                                 double distance = 0.0,
                                 long int filter = 0,
                                 long int inside = 1,
                                 long int visible = 0,
                                 const char * listname = 0,
                                 long int action = 0);
#else
_MAPIMP  long int _MAPAPI mapSelectArea(HMAP hMap, HOBJ object,
                                 double distance,
                                 long int filter,
                                 long int inside,
                                 long int visible,
                                 const char * listname,
                                 long int action);
#endif


  // ���������� ��������� ������ �������� �� �������.
  // hMap     - ������������� �������� �����,
  // object   - ������-������� ������
  // distance - ���������� ������ � ������
  // nmap     - ����� ����� ������; ������������� ������� ������
  //            �� ������.���� nmap=-1,����� �� ���� ������
  // ������,����������� �������� ������ :
  // filter  - ���������/�� ���������(1/0) ������ ��������
  //           (��������� ������� ������ ���� ����������� �������
  //           � ��������� ������)
  // inside  - ������� ������ �������� �� ������� :
  //           1 - ������ �������, 2 - ������� ������ �������,
  //           0 - �� ����������.
  // visible - � ������/��� �����(1/0) ��������� �������� �� �����
  // action   - ������� ������ �������� :
  //            0 - ���������������� ����� �� ���� ������� ��������,
  //            1 - ��������������� ����� ���� �������� (��������
  //            ���� ���������� ���������� WM_PROGRESSBAR - maptype.h),
  //            �������� ������������ ������ ���������� ��������;

_MAPIMP  int _MAPAPI  mapSelectAreaEx(HMAP hMap, HOBJ object,
                             double distance, long int filter,
                             long int inside, long int visible,
                             long int action, long int nmap);


  // �������� ��������� ������ �������� �� �������
  // hMap     - ������������� �������� �����

_MAPIMP  void _MAPAPI mapUnselectArea(HMAP hMap);


  // ���������� � ��������� ��������� ������ �������� �� �������.
  // hselect - �������� ������ ��'�����
  // object - ������-������� ������
  // distance - ���������� ������ � ������
  // ������,����������� �������� ������ :
  // filter  - ���������/�� ���������(1/0) ������ ��������
  //           (��������� ������� ������ ���� ����������� �������
  //           � ��������� ������)
  // inside  - ������� ������ �������� �� ������� :
  //           1 - ������ �������, 2 - ������� ������ �������,
  //           0 - �� ����������.
  // visible - � ������/��� �����(1/0) ��������� �������� �� �����
  // action   - ������� ������ �������� :
  //            0 - ���������������� ����� �� ���� ������� ��������,
  //            1 - ��������������� ����� ���� �������� (��������
  //            ���� ���������� ���������� WM_PROGRESSBAR - maptype.h),
  //            �������� ������������ ������ ���������� ��������;
#ifdef __cplusplus
_MAPIMP  long int _MAPAPI mapSelectSeekArea(HSELECT hselect, HOBJ object,
                                     double distance = 0.0,
                                     long int filter = 0,
                                     long int inside = 1,
                                     long int visible = 0,
                                     long int action = 0);
#else
_MAPIMP  long int _MAPAPI mapSelectSeekArea(HSELECT hselect, HOBJ object,
                                     double distance,
                                     long int filter,
                                     long int inside,
                                     long int visible,
                                     long int action);
#endif


  // �������� � ��������� ��������� ������ �������� �� �������
  // hselect - �������� ������ ��������

_MAPIMP  void _MAPAPI mapUnselectSeekArea(HSELECT hselect);


  // ������������� � ��������� ������ �������������� ������ �����
  // ��� ������ ���������� ����
  // hMap     - ������������� �������� �����,
  // (������������ ��� �������������� ����� ��� ���������� �� ������ �����
  // ��������� ��������)                                      // 24/06/02

_MAPIMP  long int _MAPAPI mapFreezeMapContents(HMAP hMap);


  // �������� � ��������� ������ ������ � �������������� ������� �����
  // hMap     - ������������� �������� �����,
  // ��� ������ ���������� ����                               // 24/06/02

_MAPIMP  long int _MAPAPI mapDefreezeMapContents(HMAP hMap);



 /*********************************************************
 *                                                        *
 *      ������� ������ �� ������� ��������                *
 *                                                        *
 *********************************************************/

  // ����� ����� ������� ����������, ��������� � ��������
  // info    - ������������� ������� � ������
  // point   - ���������� ����� � �������������
  //           ������� ��������� , � ������ �� ���������
  // subject - ���������������� ����� ����������
  //           (0 - ������, 1 - ������ ��������� � �.�.,
  //           ���� ����� -1  - ����� �� ���� �������)
  // ��� ����������� ������ ���������� ��� ������ �� ���� �������
  // ����������� mapGetCurrentSubject()
  // ���������� ����� ����� (����� ������ ����� ����� 1)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSeekNearPoint(HOBJ info,
                                    DOUBLEPOINT * point,
                                    long int subject);


  // ����� ����� �� �������� ������� � �����������,
  // ��������� � ��������
  // hMap    - ������������� �������� �����,
  // info    - ������������� ������� � ������
  // pointin - ���������� ����� � �������������
  //           ������� ��������� , � ������ �� ���������
  // ���������� ����� ����� ������� �� ������� �����������
  // ����� �� ������� ��� ���� ��� ������
  // ���������� ����� (� ������) ���������� �� ������ pointout

_MAPIMP  long int _MAPAPI mapSeekNearVirtualPoint(HMAP hMap, HOBJ info,
                                         DOUBLEPOINT * pointin,
                                         DOUBLEPOINT * pointout);


  // ����� ����� �� ������� ����������,
  // ��������� � ��������
  // ���������� ����� pointin ������ � �������������
  // ������� ��������� , � ������ �� ���������
  // hMap    - ������������� �������� �����,
  // info    - ������������� ������� � ������
  // subject - ���������������� ����� ����������
  // ( 0 - ������, 1 - ������ ��������� � �.�.)
  // ���������� ����� ����� ������� �� ������� �����������
  // ����� �� ������� ��� ���� ��� ������
  // ���������� ����� (� ������) ���������� �� ������ pointout

_MAPIMP  long int _MAPAPI mapSeekNearVirtualPointSubject(HMAP hMap,
                                  HOBJ obj,long int subject,
                                  DOUBLEPOINT * pointin,
                                  DOUBLEPOINT * pointout);


  // ��������� ����� �������� ���������� (����� ������)
  // hObj - ������������� ������� � ������
  // ��� ������ ���������� ����, ���� ������� �����������
  // �������� ��� ������ - ���� ���������� ����

_MAPIMP  long int _MAPAPI mapGetCurrentSubject(HOBJ hobj);


  // ����������� ��������� �����, ������� �� ��������
  // ���������� (�� ���������) �� �������� �����
  // info   - ������������� ������� � ������
  // number - ����� ��������� �����
  // distance - ����������
  // ���� distance > = 0 - ����� �� ����������� ����������
  //               <   0 - ����� ������ ����������� ����������
  // point - ���������� �������� �����
  //         (� ������������� ������� � ������ �� ���������)
  // subject - ����� ����������
  // ���������� ����� �����, �� ������� ��������� ���
  // c ������� ���������
  // ���� ����� ��������� - ���������� ������������� ����� �����
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSeekVirtualPointByDistance(HOBJ info,
                                    long int number, double distance,
                                    DOUBLEPOINT *point, long int subject);



 /*******************************************************************
 *     ������� ����������� ��'����� ����������� �����               *
 *                                                                  *
 * ����������� ���� ��������, �.�. ���������� ����� ����� ��������, *
 * ���� �� ������� (������ ������ �����) - �����(�� �������� �����) *
 * ������ (������ ������ �����) - ������, ������� �����.            *
 * ������ ��� ��������� ��� �������� �������� !!!                   *
 ********************************************************************/

 // *********************************************************
 //
 // ����� �������:
 // =============
 // HCROSS hCross = mapCreateObjectsCross(info1,info2,method,precision)
 // if (hCross)
 //    {
 //    while(mapGetNextCross(hCross,info))
 //         {
 //         ...
 //         }
 //    mapFreeObjectsCross(hCross);
 //    }
 //**********************************************************

 // ����������� ���� ��������, �.�. ���������� ����� ����� ��������,
 // ���� �� ������� (������ ������ �����) - �����(�� �������� �����)
 // ������ (������ ������ �����) - ������, ������� �����.
 //
 // �������� ������ �����������
 // ������ ��� ��������� ��� �������� �������� !!!
 // info1 - ������ ������ ����� - ����� (������������ ��������� ������, ���������� �� �����������)
 // info2 - ������ ������ ����� (��������� ������ � ������������)
 // ���
 // info1 - ������ ������ ����� - ����� (������������ ��������� ������ � ������������)
 // info2 - ������ ������ ����� (�������� ������ � ������������)      // 09/08/04
 // ����������� ������������ ��������� �������� � ������������ - mapCreateObjectsCrossSquare(...) 
 // method - ��� �������������� ��������
 //          LOCAL_SQUARE - ���������, LOCAL_LINE - ��������
 //          ��� �������������� �������� ������� �� ����
 //          ������� �������:
 //          - ���� ������ ������ �����������, �� ��� ������ LOCAL_LINE,
 //          - ���� ������ ������ ���������, �� ��� ����� ���� LOCAL_LINE ��� LOCAL_SQUARE.
 // ��� ���������� �������� method � ����� �������� ���������� (FLAGINSIDEOBJECTS = 32
 // ��. maptype.h) � ����� ����������� ����� ��������� �������, ������� ��������� ������
 // � ������ - �����  (����. LOCAL_SQUARE | FLAGINSIDEOBJECTS)     //24/08/04
 // precision - �������� ��� ����������� (� ������)
 // ���������� ��������� �� ����� �����������
 // ��� ������ ���������� 0


_MAPIMP HCROSS _MAPAPI mapCreateObjectsCross(HOBJ info1, HOBJ info2,
                                      long int method,
                                      double precision);

 // ����������� ���� ��������
 // ������������ ������ �����������

_MAPIMP void _MAPAPI mapFreeObjectsCross(HCROSS hCross);

 // ����������� ���� ��������
 // ��������� ������
 // info - ���������
 // ��� ������ ���������� 0

_MAPIMP HOBJ _MAPAPI mapGetNextCross(HCROSS hCross, HOBJ info);

 // ������ �� ����������� ���� ��������
 // ������ ��� ��������� ��� �������� �������� !!!
 // info1 - ������ ������ �����
 // info2 - ������ ������ �����
 // ���� ������� ������������, ���������� 1
 // ��� ������ ��� �������� ���� �������� ���������� 0

_MAPIMP long int _MAPAPI mapGetObjectsCross(HOBJ info1, HOBJ info2);


 // �����������(������) ���� ��������
 // ������ ��� ��������� ��� �������� �������� !!!
 // �� ����������� ������� ��������� � ����������� ������� !!!
 // info1 - ������ ������ �����
 // info2 - ������ ������ �����
 // info -  ���������
 // method - ��� ��������������� �������
 //          LOCAL_SQUARE - ���������
 //          (�� ����� ������ ��� ��������� ��� �������� ��������� �������),
 //          LOCAL_LINE - ��������
 //          (�� ����� ��� ��������� ��� �������� ��������� �������,
 //           ��� ��� ����������� �������)
 // precision - ������ ��� ����������� (� ������)

 // ���������� ��������� �� �������������� ������ (info)
 // ��� ������ ���������� 0

_MAPIMP HOBJ _MAPAPI mapGetObjectsUnion(HOBJ info1, HOBJ info2,  HOBJ info,
                                 long int method, double precision);



 /*************************************************************
 *     ������� ������������ ��'����� ����������� �����        *
 *                                                            *
 * ������������ ���� ��������, �.�. ���������� ������� �����  *
 * ��������� �������, ������� ��������� � ������� ������� �   *
 * ����� � ��� ����� ����� �������.                           *
 * ������ ��� ��������� ��� �������� �������� !!!             * 
 **************************************************************/

 // *********************************************************
 // ����� �������:
 // =============
 // HCROSS hCross = mapCreateObjectsConsent(info1,info2,method,precision)
 // if (hCross)
 //    {
 //    while(mapGetNextConsent(hCross,info))
 //         {
 //         ...
 //         }
 //    mapFreeObjectsConsent(hCross);
 //    }
 // **********************************************************

 // ������������ ���� ��������, �.�. ���������� ������� �����
 // ��������� �������, ������� ��������� � ������� ������� �
 // ����� � ��� ����� ����� �������.

 // �������� ������ ������������
 // ������ ��� ��������� ��� �������� �������� !!!
 // info1 - ������ ������ �����, �� �������� �������������
 //         ������� ������ ������� �������
 //         (��� ������������ ��������� ������ ��� �����������)
 // info2 - ������ ������ �����, � �������� ����� ����� �������
 //         �����, ����������� � ������� ������� � �������� � ���
 //         ����� ����� ������� (��� ������������ ��������
 //         ��� ��������� ������ � ������������)
 // method - ��� �������������� ��������
 //          LOCAL_SQUARE - ���������, LOCAL_LINE - ��������
 //          ��� �������������� �������� ������� �� ����
 //          ������� �������:
 //          - ���� ������ ������ �����������, �� ��� ������ LOCAL_LINE,
 //          - ���� ������ ������ ���������, �� ��� ����� ���� LOCAL_LINE ��� LOCAL_SQUARE.
 // precision - �������� ��� ����������� (� ������)
 // ���������� ��������� �� ����� ������������
 // ��� ������ ���������� 0


_MAPIMP HCROSS _MAPAPI mapCreateObjectsConsent(HOBJ info1, HOBJ info2,
                                        long int method,
                                        double precision);

 // ������������ ���� ��������
 // ������������ ������ ������������
 // hCross - ��������� �� ����� ������������

_MAPIMP void _MAPAPI mapFreeObjectsConsent(HCROSS hCross);


 // ������������ ���� ��������
 // ��������� ������
 // hCross - ��������� �� ����� ������������
 // info   - ���������
 // ��� ������ ���������� 0

_MAPIMP HOBJ _MAPAPI mapGetNextConsent(HCROSS hCross, HOBJ info);




 /****************************************************************
 *  ������� ������� ����� ����������� ��'����� ����������� ����� *
 *                  �������������� ��� �����'���� !!!            *
 *****************************************************************/

 // **********************************************************
 // ����� �������:
 // =============
 // HCROSS hCross = mapCreateObjectCrossPoints(info1,info2)
 // CROSSPOINT point;
 // if (hCross)
 //    {
 //    int count = mapGetCrossCount(hCross);
 //    for(int i = 1; i <= count; i++)
 //         {
 //         mapGetCrossPoint(hCross,i,(HPOINT)&point);
 //         ...
 //         }
 //    mapFreeCrossPoints(hCross);
 //    }
 // **********************************************************

 // ���������� ����� ����������� ���� ��������
 // �������� ������ ����� �����������
 // info1 - ������ ������ ����� ( ��������,��������� )
 // info2 - ������ ������ ����� ( ��������,��������� )
 // precision - �������� ��� ����������� (� ������)
 // ���������� ��������� �� ����� �����������
 // ��� ������ ���������� 0

_MAPIMP HCROSS _MAPAPI mapCreateObjectCrossPointsEx(HOBJ info1, HOBJ info2,
                                             double precision);


 // ���������� ����� ����������� ���� ��������
 // ������ ��� ��������� ��� �������� �������� !!!
 // �������� ������ ����� �����������
 // info1 - ������ ������ �����
 // info2 - ������ ������ ����� 
 // ���������� ��������� �� ����� �����������
 // ��� ������ ���������� 0

_MAPIMP HCROSS _MAPAPI mapCreateObjectCrossPoints(HOBJ info1, HOBJ info2);


 // ���������� ����� ����������� ���� ��������
 // ��������� ���������� ����� �����������
 // hCross - ��������� �� ����� ������������
 // ��� ������ ���������� 0

_MAPIMP int _MAPAPI mapGetCrossCount(HCROSS hCross);


 // ���������� ����� ����������� ���� ��������
 // ��������� �����
 // hCross - ��������� �� ����� ������������
 // number - ����� ����� (� 1)
 // point  - ����� (���������� � ������ �� ���������)
 // ��� ������ ���������� 0

_MAPIMP int _MAPAPI
     mapGetCrossPoint(HCROSS hCross,long int number,HPOINT point);


 // ���������� ����� ����������� ���� ��������
 // ������������ ������
 // hCross - ��������� �� ����� ������������

_MAPIMP void _MAPAPI mapFreeCrossPoints(HCROSS hCross);




 /**********************************************************
 *  ������� ������� ����� ����������� ��'�����/�����'����� *
 *                    ����������� �����                    *
 *                  �����'���� �� �������������� !!!       *
 **********************************************************/

 // *********************************************************
 // ����� �������:
 // =============
 // HCROSS hCross = mapCreateSubjectCrossPoints(info1,info2,
 //                                             subject1, subject2)
 // CROSSPOINT point;
 // if (hCross)
 //    {
 //    int count = mapGetCrossCount(hCross);
 //    for(int i = 1; i <= count; i++)
 //         {
 //         mapGetCrossPoint(hCross,i,(HPOINT)&point);
 //         ...
 //         }
 //    mapFreeCrossPoints(hCross);
 //    }
 //**********************************************************

 // ���������� ����� ����������� ���� ��������/�����������
 // �������� ������ ����� �����������
 // info1 - ������ ������ ����� ( ������������ )
 // info2 - ������ ������ ����� ( ������������ )
 // subject1 - ����� ���������� info1
 // subject2 - ����� ���������� info2
 // precision - �������� ��� ����������� (� ������)
 // ���������� ��������� �� ����� �����������
 // ��� ������ ���������� 0

_MAPIMP HCROSS _MAPAPI
        mapCreateSubjectCrossPointsEx(HOBJ info1, HOBJ info2,
                                      long int subject1,long int subject2,
                                      double precision);
                                      
 // ���������� ����� ����������� ���� ��������/�����������
 // �������� ������ ����� �����������
 // info1 - ������ ������ ����� ( ������������ )
 // info2 - ������ ������ ����� ( ������������ )
 // subject1 - ����� ���������� info1
 // subject2 - ����� ���������� info2
 // ���������� ��������� �� ����� �����������
 // ��� ������ ���������� 0

_MAPIMP HCROSS _MAPAPI
        mapCreateSubjectCrossPoints(HOBJ info1, HOBJ info2,
                                    long int subject1, long int subject2);


 //  �������� ����� ����������� �������� � �������
 //  ��� ������ ��� ���������� ����������� ���������� 0
 //  info1 - ������ ������ �����
 //  info2 - ������ ������ �����
 //  30/03/00

_MAPIMP int _MAPAPI mapInsertPointCross(HOBJ info1, HOBJ info2);


 //  ���������� ������������������ ���� ��������
 //  (������ ��� ��������� ��������)
 //  info1 - ������ ������ �����
 //  info2 - ������ ������ �����
 //  ����������: 1 - ������ ������ ������ �������,
 //              2 - ������ ������ ������ �������,
 //              3 - ������� ������������,
 //              4 - ������� �� ������������
 //  ��� ������ ���������� 0
 //  20/04/00

_MAPIMP int _MAPAPI mapCheckInsideObject(HOBJ info1, HOBJ info2);


 //  ���������� ������������������ ���� �������� (������� ����������)
 //  (������ ��� ��������� ��������)
 //  info1 - ������ ������ �����
 //  info2 - ������ ������ �����
 //  ����������: 1 - ������ ������ ������ �������
 //                 (������ ������ �.�. ����������� ���������),
 //            - 1 - ������ ������ ������ ���������� ������� �������
 //                 (������ ������ �.�. ����������� ���������),
 //              2 - ������ ������ ������ �������
 //                 (������ ������ �.�. ����������� ���������),
 //            - 2 - ������ ������ ������ ���������� ������� �������
 //                 (������ ������ �.�. ����������� ���������),
 //              3 - ������� ������������,
 //              4 - ������� �� ������������
 //  ��� ������ ���������� 0
 //  09/06/01

_MAPIMP int _MAPAPI mapCheckInsideObjectEx(HOBJ info1, HOBJ info2);


 //  ���������� ������������������ ������� � �����
 //  (������ ��� ��������� ��������)
 //  info    - ������������� �������,
 //  subject - ����� �������(0) ��� ����������,
 //  point   - ���������� ����������� ����� � ������.
 //  ����������: 1 - ����� ������ �������(����������),
 //              2 - ����� �� ��������� �������(����������),
 //              3 - ����� ��������� � ������ �������,
 //              4 - ����� ����� �� �������.
 //  ��� ������ ���������� 0

_MAPIMP int _MAPAPI mapCheckInsidePoint(HOBJ info, int subject,
                                 DOUBLEPOINT * point);


 //  ���������� ������������������ ������� � �������
 //  info - ������������� �������,
 //  area - ������� (����������� �������� � ��� �����������,
 //                  �.�. ���������� ������� �� ����������� )
 //  precision - �������� (� ������)
 //  ����������: 1 - ������� ������ �������
 //                 (� ���� ������ ������ �.�. ����������� ���������),
 //              2 - ������ ������ �������
 //              3 - ������� � ������ ������������,
 //              4 - ������� � ������ �� ������������
 //              5 - ������ �������� ������� � ����� ������ ���
 //              6 - ������ �������� ������� � ����� �������
 //  ��� ������ ���������� 0
 //  21/02/01

#ifdef __cplusplus
_MAPIMP int _MAPAPI mapCheckOverlap(HOBJ area, HOBJ info, double precision = 0);
#else
_MAPIMP int _MAPAPI mapCheckOverlap(HOBJ area, HOBJ info, double precision);
#endif

#ifdef __cplusplus


 // ����� ����������� ���� ��������
 // xy1,xy2 - ������ �������,
 // xy3,xy4 - ������ �������
 // point1,point2  - ����� �����������
 // precision - �������� (� ������)
 // ������� : 1 - ���� ����� �����������,
 //           2 - ������� xy1,xy2 �����  �� ������� xy3,xy4
 // ��� ���������� ����� ����������� ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapCrossCutData(DOUBLEPOINT *xy1, DOUBLEPOINT *xy2,
                                  DOUBLEPOINT *xy3, DOUBLEPOINT *xy4,
                                  DOUBLEPOINT *point1, DOUBLEPOINT *point2,
                                  double precision = DELTANULL);

 // ----------------------------------------------------------
 // ����������� ������� � ������� ������� / ����������
 // xy1, xy2 - ���������� �������
 // data - ������� �������/����������
 // subject - ����� �������/����������
 // ( 0 - ������, 1 - ������ ��������� � �.�.)
 // first - ����� ������ ����� �������
 // last  - ����� ��������� ����� �������
 // ���������� ��� ��������� NUMBERPOINT, ����������
 // ����� ����� �������, ����� �������
 // ��������� ����� ����������� �
 // ��������� DOUBLEPOINT - ���������� ����� �����������
 // ��� ��������� ����������� ���� ������� xy1,xy2 �����
 // �� ������� �������
 // ��� ���������� ����� ����������� ��� ������ ���������� ����
 // ----------------------------------------------------------
_MAPIMP long int _MAPAPI mapCrossCutAndSubject(HOBJ info,            // 31/01/06
                             DOUBLEPOINT * xy1, DOUBLEPOINT * xy2,
                             int first, int last,
                             NUMBERPOINT * point1,
                             NUMBERPOINT * point2, int subject,
                             double precision);

 // ��������� ����� ������������ �������
 // point     - ���������� 
 // xy1,xy2   - ���������� ������ �������
 // precision - ��������
 // ���������� POINTPOSITION (PS_FIRST, PS_LEFT... - maptype.h)
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetPointPosition(DOUBLEPOINT *point,
                                          DOUBLEPOINT *xy1,
                                          DOUBLEPOINT *xy2,
                                          double precision = DELTANULL);


 // ����������� ���� ����� �� �������������� �� ������� (point1-point2)
 // �� ���������� (+/-) distance �� ������������ ����� point (�� ��������� point1)
 // pointout1, pointout2 - ���������� ��������� �����
 // point1,point2        - ���������� ������ �������
 // point                - ������������ �����, �� ������� ������������� ������
 // distance             - ��������� �� ����� point
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSeekPointNormalLine(DOUBLEPOINT *point1,
                                         DOUBLEPOINT *point2,
                                         DOUBLEPOINT *pointout1,
                                         DOUBLEPOINT *pointout2,
                                         double distance, DOUBLEPOINT * point = 0);
#endif




  /**********************************************************
  *                                                         *
  *    ������� ���������� ���������� ��'���� �� �����       *
  *                                                         *
  **********************************************************/

 // *********************************************************
 // ����� �������:
 // =============
 // HCROSS hCross = mapCreateObjectCutByLine(info1,info2,method,precision)
 // if (hCross)
 //   {
 //     while(mapGetNextCut(hCross,info))
 //     {
 //        ...
 //     }
 //     mapFreeObjectsCut(hCross);
 //   }
 //**********************************************************

 // ���������� ���������� ������� �� �����
 // �������� ������ ����������
 // info1 - ����� ��� �����������, �� ������� �����
 // info2 - ��������� ������, ������� ����� (������������,c ������������)
 // method - ����� ������� ��������:
 //          LOCAL_LINE - ��������,
 //          LOCAL_SQUARE - ���������
 // precision - �������� ��� ����������� (� ������)
 // ���������� ��������� �� ����� ����������
 // ��� ������ ���������� 0

_MAPIMP HCROSS _MAPAPI mapCreateObjectCutByLine(HOBJ info1, HOBJ info2,
                                         long int method,
                                         double precision);


 // ���������� ���������� ������� �� �����
 // ������������ ������ ����������
 // hCross - ��������� �� ����� ����������

_MAPIMP void _MAPAPI mapFreeObjectsCut(HCROSS hCross);


 // ���������� ���������� ������� �� �����
 // ��������� ������
 // hCross - ��������� �� ����� ����������
 // info   - ���������
 // ��� ������ ���������� 0

_MAPIMP HOBJ _MAPAPI mapGetNextCut(HCROSS hCross, HOBJ info);




  /*********************************************************************
  *                                                                    *
  *     ������� ����������� ��������� ��'����� ����������� �����       *
  *                                                                    *
  * ����������� ���� ��������� ��������(� ������ ���� �����������),    *
  * �.�. ���������� �� ����� �����                                     *
  * ���� �� ������� (������ ������ �����) - �����(�� �������� �����)   *
  * ������ (������ ������ �����) - ������, ������� �����.              *
  * ������ ��� ��������� �������� !!!                                  *
  **********************************************************************/

 // *********************************************************
 // ����� �������:
 // =============
 // HCROSS hCross = mapCreateObjectsCrossSquare(info1,info2,method,precision)
 // if (hCross)
 //   {
 //    while(mapGetNextCross(hCross,info))
 //    {
 //      ...
 //    }
 //    mapFreeObjectsCross(hCross);
 //   }
 //**********************************************************

 // �������� ������ ����������� ���� ��������� ��������(� ������ ���� �����������)
 // ������ ��� ��������� �������� !!!
 // info1 - ������ ������ ����� - ����� (������������ ��������� ������ � ������������)
 // info2 - ������ ������ ����� (������������ ��������� ������ � ������������)
 // precision - �������� ��� ����������� (� ������)
 // ���������� ��������� �� ����� �����������
 // ��� ������ ���������� 0

_MAPIMP HCROSS _MAPAPI mapCreateObjectsCrossSquare(HOBJ info1, HOBJ info2,
                                            double precision);


 // ���������� ������ ��� �������� ���������� �����  13/01/03
 // info - ������ �����
 // precision - ������������ ������ ��� 0 (� ������)
 // ���������� �������� ������

_MAPIMP double _MAPAPI mapSetPrecision(HOBJ info, double precision);




  /*******************************************************************
  *                                                                  *
  *     ������� ��� ������ ��������, ������������ �� �������������   *
  *                      ��������������                              *
  *                                                                  *
  *  ���� ��������:                                                  *
  *                                                                  *
  *  32801 - ������� �������, �������� ������ �� ����������� ������; *
  *  32802 - ������� �������, �� ������� ������� ������ �� ��������  *
  *          �������;                                                *
  *  32803 - ������� �������, ��������� � ������ ������������        *
  *          ��������.                                               *
  *                                                                  *
  *    ��������� ��������� �������� ���������� ����� ������, ������� *
  * ����������� ������������� �� ������ �������� ������� ��� ������� *
  * ������� � ������ ������������ ��������.                          *
  *                                                                  *
  ********************************************************************/

 // *********************************************************
 // ����� �������:
 // =============
 // HOBJSET hObjSet = mapCreateObjectSet()
 // if (hObjSet)
 //   {
 //     ... ������� ������
 //     mapFreeObjectSet(hObjSet);
 //   }
 //**********************************************************

#ifdef __cplusplus          // �� ���������� �� �

 // �������� ������ ������ ��������, ������������ �� �������������
 // ��������������
 // ��� ������ ���������� 0

_MAPIMP HOBJSET _MAPAPI mapCreateObjectSet();


 // ������������ ������ ������ ��������, ������������ �� �������������
 // ��������������
 // hobjset - ��������� �� ������ ��������

_MAPIMP void _MAPAPI mapFreeObjectSet(HOBJSET hobjset);


 // ���������� ������ �� �������� �����
 // �� ������������ � ������� ��������� ���������
 // hobjset - ��������� �� ������ ��������
 // info    - ������������� ������� �����
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapBuildObjectSet(HOBJSET hobjset, HOBJ info);


 // ���������� ������ �� �������� �����
 // �� ������������� ���� ������������ � ������� ��������� ���������
 // hobjset - ��������� �� ������ ��������
 // info    - ������������� ������� �����
 // type    - ��� ������������� �������������� ��� ������ � info
 //           GROUPLEADER, GROUPSLAVE, GROUPPARTNER
 // ���� type = 0 - ���� ������ ���������� ��������� ���������
 // ( ������� mapBuildObjectSet );
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapBuildObjectSetByType(HOBJSET hobjset, HOBJ info, int type);


 // ��������� �������� ������ �� �������� ������
 // hobjset - ��������� �� ������ ��������
 // hselect - ������� ������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapBuildSelect(HOBJSET hobjset, HSELECT hselect);


 // ��������� ���������� �������� � ������
 // hobjset - ��������� �� ������ ��������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapObjectSetCount(HOBJSET hobjset);


 // ��������� ������ �� ������ �� ������ (������� � 1)
 // ������ HOBJ �� ����� ��������� !!! 
 // hobjset - ��������� �� ������ ��������
 // number  - ����� ������� �� ������
 // ��� ������ ���������� 0

_MAPIMP HOBJ _MAPAPI mapObjectSetObject(HOBJSET hobjset, long int number);


 // ��������� �������� �������� ������
 // hobjset - ��������� �� ������ ��������
 // frame   - ���������� (� ������) ������������� ������� ��������� ������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapObjectSetFramePlane(HOBJSET hobjset, DFRAME *frame);


 // ��������� ������� ������ � ������ (��������� ��������� 32801)
 // hobjset - ��������� �� ������ ��������
 // number - ���������� ����� ������� � ����� (�� ����� �������� � ������)
 // ���� number = 0, ����������� ������ ���������� ������ � ������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapObjectSetNominateLeader(HOBJSET hobjset, int number);


 // ������� ������ �� ������ �� ����������� ������ (� 1)
 // ��������� ���������� �� ���������
 // ���� ������ ������� � ������ - ��������� ��� ������
 // hobjset - ��������� �� ������ ��������
 // number - ���������� ����� ������� 
 // save - ��������� ��������� � ����
 //  =  0 - �� ���������, 1 - ���������
 // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapObjectSetClearObject(HOBJSET hobjset, long int number,
                                          long int save);


 // ������� ��� ������� �� ������
 // hobjset - ��������� �� ������ ��������
 // save    - ��������� ��������� � ����
 //           =  0 - �� ���������, 1 - ���������

_MAPIMP void _MAPAPI mapObjectSetClear(HOBJSET hobjset, long int save);


 // ������ �������� ���������� ������� (�� ���������)
 // groupnumber - ����������, ���� ���������� ����� ������
 // (���� �� �����) ��� 0
 // hobjset - ��������� �� ������ ��������
 // hobj    - ������������� �������
 // ���������� ��� ��������� ��������� (GROUPLEADER,GROUPSLAVE,GROUPPARTNER) ��� 0

_MAPIMP long int _MAPAPI mapObjectSetIsGroup(HOBJSET hobjset, HOBJ hobj,
                                      long int *groupnumber);


 // ��������� ������� ��������� ��������� ������� ���� � �������
 // hobjset - ��������� �� ������ ��������
 // hobj    - ������������� �������
 // type -  ��� ��������� ���������
 //        GROUPLEADER, GROUPSLAVE, GROUPPARTNER
 // ���������� ����� ������ ��� 0 ��� ����������

_MAPIMP long int _MAPAPI mapObjectSetGetTypeSemn(HOBJSET hobjset, HOBJ hobj, int type);


 // ������� ��� ������� ������ � �����
 // hobjset - ��������� �� ����� ��������

_MAPIMP long int _MAPAPI mapObjectSetDelete(HOBJSET hobjset);


 // ������� ��������� ��������� �� �������
 // group - ����� ������
 // ���� group == 0, �� ������������ ����� ������ ������ hobjset
 // hobjset - ��������� �� ������ ��������
 // hobj    - ������������� �������

_MAPIMP long int _MAPAPI mapObjectSetDeleteSemantic(HOBJSET hobjset, HOBJ hobj,
                                             long int group);

 // ���������� �����
 // hobjset - ��������� �� ����� ��������
 // hmap    - ������������� �������� �����
 // hDC     - �������� ���������� �����������
 // Rect    - ������� �����������

_MAPIMP long int _MAPAPI mapPaintObjectSet(HOBJSET hobjset, HMAP hmap,
                                    HDC hDC, RECT& rect);

 // ��������� �����
 // hobjset - ��������� �� ������ ��������
 // always  - ��������� ������ ��� ������, ���� ���� ���������
 //         = 0 - ���� ���������
 //         = 1 - ������

_MAPIMP long int _MAPAPI mapObjectSetSave(HOBJSET hobjset, long int always);


 // ������� ������ �� ������ �� ��� ������ �� ����� (� 1)
 // hobjset - ��������� �� ����� ��������
 // number  - ���������� ����� �������
 // save - ���������� � ����
 //      =  0 - �� ���������, 1 - ���������

_MAPIMP int _MAPAPI mapObjectSetRemoveNumber(HOBJSET hobjset, int number,
                                      int save);


 // �������� ������� ������ ������ (� ������������� ��������� 32801)
 // hobjset - ��������� �� ����� ��������
 // save - ���������� � ���� : = 0 - �� ���������, 1 - ���������
 // ���� hobj - ����� ��������� ������ (Key = 0) � save = 1
 //             ������� info ����� ��������, � ����� �������� � ������
 // ���� ������ hobj �������� ��������� ��������� � �������� �������
 // - ��������� � �����, �� ������� ��������� ���������
 // ���� ������ hobj �������� ��������� ��������� � �������� �����������
 // - ��������� ��������� ��������� (������� ����� ������ �� �������� ������)
 // ���������� ���������� ����� ������� ��� 0

_MAPIMP int _MAPAPI mapObjectSetAppendGeneral(HOBJSET hobjset, HOBJ hobj, int save); // 02/10/02


 // �������� ������� ������ ������ (� ������������� ��������� 32801)
 // hobjset - ��������� �� ����� ��������
 // save - ���������� � ���� : = 0 - �� ���������, 1 - ���������
 // ���� hobj - ����� ��������� ������ (Key = 0) � save = 1
 //             ������� info ����� ��������, � ����� �������� � ������
 // ���� ������ hobj �������� ��������� ��������� � �������� �������
 // - ��������� ������������ ������ � ������� �����
 // ���������� ���������� ����� ������� ��� 0

_MAPIMP int _MAPAPI mapObjectSetAppendGeneralNew(HOBJSET hobjset, HOBJ hobj, int save); // 02/10/02


 // �������� ����������� ������ ������ (� ������������� ��������� 32802)
 // hobjset - ��������� �� ����� ��������
 // save - ���������� � ���� : = 0 - �� ���������, 1 - ���������
 // ���� hobj - ����� ��������� ������ (Key = 0) � save = 1
 //             ������� info ����� ��������, � ����� �������� � ������
 // ���� ������ hobj �������� ��������� ��������� � �������� �������
 // - ��������� ��������� ��������� (������� ����� ������ �� �������� ������)
 // ���� ������ hobj �������� ��������� ��������� � �������� �����������
 // - ��������� � �����, ������� ��������� ���������
 // ���������� ���������� ����� ������� ��� 0

_MAPIMP int _MAPAPI mapObjectSetAppendSubordinate(HOBJSET hobjset, HOBJ hobj,
                                           int save);


 // �������� ����������� ������ ������ (� ������������� ��������� 32802)
 // hobjset - ��������� �� ����� ��������
 // save - ���������� � ���� : = 0 - �� ���������, 1 - ���������
 // ���� hobj - ����� ��������� ������ (Key = 0) � save = 1
 //             ������� info ����� ��������, � ����� �������� � ������
 // ���� ������ hobj �������� ��������� ��������� � �������� �����������
 // - ��������� ������������ ������ � ������� �����
 // ���������� ���������� ����� ������� ��� 0

_MAPIMP int _MAPAPI mapObjectSetAppendSubordinateNew(HOBJSET hobjset, HOBJ hobj,
                                              int save);


 // ����� ������� ������ � ������
 // hobjset - ��������� �� ����� ��������
 // group - ����� ������
 //         ��� group = 0 - ����� ������ ��������������� �� ������ hobjset
 // ������ HOBJ �� ����� ��������� !!!

_MAPIMP HOBJ _MAPAPI mapObjectSetFindGeneral(HOBJSET hobjset, long int group);


 // ���������� ������ hobjset � set
 // regime -
 //    = 1 -  �������� ��������� ������
 //           ���� ������ ������� - ������� ��������, ������� ������ ���
 //           � ������� �����
 //           ���� ������ ����������� ��� ������������ - �������� ��� � ������� �����,
 //           ������ �� set
 //    = 2 -  ���� �����
 //           ����������� ����� set � ��� ������� ���������� � ������� �����
 //    = 3 -  ������� ��������
 //           ����� ������� ������ ������ set � �������� ��� ��� �����������
 //           � ������� �����, ������ ��������
 // info - �� ������ ������� ������ set ���������������
 // ��������� ���������� � ����� hobjset
 // save - ���������� � ����
 //      =  0 - �� ���������, 1 - ���������

_MAPIMP int _MAPAPI mapObjectSetUnion(HOBJSET hobjset, HOBJSET set,
                               int regime, HOBJ info, int save);


 /*******************************************************************
 *                                                                  *
 *     ������� ��� ������� ������������� ��������������  � �����    *
 *                    �� ��������� �����                            *
 *                                                                  *
 ********************************************************************/

 // ���������� �������� �������������� � �������� �����
 // �� ������ ��������� �����.]
 // hMap - ������������� �������� ��������� �����,
 // �������������� ������� ����� ��������� - semanticCode,����� ��������
 // �������������� ����������� �� ���� �������� ��������� �����.
 // ���������� ����� (point->X,point->Y) �������� � ������ �
 // ������� ��������� ��������� �����.
 // ����������� �������� �������������� ��������� � value.
 // � ������ ������ ���������� 0
 // 06/10/05
_MAPIMP long int _MAPAPI  mapCalcCharacteristic(HMAP hMap,
                                        DOUBLEPOINT* point,
                                        long int semanticCode,
                                        double*  value);

#endif

#ifdef __cplusplus
}       // extern "C"
#endif


#endif  // SEEKAPI_H
