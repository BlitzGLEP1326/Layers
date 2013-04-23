/****** OBJAPI.H ************* Shishkova L.A.  ******** 28/01/05 ***
******* OBJAPI.H ************* Belenkov  O.V.  ******** 22/09/99 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2001              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                  FOR  WINDOWS95,98 & WINDOWS NT                  *
*                                                                  *
********************************************************************
*                                                                  *
*               �������� ������ ������� � �������                  *
*        ��������� ��� �������� �� ������ C, PASCAL, BASIC         *
*                                                                  *
********************************************************************
*                                                                  *
*                 �������������� ������� :                         *
*                                                                  *
*                                                                  *
*    // �������� ����������                                        *
*    HINSTANCE libInst = ::LoadLibrary("gisforms.dll");            *
*                                                                  *
*    // ����� �������                                              *
*    long int (WINAPI * Select)(HOBJ object, MAPDFRAME* frame,     *
*                               long int place, OBJECTFORM* form,  *
*                               TASKPARM *parm);                   *
*    (FARPROC)Select = GetProcAddress(libInst,"formSelectObject"); *
*    int res = (*Select)(object,frame,PP_PLANE,form,parm);         *
*    ...                                                           *
*                                                                  *
*    // �������� ����������                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

#ifndef OBJAPI_H
#define OBJAPI_H

#ifndef MAPTYPE_H
  #include "maptype.h"   // �������� �������� ���������� MAPAPI
#endif

typedef struct OBJECTFORM      // ��������� ����������� ���������� �� ��'����
{
  HWND        Window;          // ������������� ���� ���������
  POINT       Position;        // ��������� ������� � ����� ������ � ����������� ������        //28/11/02
  POINT       LeftTopPosition; // ���������� ������ �������� ���� ����� � �������� � ������    //28/11/02
  long int    PlaceSystem;     // ������� ������� ����������� ��������� ������� �������:
                               // 1 - � ������ �� ���������
                               // 2 - � �������� �������� ����� (���������)
                               // 3 - � �������� �������� ������� �����������
                               //     ��������� ����������� 1942�.
                               // 4 - � �������� � ������������ � ���������
                               // 5 - � �������� ...
                               // 6 - � ��������, �������, �������� ...
                               // 7 - � �������� (���������� ��������� WGS84)                    //28/01/05
                               // 8 - � �������� (���������� ��������� WGS84)
                               // 9 - � ��������, �������, �������� (���������� ��������� WGS84)
  short int   FormMode;        // ��� ���� ����������� �������
                               // 0 - ������ ����� �������� �� �������
                               // 1 - ����� �������� � ��������� �������
                               // 2 - ����� �������� � ������� �������
                               // 3 - ����� �������� � ������� ����������� �������
                               // 4 - ����� �������� � ������� ��� �������
                               // 5 - ����� �������� � ���������� ��� �������
                               // 6 - ����� �������� � ����������� ��� �������
                               // -1 - -6 ��������������� ���������� � ������������� ��������
  short int   MarkPointMode;   // ��� ���� ����������� �����
                               // ���������� ��������������� �������
                               // ������������ ��������� ������� � ������� ��������
                               // ��������� ����������� ��������� ������� ����� �������
                               // 0 - �� ����������� ��������� ������� ����� �������
                               // 1 - ����������� ��������� ������� ����� �������
                               // ������ ������������ ����
                               // 0 - ������������ ������ �����, ���������� ������
                               // 1 - ������������ ��� �����
  HMAP        Map;             // ������������� �������� ��������� �����
                               // (��������� �� TMapAccess)
}
  OBJECTFORM;

// ��������� TASKPARM ������� � maptype.h
// ���� � TASKPARM ����������� ������ ��� ����� ".hlp",
// �� ���� ���� ������ ��������� ����� � ������� 6700,
// ������� ����� ���������� ��� ������� ������� "������"

typedef long int  HCHOICEOBJECT; // ������������� ��������� ������ ������ �������
                                 // (��������� �� TChoiceObject)

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// �������� ������� ������/������ ������� ����������� �����
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C"
{

 // ��������� ����� � ��������� ������� ����� � ����� Position
 // ��������� ������ �������� ����� ���������� object
 // object - ����� ��� ���������� �������� �������
 // place - ����������� ������� ��������� (�������������
 // ���������� �� ��������������)
 // (��� LINUXAPI ������� ��������� ������ � ���������)      //12/02/03
 // frame - ������������� ������ � ������������ � place,
 // ������ ����� �������������� ������ ��������� � ������,
 // ��������� � Position ��������� OBJECTFORM
 // ��������� TASKPARM ������� � maptype.h
 // ���� ������ ������ - ������������ ��������� ��������
 // ���� ������ �� ������ (��� � ������ ����� ��� ������������
 // ����� "Cancel") - ������������ ����

 long int _export WINAPI  formSelectObject(HOBJ object, MAPDFRAME* frame,
                              long int place, OBJECTFORM* objform,
                              TASKPARM* taskparm);

 //================================================================
 // ���������� ������� ������ ������� � ������ "Create"
 // ��������� � ���� ������ ������� ����������������� ������
 // ���� �������: 1.formProcessSelectObject
 //               2.formContinueSelectObject
 //               3.formDestroySelectObject
 //================================================================
 // ��������� ����� � ��������� ������� ����� � ����� Position
 // ��������� ������ �������� ����� ���������� object
 // object - ����� ��� ���������� �������� �������
 // place - ����������� ������� ��������� (�������������
 // ���������� �� ��������������)
 // (��� LINUXAPI ������� ��������� ������ � ���������)      //12/02/03
 // frame - ������������� ������ � ������������ � place,
 // ������ ����� �������������� ������ ��������� � ������,
 // ��������� � Position ��������� OBJECTFORM
 // ��������� TASKPARM ������� � maptype.h
 // ����������:
 // 0 - ���� ������� ������ ������� �� �������
 // 1 - ���� ������� ������ ������� ������� ������

 long int _export WINAPI  formProcessSelectObject(HOBJ object, MAPDFRAME* frame,
                              long int place, OBJECTFORM* objform,
                              TASKPARM* taskparm,
                              HCHOICEOBJECT &choiceobject);

 // ����������� �������� ������ ������� � ����� �������� �����
 // ��������� ����� � ��������� ������� ����� � ����� Position
 // ��������� ������ �������� ����� ���������� object
 // object - ����� ��� ���������� �������� �������
 // place - ����������� ������� ��������� (�������������
 // ���������� �� ��������������)
 // (��� LINUXAPI ������� ��������� ������ � ���������)      //12/02/03
 // frame - ������������� ������ � ������������ � place,
 // ������ ����� �������������� ������ ��������� � ������,
 // ��������� � Position ��������� OBJECTFORM
 // ������ ������������ ����

 long int _export WINAPI  formContinueSelectObject(HOBJ object, MAPDFRAME* frame,
                              long int place, OBJECTFORM* objform,
                              HCHOICEOBJECT choiceobject);

 // ���������� ������� ������ �������

 long int _export WINAPI
      formDestroySelectObject(HCHOICEOBJECT choiceobject);

 //================================================================

 // ��������� ����� � ��������� ������� ����� � ����� Position
 // � ��������������� ��������� ������� ������� � ����� Position

 long int _export WINAPI  formCheckAndSelectObject(HOBJ object,
                              MAPDFRAME* frame, long int place,
                              OBJECTFORM* objform, TASKPARM* taskparm);

 // ����� ������� �� �������� ��������
 // select - ������� ������ ��������
 // flag   - ������� ������ ��������
 // ��� ��������� �� ����� ���������� ������� ���������� ���������
 // ������ ������������ ��������� WM_LEFTTOPPOINT :
 //  - �������� wpar�m �������� ��������� ���� (POINT*)
 //    ��� ������ ������� ��������� �������� ������ ���� ����
 //    ����� � �������� ������ ����������� (PP_PICTURE);
 //  - ������� �������� �������������� ��������� ��� ��������
 //    ���������� (WM_LEFTTOPPOINT).
 // ������������� WM_LEFTTOPPOINT ��������� � maptype.h
 // ��� ����������� ����������� ����� � ����� �����������
 // ���������� ������� ���������� ��������� ������ ������������
 // ��������� WM_MOVEDOC :
 //  - �������� wpar�m �������� ��������� ���� (POINT*)
 //    ��������� �������� ������ ���� ���� ����� � ��������
 //    ������ ����������� (PP_PICTURE), ���� ����� �����������
 //    �����������;
 //  - �������� lpar�m �������� 0 ��� ��������� ���� (POINT*)
 //    ���������� ������� � �������� ������ ����������� (PP_PICTURE);
 //  - ������� �������� �������������� ��������� ��� ��������
 //    ���������� (WM_MOVEDOC).
 // ������������� WM_MOVEDOC ��������� � maptype.h
 // ���� ������ ������ - ������������ ��������� ��������.
 // ���� ������ �� ������ - ������������ ����.

 long int _export WINAPI  formSeekObject(HOBJ object,
                              long int flag, HSELECT select,
                              OBJECTFORM* objform, TASKPARM* taskparm);

 // ����� ������� �� �������� ��������
 // � ��������������� ��������� ������� �������

 long int _export WINAPI  formCheckAndSeekObject(HOBJ object,
                              long int flag, HSELECT mapselect,
                              OBJECTFORM* objform, TASKPARM* taskparm);

 // ����� ������� ������ ������ ��� ��������� ����� ����������
 // object �������
 // ���� ����������� ������� �� ����� ��� ����� ��������� �����
 // �������� � ��������� �������
 // ���� ������ ������ - ������������ ��������� ��������
 // ���� ������ �� ������ (��� � ������ ����� ��� ������������
 // ����� "Cancel") - ������������ ����

 long int _export WINAPI  formSelectAssignObject(HOBJ object,
                              OBJECTFORM* objform, TASKPARM* taskparm);

 // ����� ������� ������ ��� �������� ��������� ������ �������
 // ������ ����� ����� ���������� object
 // ���� ����������� ������� �������� ����� �������� � ��������� �������
 // ���������� ���������� �� ������� �� �����������
 // ��������� ��������� ����� ����� �������� ������� �� "IDOK"
 // ���� ������ ������ �� "IDOK"  - ������������ ��������� ��������
 // ���� �� �� "IDOK" - ������������ ����

 long int _export WINAPI formCreateObject(HOBJ        object,
                                          OBJECTFORM* objform,
                                          TASKPARM*   taskparm);

 // ����� ������� ������ ��� �������� ������� ������ �������
 // ������ ����� ����� ���������� object
 // ���� ����������� ������� �������� ����� �������� � ������� �������
 // ���� ������ ������ �� "IDOK"  - ������������ ��������� ��������
 // ���� �� �� "IDOK" - ������������ ����

 long int _export WINAPI formInputObject(HOBJ        object,
                                         OBJECTFORM* objform,
                                         TASKPARM*   taskparm);

 #ifdef LINUXAPI                          //12/02/03
 // ����� ������� ������ (������)������ ��� ��������� ����� ����������
 // info �������
 // ���� ������ ������ - ������������ ��������� ��������
 // ���� ������ �� ������ (������������ ����� "Cancel") - ������������ ����
 long int formViewAssignObject(HOBJ object,
                               OBJECTFORM* objform, TASKPARM* taskparm);
 #endif

}       // extern "C"

#endif  // OBJAPI_H
