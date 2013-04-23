/****** RSCAPI.H *************** Vitsko     D.A. ****** 23/11/05 ***
******* RSCAPI.H *************** Belenkov   O.V. ****** 09/02/05 ***
******* RSCAPI.H *************** Panteleeva N.A. ****** 18/04/05 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*       �������� ������� ������� � ��'���� "������������� ����"    *
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
*    HRSC (WINAPI * lpfn)(HMAP,HSITE);                             *
*    (FARPROC)lpfn = GetProcAddress(libInst, "mapGetRscIdent");    *
*    HRSC hRsc = (*lpfn)(hMap,hSite);                              *
*                                                                  *
*    // �������� ����������                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

#ifndef RSCAPI_H
#define RSCAPI_H

#ifndef MAPTYPE_H
 #include "maptype.h"
#endif

  // ���������� ����� ����� ���������� � 0. ������� ���� - ���������.
  // ��������������� ���� ������ ��� ��������.�������� ���� ���������.
  // �������� ��� ���� (����) - ���������.

  // ���������� ��� (���������� ����� ) �������� ���������� � 1.
  // ���������� ��� ������� �� ����� ���������� ��������.
  // ���� ������� - ��������.

  // ��������������� �������� ������ ���. ��������� � ����� 0 - ���������.
  // ��� ��������� �� �������� �� ���������� ������� .
  // ���������� ����� ��������� ���������� � 1.
  // �������� ��� ��������� (����) - ���������.

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ �������� ������� ������� � �������������� +++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifdef __cplusplus
extern "C"
{
#endif  //__cplusplus
  /*********************************************************
  *                                                        *
  * ������� ������� ���������� �� �������������� ��'�����  *
  *                                                        *
  *********************************************************/

  // ��������� ������������� �������������� �����
  // hMap  - ������������� �������� �����
  // hSite - ������������� �������� ���������������� �����
  // ��� ������ ���������� ����

_MAPIMP  HRSC _MAPAPI mapGetRscIdent(HMAP hMap,HSITE hSite);

  // ��������� ��� ����� ��������������
  // hRsc   - ������������� �������������� �����,
  // target - ������ ��� ���������� ������� ����� �����,
  // size   - ������ ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscFileName(HRSC hRsc,
                                     char * target, long int size);

  // ��������� ��� ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  const char * _MAPAPI mapGetRscName(HRSC hRsc);

  // ��������� ��� ������ ��������� �������� � ��������������� �����
  // hRsc - ������������� �������������� �����
  // ���� ������ ����������� � maperr.rh

_MAPIMP  long int _MAPAPI mapGetRscError(HRSC hRsc);

  // ��������� ����� �������� ��������� � ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscObjectCount(HRSC hRsc);

  // ��������� ����� �������� ��������� � ��������������
  // � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscObjectCountInLayer(HRSC hRsc,
                                               long int layer);

  // ��������� �������� ������� �� ����������� ������
  // � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ���� ��� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscObjectNameInLayer(HRSC hRsc,
                                               long int layer,
                                               long int number);

  // ��������� ����������������� ��� �������
  // �� ����������� ������ � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscObjectExcodeInLayer(HRSC hRsc,
                                             long int layer,
                                             long int number);

  // ��������� ��� ����������� �������
  // �� ����������� ������ � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ���� (���� ��������)

_MAPIMP  long int  _MAPAPI mapGetRscObjectLocalInLayer(HRSC hRsc,
                                            long int layer,
                                            long int number);

  // ��������� ���������� ��� (���������� �����) �������
  // �� ����������� ������ � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscObjectCodeInLayer(HRSC hRsc,
                                               long int layer,
                                               long int number);

  // ��������� ������ ������� ������� ��������� ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscScaleCount(HRSC hRsc);

  // ��������� �������� (����������� ��������) �� ������� �������
  // ��������� ��������������  �� ����������� ������ (� 1)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscScaleItem(HRSC hRsc,
                                       long int number);

  /*********************************************************
  *                                                        *
  *        ������� �������� �������������� ��'�����        *
  *                                                        *
  *********************************************************/

  // ������� ������������� ��������� �����
  // name - ��� ������������ ����� ��������������
  // RSCCREATE -   ��������� ������� ������  (��. maptype.h)
  // PALETTE256 -  ��� ������������� �������� ������� (�� ����� 32 ������)
  //               (��. maptype.h)
  // ��� ������ ���������� ����

_MAPIMP  HRSC _MAPAPI mapCreateRsc(char * name, RSCCREATE * rsccreate,
                            PALETTE256 * palette );

  // ������� ������������� ��������� ����� c �������������� ����� �������
  // �� ����� (��������� ����� �������)
  // name - ��� ������������ ����� ��������������
  // RSCCREATE -   ��������� ������� ������  (��. maptype.h)
  // PALETTE256 -  ��� ������������� �������� ������� (�� ����� 32 ������)
  //               (��. maptype.h)
  // ��� ������ ���������� ����                         // 21/05/02

_MAPIMP  HRSC _MAPAPI mapCreateKeyObjectRsc(char * name, RSCCREATE * rsccreate,
                            PALETTE256 * palette );


  // ��������� ������ �� �������������� ��������� �����
  // hRsc - ������������� �������������� �����
  // RSCCREATE -  �������� ��������������  (��. maptype.h)
  // PALETTE256 - �������� ������� �����   (��. maptype.h)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscDescribe(HRSC hRsc, RSCCREATE * rsccreate,
                                     PALETTE256 * palette);

  // ������� �������������
  // name - ���  ����� ��������������
  // ��� ������ ���������� ����, ����� ������������� �������������� �����

_MAPIMP  HRSC _MAPAPI mapOpenRsc(char * name);

  // ������� �������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  HRSC _MAPAPI mapCloseRsc(HRSC hRsc);

  // ��������� ������������� �� ����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCommitRsc(HRSC hRsc);

  // ������������ ������������� � �����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapRevertRsc(HRSC hRsc);

 /****************************************************************
 *                                                               *
 *     ������ � �������� ����������� ����������� �����           *
 *    ����������� ���������� � 0                                 *
 *                                                               *
 ****************************************************************/

  // ������ ���������� �����������
  // hRsc - ������������� �������������� �����

_MAPIMP  long int  _MAPAPI mapGetRscLocalCount(HRSC hRsc);

  // ������ �������� ����������� �� �� ������ (0 - ��������, ...)
  // hRsc - ������������� �������������� �����
  // local - ��� �����������
  // language - ���� (�� ��������� - �������)
  // �������� �������� �� ���� ������ ...

_MAPIMP  const char * _MAPAPI mapGetRscLocalName(HRSC hRsc,long int local,
#ifdef __cplusplus
                                          long int language = ML_RUSSIAN);
#else
                                          long int language);
#endif


  // ������ ����� ����� �����������
  // hRsc - ������������� �������������� �����
  // (������ ��� �������� �� 32 ��������)

_MAPIMP  long int _MAPAPI mapGetRscLocalNameSize(HRSC hRsc);



  /*********************************************************
  *                                                        *
  *  ������� ������ �� ������ �� �������������� ��'�����   *
  *                                                        *
  *********************************************************/

  // ��� ������� �������� �����  � ������ ���������������  �����
  // ��������� ������� ������ ����� �� �����, ����� ����������� ���-
  // ����� �� ���� � ���� � ����� �������� ����� ���������� ��������
  // ����� � ������������ � ��������������� - ������� mapAdjustData()
  // � ��� ������������� ������������ �����

  // ������ ���������� �����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentCount(HRSC hRsc);


  // ������ ����� ���� �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ""

_MAPIMP  const char * _MAPAPI mapGetRscSegmentName(HRSC hRsc,long int incode);


  // ������ ����������� ������ ���� �� �����
  // ������ ����� ���������� � 0 !
  // hRsc - ������������� �������������� �����
  // name - ��� ����
  // ��� ���������� ���� ���������� - 0, ��� ������ IDS_NOTFIND

_MAPIMP  long int _MAPAPI mapGetSegmentByName(HRSC hRsc,char * name);


  // ������ ������������ ����� ����� ����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentNameSize(HRSC hRsc);


  // ������ ������� ������ ���� �� ����� �� ����������� ������ (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentOrder(HRSC hRsc,long int incode);


  // ������ ���������� �������� ���� ��  ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentObjectCount(HRSC hRsc,long int incode);


  // ��������� ����� ���� �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // name   - ��� ����
  // ��� ������ ���������� ����  ��� ������ IDS_REPLY ��� ������� �����

_MAPIMP  long int _MAPAPI mapSetRscSegmentName(HRSC hRsc,
                                        long int incode,char * name);


  // ��������� ������� ������ ���� �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // order  - ������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRscSegmentOrder(HRSC hRsc,
                                         long int incode,
                                         long int order);


  // ������� ���� �� ����������� ������ ���� (� 0)
  // ���� ���������  ������ � ���������
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapDeleteRscSegment(HRSC hRsc,long int incode);


  // ��������� ������� �� ������ ���� � ������
  // hRsc - ������������� �������������� �����
  // oldcode, newcode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapMoveRscSegmentObjects(HRSC hRsc,
                                            long int oldcode,
                                            long int newcode);


  // ������� ���� � �������������� �����
  // RSCSEGMENT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����,��� ������ IDS_REPLY ��� ������� �����
  // ����� ���������� ����� ���� (� 0)

_MAPIMP  long int _MAPAPI mapAppendRscSegment(HRSC hRsc, RSCSEGMENT * segment);


  // ��������� ��������� �������� �����
  // RSCSEGMENT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ����
  // ��� ������ ���������� ���� � ��� ������
  // ����� ���������� ����� ����  (� 0)

_MAPIMP  long int _MAPAPI mapGetRscSegment(HRSC hRsc, RSCSEGMENT * segment,
                                    long int incode);


  // ��������� �������� ��� (����) ����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ���� (� 0)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSegmentShortName(HRSC hRsc,long int incode);
_MAPIMP  const char * _MAPAPI mapGetRscSegmentKey(HRSC hRsc,long int incode);  //18/09/01


  // ���������� �������� ���(����) ����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSegmentShortName(HRSC hRsc,long int incode,
                                             char * shortname );
_MAPIMP  long int _MAPAPI mapSetRscSegmentKey(HRSC hRsc,long int incode,    //18/09/01
                                             char * key);


  // ��������� ���������� ����� ���� (� 0) �� ��������� �����(�����) ����   //11/03/00
  // hRsc - ������������� �������������� �����
  // shortname - �������� ���(����) ����
  // ��� ������ ���������� ���� � ��� ������
  // ����� ���������� ����� ����  (� 0)

_MAPIMP  long int _MAPAPI mapGetRscSegmentByShortName(HRSC hRsc,char * shortname);
_MAPIMP  long int _MAPAPI mapGetRscSegmentByKey(HRSC hRsc,char * key);     //18/09/01


  // ��������� ���������� �������� ����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscSegmentSemanticCount(HRSC hRsc,long int incode);


  // ��������� ��� ��������� ���� �� ����������� ������
  // number ��������� � ������ (� 1)
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscSegmentSemanticCode(HRSC hRsc,long int layer,
                                                 long int number);


  // �������� ��������� ����
  // semanticcode ��� ����������� ���������
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapAppendRscSegmentSemantic(HRSC hRsc,long int layer,
                                                long int semanticcode);


  // ������� ��������� �� ����
  // semanticcode ��� ��������� ���������
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapDeleteRscSegmentSemantic(HRSC hRsc,long int layer,
                                                    long int semanticcode);


  // ���������� ��������� ��� ����
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // type = 0 - ������� ��� ���������,1 - ������ ������������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapBuildRscSegmentSemantic(HRSC hRsc,long int layer,
                                              long int type);



  /***********************************************************
  *                                                          *
  *  ������� ������ � ��'������ �� �������������� ��������   *
  *                                                          *
  ***********************************************************/

  // ������� ������
  // RSCOBJECT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ���� , ����� ���������� ����� ������� (� 1)

_MAPIMP  long int  _MAPAPI mapAppendRscObject(HRSC hRsc, RSCOBJECT * object);


  // ����������� ������
  // hRsc - ������������� �������������� �����
  // oldcode - ���������� ����� ������� � �������� ��������
  // ��� ������ ���������� ���� , ����� ���������� ����� ������ ������� (� 1)
  // ���������� ��������� �������,��� �����������,��������� �������
  // ���  FIRSTSERVEXCODE
  // ��� ����,����� ������ ������ ����������,
  // ������������ ������ �������������� ������� ���

_MAPIMP  long int  _MAPAPI mapCopyRscObject(HRSC hRsc, long int oldcode);


  // �������� ������
  // RSCOBJECT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ���� , ����� ���������� ����� ������� (� 1)
  // ��� ������� ����� ������� ��� � ����������� � ���� - �� ��������
  // ���� ������� ��� ������� �� ������������� ����������� - ������������
  // ������������ ������� ���

_MAPIMP  long int  _MAPAPI mapUpdateRscObject(HRSC hRsc,long int code,
                                       RSCOBJECT * object);


  // ������� ������
  // hRsc - ������������� �������������� �����
  // �ode - ���������� ����� ������� ������� ������� (� 1)
  // ��� ������ ���������� ���� , ����� ���������� ����� ���������� �������
  // ���� ������ ������ � ����� - �������� �� ��������

_MAPIMP  long int  _MAPAPI mapDeleteRscObject(HRSC hRsc,long int code);


  // ��������� ��������� �������� �������
  // RSCOBJECT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // ��� ������ ���������� ���� , ����� ���������� ����� �������

_MAPIMP  long int  _MAPAPI mapGetRscObject(HRSC hRsc,long int incode,
                                    RSCOBJECT * object);


  // ��������� ���������� ����� ������� � ����� ����������
  // �������� (� ����� ����������������� ����� � ������������)
  // �� ����������� ���� �������
  // (��������������� ������� - mapGetRscObjectCodeByNumber)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // ��� ������ ��� ���������� ����� ���������� ���� ,
  // ����� ����� ������� � �����

_MAPIMP  long int _MAPAPI mapGetRscObjectNumber(HRSC hRsc,long int incode);


  // ��������� ������� � �������� � �������� ����������� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // IMAGESIZE -  ��������� ������� ������  (��. maptype.h)
  // ������ string ������ length �������� ���
  // ����������� ��������������� ������� �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscImageSize(HRSC hRsc,
                            long int incode, IMAGESIZE * imagesize,
#ifdef __cplusplus
                            long int length = 0,char * string = 0);
#else
                            long int length,char * string);
#endif


 // ��������� ���������� ����� ����������� ������� (��������, ���������)
 // � ������ �������� ������� (IMAGEFRAME - ��. maptype.h)
 // ��� ������� � �������� �� "��������" ����������� (� ������� ��������)
 // ������������ ������ ����� ������� ������� � ���������������� �������
 // ��� ��������� ���������� ��������� � ����� �� ��������� �����
 // �� �������� �� 1 000 000, �������� �� ������� ������� �����
 // � �������� ���������� ������ ����� �������
 // number - ����� ������� ����������� (mapgdi.h)
 // param  - ��������� ����������� (mapgdi.h)
 // angle  - ���� �������� ������� � �������� �� ������� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscMarkFrame(HRSC hRsc, long int number,
                                     const char * param,
                                     double angle,
                                     IMAGEFRAME * imageframe);


  // ��������� ���������� ��� (���������� �����) �������
  // �� �������� ���� , �����������  � ����������� ������ ����� �����������
  // ��������(� 1)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscObjectCodeByNumber(HRSC hRsc,
                                                long int excode,
                                                long int local,
#ifdef __cplusplus
                                                long int number = 1);
#else
                                                long int number);
#endif


  // ��������� ���������� �������� � �������� ������� ����� � ������������
  // hRsc - ������������� �������������� �����
  // excode - ������� ��� �������
  // local  - ��� �����������
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscObjectsCount(HRSC hRsc,
                                          long int excode,
                                          long int local);


  // ��������� ��� ������� �� �����������  ���� (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscObjectName(HRSC hRsc,long int incode);


  // ��������� ���� ������� �� �����������  ���� (����������� ������) //14/06/01
  // ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscObjectKey(HRSC hRsc,long int incode);


  // ���������� ���� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // (�������� ��� ������ ���� ���������)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapSetRscObjectKey(HRSC hRsc,long int incode,
                                                const char * key);


  // ��������� ������������� ������� (���������� ���������� ��������
  // � �������� ������� ��������������) �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectIdent(HRSC hRsc,long int incode);


  // ��������� ���������� ��� (���������� �����) �������
  // �� ��������������
  // hRsc - ������������� �������������� �����
  // ident - ������������� ������� 
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectIdentIncode(HRSC hRsc,long int ident);


  // ��������� ���������� ��� (���������� �����) �������
  // �� �����
  // hRsc - ������������� �������������� �����
  // key  - ���� �������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectKeyIncode(HRSC hRsc,const char * key);


  // ��������� ����������  ��� (���������� �����) �������       //22/06/01
  // �� �����
  // hRsc - ������������� �������������� �����
  // name - ��� �������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectCodeByName(HRSC hRsc,char * name);


  // ��������� ����� �������� �������� �� ������� ��� ������� �� �����������
  // ���� (����������� ������)  ������� (� 1)
  // incode - ���������� ��� ������� (����� �� �������)
  // hRsc   - ������������� �������������� �����

_MAPIMP  long  _MAPAPI mapGetRscImageSemanticCount(HRSC hRsc,long int incode);


  // ������ ���� ��������� �������� �� ����������� �� ����������� ����
  // (����������� ������) ������� � ����������� ������ ����� ��������� (c 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // number - ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscImageSemanticCode(HRSC hRsc,long int incode,
                                            long int number);


  // ���p����� ���������� ��������� �������� �������        //01/11/01
  // �� ����������� ���� (����������� ������) �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)

_MAPIMP  long _MAPAPI mapGetRscObjectRelateCount(HRSC hRsc,long int incode);


  // ���p����� �������� ��������� ������� �� ����������� ����   //01/11/01
  // (����������� ������) ������� � �� ����������� ������ ��������� ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // relate - �������� ��������� ������� (maptype.h)
  // Order  - ���������� ����� ��������� �������
  // ���������� ������������� �������,
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectRelateOrder(HRSC hRsc,long int incode,
                                         long int order,RSCRELATION * relate);

  /**************************************************************
  *                                                             *
  *  ������� ������ � ����������� ����������� ��������          *
  *                                                             *
  **************************************************************/

  // ��������� ����� ������� ����������� ������� �� �����������  ����
  // (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscObjectFunction(HRSC hRsc,long int incode);


  // ��������� ����� ���������� ����������� ������� �� �����������  ����
  // (����������� ������)������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectParametersSize(HRSC hRsc,long int incode);


  // ��������� ��������� ����������� ������� �� �����������  ����
  // (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  const char * _MAPAPI mapGetRscObjectParameters(HRSC hRsc,long int incode);


  // ��������� ���������� ���������� � ���������� ����������� ������� ��
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrimitiveCount(HRSC hRsc,long int incode,
#ifdef __cplusplus
                                        long int viewtype = 0);
#else
                                        long int viewtype);
#endif


  // ��������� ����� ������� ����������� ��������� �� �����������
  // ������ ��������� � ���������� ����������� ������� ,
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrimitiveFunction(HRSC hRsc,long int incode,
                                           int number,
#ifdef __cplusplus
                                           long int viewtype = 0);
#else
                                           long int viewtype);
#endif


  // ��������� ����� ���������� ��������� �� �����������
  // ������ ��������� � ���������� ����������� ������� ,
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // number - ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrimitiveLength(HRSC hRsc,long int incode,
                                        int number,
#ifdef __cplusplus
                                        long int viewtype = 0);
#else
                                        long int viewtype);
#endif


  // ��������� ����� ���������� ��������� �� �����������
  // ������ ��������� � ���������� ����������� ������� ,
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // number - ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  char * _MAPAPI mapGetRscPrimitiveParameters(HRSC hRsc,long int incode,
                                        int number,
#ifdef __cplusplus
                                        long int viewtype = 0);
#else
                                        long int viewtype);
#endif


  // �������� ������������ ����������� � ���� ����������� �������
  // �� ����������� ����  ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscImageSuitable(HRSC hRsc,long int local,
                                     long int incode);


  // ���������� ������� ��� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // length - ����� ����������
  // number - ����� ������� �����������
  // param  - ��������� �� ��������� �������
  // ��� ������ ���������� ���� , ����� ���������� ����� �������

_MAPIMP  long int  _MAPAPI mapSetRscObjectImage(HRSC hRsc,
                                         long int incode,
                                         long int length,
                                         long int number,char * param);


  // ��������� ����� ������� (�����������) ����������� ������� �� ����������� ����
  // (����������� ������) �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrintObjectFunction(HRSC hRsc,long int incode);   //26/11/01


  // ��������� ����� ���������� (�����������)����������� ������� �� �����������  ����
  //(����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0                                              //05/02/02

_MAPIMP  long _MAPAPI mapGetRscPrintObjectParametersSize(HRSC hRsc,long int incode);


  // ��������� ��������� ����������� (�����������)������� �� �����������  ����
  //  �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0
                                                       //26/11/01
_MAPIMP  const char * _MAPAPI mapGetRscPrintObjectParameters(HRSC hRsc,long int incode);


  // ���������� ���������� ��� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // length - ����� ����������
  // number - ����� ������� �����������
  // param  - ��������� �� ��������� �������
  // ��� ������ ���������� ���� , ����� ���������� ����� �������
                                                     //26/11/01
_MAPIMP  long int  _MAPAPI mapSetRscPrintObjectImage(HRSC hRsc,
              long int incode,long int length,long int number,char * param);


  // ����� "��������" ���� ����������� �������                  // 11/04/05
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // viewtype - ��� �����������  0 - ��������, 1 - ����������
  // ��� ���������� ����� ���������� 0xFF000000
  // ��� ������ ���������� 0

_MAPIMP  COLORREF  _MAPAPI  mapGetRscObjectBaseColor(HRSC hRsc, long int incode,
                                          long int viewtype);


  // ��������� ���� ������ ����������� �������                     // 18/04/05
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // ���������� 0 - ����������� ���������, 1 - ���.

_MAPIMP  int _MAPAPI  mapGetRscObjectPressure(HRSC hRsc, long int incode);


  // ���������� ���� ������ ����������� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // flag - ���� ������ ����������� 0 - ���������, 1 - ���.
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI  mapSetRscObjectPressure(HRSC hRsc, long int incode,long int flag);





  /**************************************************************
  *                                                             *
  *  ������� ������ �  ����������� �� �������������� ��'�����   *
  *                                                             *
  **************************************************************/

  // ������� ����� ��������� - ����������  ��� ��������� ���������
  // hRsc - ������������� �������������� �����
  // ��������� RSCSEMANTICEX ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapAppendRscSemanticEx(HRSC hRsc,RSCSEMANTICEX * rsem);


  // �������� ��������� - ����������  ��� ����������� ���������
  // code - ��� ����������� ���������
  // classupdate - 1, ������������� ��������� ��������� ��� ������������
  // ����������(�������� ��� ����� ���� ���������), 0 - ��� ��������� ��������
  // ������� � ���������� �������������� ������ ��������� �� �����.
  // hRsc - ������������� �������������� �����
  // ��������� RSCSEMANTICEX ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapUpdateRscSemanticEx(HRSC hRsc,long int code,
                                    RSCSEMANTICEX * rsem,long int classupdate);


  // ������� ���������
  // code - ��� ��������� ���������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapDeleteRscSemantic(HRSC hRsc,long int code);


  // ��������� ���������� � ���������� ��������� ��� �������� �����
  // code - ��� ���������
  // applysemantic - ��������� ��� ���������� (maptype.h)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscApplySemantic(HRSC hRsc,long int code,
                                           APPLYSEMANTIC * applysemantic);


  // �������� �������������� ��������� �������
  // hRsc - ������������� �������������� �����
  // objincode - ���������� ��� �������,
  // code      - ��� ���������,
  // enable    - ��� ������� � ���������
  // (2 - ������������, 1 - ���������)
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapEnableRscSemantic(HRSC hRsc,
                                         long int objincode,
                                         long int code,
                                         long int enable);


  // ��������� ���������� �������� � ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticCount(HRSC hRsc);


  // ��������� ��� ��������� �� ����������� ������
  // hRsc - ������������� �������������� �����
  // number - ����� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticCodeByNumber(HRSC hRsc, long int number);


  // ��������� ���������� ����� ��������� (� 0)
  // �� ��������� ����� (�����)���������                                   //11/03/01
  // hRsc - ������������� �������������� �����
  // shortname - �������� ��� ���������
  // ��� ������ ���������� ����
  // ����� ���������� ����� ���������(� 1)

_MAPIMP  long int _MAPAPI mapGetRscSemanticByShortName(HRSC hRsc,const char * shortname);
_MAPIMP  long int _MAPAPI mapGetRscSemanticByKey(HRSC hRsc,const char * key);  //18/09/01


  // ��������� �������� ��������� �� ����������� ������
  // hRsc - ������������� �������������� �����
  // number - ����� ���������
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSemanticNameByNumber(HRSC hRsc, long int number);


  // ��������� ��� ��������� �� �� �������� ����
  // ���� ����� �������� - ��. maptype.h (SEMTYPE)
  // hRsc - ������������� �������������� �����
  // code - �������� ��� ���������
  // ��� ������ ���������� ���� (���������� ��������� ����� ��� ����!)

_MAPIMP  long int _MAPAPI mapGetRscSemanticTypeByCode(HRSC hRsc, long int code);


  // ��������� �������� ��� (����) ���������
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSemanticShortName(HRSC hRsc,long int code);
_MAPIMP  const char * _MAPAPI mapGetRscSemanticKey(HRSC hRsc,long int code); //18/09/01


  // ���������� �������� ��� (����) ���������
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSemanticShortName(HRSC hRsc,long int code,
                                             char * shortname );
_MAPIMP  long int _MAPAPI mapSetRscSemanticKey(HRSC hRsc,long int code,
                                             char * key );         //18/09/01


  // ���������� ������ � �������� �������� ���������       // 11/03/01
  // hRsc - ������������� �������������� �����
  // size - ������ �������� ��������� (������� ���������� �����)
  // decimal - ���������� ������ ����� ������� (� ���������� - 0)
  // code - ��� ���������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSemanticDecimal(HRSC hRsc,long int code,
                                            long int size,long int decimal);


  // ��������� ��������� �������� ������������� ��������������      // 21/01/02
  // �� ���� ���������
  // hRsc - ������������� �������������� �����
  // code - ������� ��� ���������
  // ��������� RSCSEMANTICEX ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticExByCode(HRSC hRsc,RSCSEMANTICEX * semtype,
                                       long int code);


  // ��������� ���������� �������� �������������� �������������
  // �������������� �� ���� ��������� (���� �� ��� TCODE)
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticClassificatorCount(HRSC hRsc,
                                                    long int code);


  //  ��������� �������� �������� �������������� ��
  //  �������������� ��������� �� ���� ��������� �
  //  ����������������� ������ � ��������������
  //  hRsc - ������������� �������������� �����
  //  number - ���������������� ����� � ��������������(1,2,3...)
  //  code - ��� ���������
  //  ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSemanticClassificatorName(HRSC hRsc,long int code,
                                                           long int number);


  //  ��������� ��� �������� �������������� ��
  //  �������������� ��������� �� ���� ��������� �
  //  ����������������� ������ � ��������������
  //  hRsc - ������������� �������������� �����
  //  number - ���������������� ����� � ��������������(1,2,3...)
  //  code - ��� ���������
  //  ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticClassificatorCode(HRSC hRsc,
                                                     long int code,
                                                     long int number);


  // �������� ����� "�������" ��������������
  // (�������� �������� � ����������) ����������
  // ����� ���������� ������ � 1
  // hRsc - ������������� �������������� �����
  // semanticcode - ��� ������������� ��������������
  // value - �������� ��������
  // name  - ���������� �������� ������������� ��������������

_MAPIMP  long int  _MAPAPI mapAppendRscClassificator( HRSC hRsc,int semanticcode,
                                              short int value,char * name);


  // �������� ���������� �������� �������������� �� ������ ������ (� 1)   //10/12/01
  // ���������� ����� ������������ ������ � 1
  // ��� ������ ���������� ����
  // hRsc - ������������� �������������� �����
  // semanticcode - ��� ������������� ��������������
  // index - ����� ������
  // name  - ���������� �������� ������������� ��������������

_MAPIMP  long int  _MAPAPI mapUpdateRscClassificatorName( HRSC hRsc,int semanticcode,
                                              int index,char * name);




  /**************************************************************
  *                                                             *
  *  ������� ������ � ����������� ��� ���������  ��'�����       *
  *                                                             *
  **************************************************************/

  // ��������� ���������� �������� ��� ������� �������
  // �� ���������� ��������� - ��. maptype.h (SEMANTIC_FOR_OBJECT )
  // �� ����������� ���� (����������� ������) ������� (c 1)
  // hRsc - ������������� �������������� �����
  // ���������� ���������� �������� ��������� ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // importance - ��������  

_MAPIMP  long int  _MAPAPI mapGetRscSemanticObjectCount( HRSC hRsc,long int incode,
                                                  long int importance);


  // ��������� ������������� ��������� ��� ������� ������� -
  // incode - ���������� ��� (���������� �����)�������
  // semanticcode - ��� ���������
  // hRsc - ������������� �������������� �����
  // ���������� ���������� ���������  ��. maptype.h (SEMANTIC_FOR_OBJECT )

_MAPIMP  long int  _MAPAPI mapGetRscSemanticObjectUsed(HRSC hRsc,long int incode,
                                      long int semanticcode);


  // ��������� ��� ���������  ��� ������� ������� �� ����������� ������
  // ������ ��������� ��� ������� (� 1) � ���������� ���������
  // ��. maptype.h (SEMANTIC_FOR_OBJECT ) ��� ���������� ���������
  // ALL_SEMANTIC - ���������� ��������� � ������� ����������
  // incode - ���������� ��� (���������� �����) �������
  // importance - ���������� ���������
  // hRsc - ������������� �������������� �����
  // ���������� ��� ���������
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapGetRscSemanticObjectCode(HRSC hRsc,long int incode,
                                      long int number,long int importance);


  // �������� ��� ���������  ��� ������� ������� �� ���������� ���������
  // (POSSIBLE_SEMANTIC ��� MUST_SEMANTIC)
  // semanticcode - ��� ���������
  // incode - ���������� ��� (���������� �����) �������
  // hRsc - ������������� �������������� �����
  // ���������� ����� ����������� ��������� � ���������� ������� ����
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapAppendRscSemanticObject(HRSC hRsc,long int incode,
                                     long int semanticcode,long int importance);


  // �������� ���������� ��������� ��� ������� �������
  // (POSSIBLE_SEMANTIC ��� MUST_SEMANTIC)
  // semanticcode - ��� ���������
  // incode - ���������� ��� (���������� �����) �������
  // hRsc - ������������� �������������� �����
  // ���������� ����� �������� ��������� ����������
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapUpdateRscSemanticObject(HRSC hRsc,long int incode,
                                     long int semanticcode,long int importance);


  // ������� ��������� ��� ������� �������
  // (POSSIBLE_SEMANTIC ��� MUST_SEMANTIC)
  // semanticcode - ��� ���������
  // incode - ���������� ��� (���������� �����) �������
  // hRsc - ������������� �������������� �����
  // ���������� ����� ����� �������� �������
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapDeleteRscSemanticObject(HRSC hRsc,long int incode,
                                     long int semanticcode);


   // ��������������� ������ �������� ��� ������� � ������������ �  // 16/02/04
   // ����������� ��������
   // incode - ���������� ��� (���������� �����) �������
   // hRsc - ������������� �������������� �����
   // count - ������ ������� �������� ������� ��� ����������
   // semantics - ��������� �� ������ ������� ��������� �������� �������.
   // order     - ��������� �� �������� ������ �������� ����������������
   // ����������� �������� ������� ��������(� 1 )
   // ��� ���������� ���������� ���������� 1

_MAPIMP   long int  _MAPAPI mapSortRscObjSemantic(HRSC hRsc,long int incode,
                            long int count,long int * semantics,long int * order);


   // �������� ������� �������� ��� ������� � ������������ � �������
   // �������
   // incode - ���������� ��� (���������� �����) �������
   // hRsc - ������������� �������������� �����
   // count - ������ ������� �������� �������
   // semantics - ��������� �� ������������� ������ �������� �������.
   // ��������� ������� �� �������� ������� - ������������,
   // ���� ����� - �� ��������� ��������� ������� � ����� ������
   // ��� ���������� ���������� ���������� ���������� �������� �������

_MAPIMP   long int  _MAPAPI mapSetRscObjSemanticOrder(HRSC hRsc,long int incode,
                                       long int count,long int * semantics);



  /**************************************************************
  *                                                             *
  *  ������� ������ � ��������� ���������������                 *
  *                                                             *
  **************************************************************/

  // ��������� ���� �� �������
  // color - ���� � COLORREF
  // index - ���������� ����� ����� � ������� (� 1)
  // number - ���������� ����� ������� (� 1)
  // hRsc - ������������� �������������� �����
  // ���������� ���� � COLORREF

_MAPIMP  COLORREF _MAPAPI mapGetRscColor(HRSC hRsc,long int index,
#ifdef __cplusplus
                                  long int number = 1);
#else
                                  long int number);
#endif


  // ���������� ���� � ������ �������
  // color - ���� � COLORREF
  // index - ���������� ����� ����� � ������� (� 1)
  // number - ���������� ����� ������� (� 1)
  // hRsc - ������������� �������������� �����
  // ���������� �������
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapSetRscColor(HRSC hRsc,COLORREF color,long int index,
#ifdef __cplusplus
                                     long int number = 1);
#else
                                     long int number);
#endif


  // ��������� ���������� ������ � ������� ��������������
  // hRsc - ������������� �������������� �����

_MAPIMP  long int  _MAPAPI mapGetRscColorCount(HRSC hRsc);


  // ��������� ���������� ������ ��������������
  // hRsc - ������������� �������������� �����

_MAPIMP  long int  _MAPAPI mapGetRscPaletteCount(HRSC hRsc);


  // ������ ����� ������� �� �� ������
  // number - ���������� ����� ������� (� 1)
  // hRsc - ������������� �������������� �����

_MAPIMP  char * _MAPAPI mapGetRscPaletteName(HRSC hRsc,int number);



#ifdef __cplusplus
  /************************************************************
  *                                                           *
  *  ������� ������ � �������� ���������������  //04/10/01    *
  *                                                           *
  ************************************************************/

  // K�� ������ - ������������� � ��������� ������� (IMGTEXT: ���� Type)
  // (��. mapgdi.h) ��� ������ �� ������� �������.

  // ������ ���������� �������
  // ��� ������ ���������� ����
  // hRsc - ������������� �������������� �����

_MAPIMP  long int _MAPAPI mapGetFontCount(HRSC hRsc);


  // �������� ����� - ���������� ��� ������
  // hRsc - ������������� �������������� �����
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapAppendFont(HRSC hRsc,RSCFONT * font);


  // �������� ����� - ���������� ��� ������
  // hRsc - ������������� �������������� �����
  // index - ���������� ����� ������ (� 1)
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapReplaceFont(HRSC hRsc,int index,RSCFONT * font);


  // ������ ���� ������ �� ����������� ������(c 1)
  // hRsc - ������������� �������������� �����
  // number - ����� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetFontCode(HRSC hRsc,int number);


  // ������ ������ �� ����������� ������ (c 1)
  // ���������� ��� ������
  // hRsc - ������������� �������������� �����
  // number - ����� ������
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetFont(HRSC hRsc,int number,RSCFONT * font);


  // ������ ������ �� ����
  // ���������� ���������� ����� ������ (� 1)
  // hRsc - ������������� �������������� �����
  // code - ��� ������
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetFontByCode(HRSC hRsc,int code,RSCFONT * font);

#endif //__cplusplus

#ifdef __cplusplus
} // extern "C"
#endif //__cplusplus
#endif

