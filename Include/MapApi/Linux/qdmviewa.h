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
*       �������� �������� ������ ������� � ��'����                 *
*                     "����������� �����"                          *
*                                                                  *
*******************************************************************/

#ifndef QDMVIEWA_H
#define QDMVIEWA_H

#include <qscrollview.h>
#include <qtextcodec.h>
#include "qdmtype.h"                                   // 28/11/03

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++ ������� ����� "��������� ���������� ����������� ������" ++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class  QDMapViewAcces : public QScrollView
{
   Q_OBJECT

public :
   QDMapViewAcces(QWidget *parent = 0, const char *name = 0, WFlags f = 0);  // 11/12/07

   // �������� ������������� �����
   virtual HMAP GetMapHandle();

   // �������� ������ ������� � �����
   virtual QDMapViewAcces *GetMapViewAcces();

public :
   // ��� ����������� �������������
   HMAP       VarMapHandle;   // �������� ������������� �����
   QTextCodec *MainCodec;     // 02/06/06
};

#endif  // QDMVIEWA

