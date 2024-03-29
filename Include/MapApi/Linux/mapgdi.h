/****** MAPGDI.H *************** Kruzhkov A.E.   ****** 12/01/06 ***
******* MAPGDI.H *************** Belenkov O.V.   ****** 11/01/06 ***
******* MAPGDI.H *************** Panteleeva N.A. ****** 21/07/06 ***
******* MAPGDI.H *************** Dishlenko S.G.  ****** 23/04/01 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2006              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*      �������� ���������� ������� ������������ ������������       *
*             ����������� ��'����� ����������� �����               *
*                                                                  *
*******************************************************************/

#ifndef MAPGDI_H
#define MAPGDI_H

#ifndef MAPTYPE_H
 #include "maptype.h"
#endif


// ����� ���������������� ������� (������������ ��� Image ������ IMG_OBJECT)

#define IM_PRESS       0x00000000  // ������� ��� ���������� ����� (�� ���������)
#define IM_DONTPRESS   0x04000000  // �� ������� ��� ����������

#define IM_SCALE       0x01000000  // ��������������
#define IM_DONTSCALE   0x02000000  // �� ��������������

#define IM_SCALEDONTPRESS  (IM_SCALE | IM_DONTPRESS)  // ������ �����������

#define IM_CLEARSCALE 0x0F8FFFFFF  // ������ ����� ���������������


//-----------------------------------------------------------------
// �������� ������� ����������� ������������ ��'����
//-----------------------------------------------------------------

typedef struct PAINTPARM
{
  long int Image;  // ��� ������� �����������

  char *   Parm ;  // ��������� ����������� ��� ��������������� �������.
                   // ������������ ��� Image ������ IMG_OBJECT (���������
                   // � ����� ������� ��������������� �� ��������������)

  long int Mode ;  // ������� ����������� � ���������������
                   //   R2_COPYPEN   - ����������� ������
                   //   R2_NOT       - ����������� ��������� ���� (���� ������������)

                   //   IM_SCALE, IM_DONTSCALE, ... - �������� ����������������
                   //    (������������ ��� Image ������ IMG_OBJECT)

                   // ������ �������������: Mode = R2_NOT | IM_SCALE
}
  PAINTPARM;


//-----------------------------------------------------------------
// �������� ���������� ������
//-----------------------------------------------------------------
// �������� ����� ������ ����� ���� ������ ����� ������.
// ���� � ������ ����������� '\n',
// �� ����������� ������� �� ��������� ������
//-----------------------------------------------------------------

typedef struct TEXTRECORD
{
  long Length ;                  // ����� ������, ������� ���� Length
  char Text[1];                  // �����, ��������������� �������� 0
}
  TEXTRECORD;


//-----------------------------------------------------------------
// �������� ��������� ������������ ��'����
//-----------------------------------------------------------------
// ������� ��������� � ��� ������� ���������
// �������� � ���������� ������� ������������
//-----------------------------------------------------------------

typedef struct PLACEDATA         // ���������� � ������������ �������
{
  DOUBLEPOINT * Points    ;      // ������ ��������� ��������� ��������
  long int *    PolyCounts;      // ������ ���������� ����� ��������
  long int      Count     ;      // ���������� �������� ��� �������� TEXTRECORD
                                 // ��� ������� ���� IMG_TEXT :
  TEXTRECORD *  PolyText  ;      // ������� ��������������� �������������
                                 // �������� TEXTRECORD,
                                 // ����� �������� ����� Count !
}
  PLACEDATA;


//-----------------------------------------------------------------
// ��������� ����������� ������� ���� �������
//-----------------------------------------------------------------

typedef struct PAINTEXAMPLE
{
  HDC       Hdc;       // �������� ����������
  RECT*     Rect;      // ������� ����������� � ��������

  long int  Func;      // ����� ������� (IMG_LINE, IMG_DOT, ...)
  char*     Parm;      // ��������� �� ��������� �������

  POLYDATAEX* Data;    // �������
                       //   (���� Data != 0, �� text ������������)
                       //   (���� Data == 0, �� ��������� �������������)

  char*     Text;      // ����� ������ � ��������� WINDOWS
                       //   (���� Text == 0, �� ��������� �������������)

  long int  Local;     // ����������� (LOCAL_LINE, LOCAL_SQUARE, ...)
                       //   (������������ ��� Data == 0)

  float     Factor;    // ����������� ���������� (Factor >= 0.0)
                       //  0.0 - �������������� �������������

  long int  Colors;    // ����� ������ �������
  COLORREF* Palette;   // ��������� �� �������

  long int  VisualType;     // ��� ������������ (VT_SCREEN, VT_PRINT, ...)
                            //    0 - �������

  long int  FillIntensity;  // ������������� ������� (0,100)
                            //    0 - �������
                            //  100 - � �������� ������
  char      Reserve[16];
}
  PAINTEXAMPLE;


//******************************************************************
// ���� ������� ������������ ������������ ����������� ��'����� �� ��
//******************************************************************

#define IMG_EMPTY             127  // ������ ������� - ��� ����������

#define IMG_LINE              128
#define IMG_DOT               129

#define IMG_SQUARE            135

#define IMG_CIRCLE            140

#define IMG_TEXT              142

#define IMG_MULTIMARK         143
#define IMG_MULTISQUAREMARK   144

#define IMG_DRAW              147

#define IMG_DOTSHIFT          148

#define IMG_VECTOREX          149

#define IMG_TEMPLATE          150

#define IMG_TRUETYPE          151

#define IMG_TRUETEXT          152

#define IMG_HATCHSQUARE       153

#define IMG_SQUAREGLASS       154

#define IMG_SQUAREVECTOR      155
#define IMG_VECTOREXTURN      156

#define IMG_DECORATE          157
#define IMG_DASH              158
#define IMG_LINESHIFT         159
#define IMG_VECTORTEXT        160
#define IMG_VECTORNODE        161       // ��������� � ����� (IMGVECTOREX)
#define IMG_THICKENLINE       162       // ������������ �����
#define IMG_MIDDLETHICKENLINE 163       // ������������ ����� � �������� �� ������
#define IMG_SQUAREGLASSCOLOR  164

#define IMG_VECTORGRADIENT    199       // ��������� �������

#define IMG_PERCENT           249       // ��������� ���� IMG_LONG
#define IMG_LIBRARY           250

#define IMG_SEMANTIC          251       // ��������� ���� IMG_LONG
#define IMG_COLOR             252       // ��������� ���� IMG_LONG
#define IMG_DOUBLE            253
#define IMG_LONG              254

#define IMG_OBJECT            255       // ����� ������� ���������������
                                        // �� ��������������

// ���������� ���� (��� IMG_SQUAREMARK, IMG_MULTISQUAREMARK,
//                      IMG_SQUARECROSS, IMG_FONT, IMG_SQUAREGLASSCOLOR)
#define IMGC_TRANSPARENT  0x0FFFFFFFFL
#define IMGC_NOMARK       0x0FFFFFFFFL  // �� �������� (��� IMG_OBJECT)

// ����� ��� ����������� ������� ����� (������|IMGC_INDEX, RGB)
#define IMGC_INDEX        0x0F0000000L  // ���� ����� �� ������� �����
#define IMGC_CLEARINDEX   0x0FF000000L  // ��� ������� ����� ����� (& IMGC_CLEARINDEX)
#define IMGC_CLEARCOLOR   0x000FFFFFFL  // ���� ������� �����      (& IMGC_CLEARCOLOR)

// ���������� ������ ����� 
// color - ����� ����� � ������� RSC, ������� � 0 !!!
// ���� ���� IMGC_INDEX �� ����������, ���� � ������� RGB
#define SETCOLORINDEX(color)   (((long int)(color))|IMGC_INDEX)

#define IMGC_SYSTEM       0x0F1000000L  // ���� ����� �� ��������� ������� (LINUX)  // 16/10/03
#define SETCOLORSYSTEM(color)  (((long int)(color))|IMGC_SYSTEM)

// ���������� ������ ����� (����������: 0 - RGB, 1 - ������ �� �������)
#define TESTCOLORINDEX(color)  ((((long int)(color))&IMGC_CLEARINDEX)==IMGC_INDEX)

// ���������� ������ ����� (����������: 0 - RGB, 1 - ������ �� ��������� �������)
#define TESTCOLORSYSTEM(color) ((((long int)(color))&IMGC_CLEARINDEX)==IMGC_SYSTEM)  // 16/10/03

// ��� ����� ���������� 4x4 (16 ���) (��� IMG_SQUAREMARK, IMG_MULTISQUAREMARK)
//  1 - ����������� �������� �����
//  0 - �������������
// �������� ����� �����:
//  0000(0)  1111(F)  1010(A)  0101(5)
//  0000(0)  1111(F)  0101(5)  1010(A)
//  0000(0)  1111(F)  1010(A)  0101(5)
//  0000(0)  1111(F)  0101(5)  1010(A)
#define IMGK_REGULAR0     0x00000000L  // ���������� (��������� ���)
#define IMGK_REGULAR      0x0000FFFFL  // ���������� (��������� ���)
#define IMGK_ONECHESS     0x0000A5A5L  // ���������
#define IMGK_TWOCHESS     0x00005A5AL  // ��������� ���������

// ����������� ������� (��� IMG_OBJECT)
#define IMGL_LINE      0  // ��������
#define IMGL_SQUARE    1  // ���������
#define IMGL_POINT     2  // ��������
#define IMGL_TITLE     3  // �������
#define IMGL_VECTOR    4  // ���������
#define IMGL_MIXED     5  // ������� ������� (������)

// ��� ��p������ (��� IMG_SQUARECROSS)
#define SC_HORIZONTAL  1  // ��p������������ �������
#define SC_VERTICAL    2  // ��p���a������ �������
#define SC_QUADRATIC   3  // �����a��
#define SC_CROSS45     4  // ��� ����� 45 ��������
#define SC_CROSS135    5  // ��� ����� 135 ��������

// ���� ��������� ������� (��� SCR_VECTOR)
#define VT_THICK2      2  // ����� ������� 2
#define VT_THICK3      3  // ����� ������� 3
#define VT_THICK4      4  // ����� ������� 4
#define VT_THICK5      5  // ����� ������� 5
#define VT_CIRCLE2     8  // ���������� ������� 2
#define VT_CIRCLE3     9  // ���������� ������� 3
#define VT_CIRCLE4    10  // ���������� ������� 4
#define VT_CIRCLE5    11  // ���������� ������� 5

// ���� ��������� ������� (IMG_VECTOREX)
#define VT_SQUARE      0  // �������
#define VT_LINE        1  // �����
#define VT_ROUND       6  // ���� (�������)
#define VT_CIRCLE      7  // ����������
#define VT_FREE       12  // ������� �� ����������

// ���� ��������� ������� (IMG_VECTOREX)
#define VT_ELLIPSE    64  // ������
#define VT_OVAL       65  // ������ (�������)
#define VT_ARC        66  // ������� ���� ����
#define VT_PIE        67  // ������ (�������)
#define VT_TEXT       68  // ������� ���� ����� (����������)
#define VT_STEXT      69  // ������� ���� ����� (�� ���������)
#define VT_ARC_REVERT 70  // ������� ���� ����

// ���� ��������� ������� ��� �������� ��������� �����
#define VT_OBJECT    101  // ������ �����
#define VT_SUBJECT   102  // ������ ����������
#define VT_END       103  // ����� �����

// �������� ��������� �������� � ������� � �������
#define MKMINPIX     250  //  1000 * 25.4 / 96 = 264.583333
#define PIX2MKM(pixel)  (((long int)(pixel))  * MKMINPIX)
#define MKM2PIX(metric) (((long int)(metric)) / MKMINPIX)

//------------------------------------------------------------------
// ��� IMG_FONT
//------------------------------------------------------------------

// ���������� ���� (���� ��� ����)
#define UNIC_TRANSPARENT  255

// ������������� ������ �������
#define UNIW_NORMAL       0  // ����������
#define UNIW_NARROW       1  // �������
#define UNIW_WIDE         2  // �������

// ������������ �� ���������
#define UNIA_BASELINE     0  // �� ������� �����
#define UNIA_TOP          1  // �� �����
#define UNIA_BOTTOM       2  // �� ����

// ������������ �� �����������
#define UNIA_LEFT         0  // �� ������ ����
#define UNIA_CENTER       1  // �� ������
#define UNIA_RIGHT        2  // �� ������� ����

// ���������� ���������� ������ ������� � ��������
#define CharMin  5  // ������� ������� < CharMin, �� ������������
                    // 5 - 25/10/99

// ������������� ������ ������� (mapgds.h)
//  UNIW_NORMAL     - ����������
//  UNIW_NARROW     - �������
//  UNIW_WIDE       - �������

#ifdef LINUXAPI  // 23/04/01
// ��� ������, ������� ������� (Windows-���������)
//  FW_THIN         - ������
//  FW_ULTRALIGTH   - ������
//  FW_NORMAL       - �������
//  FW_MEDIUM       - ����������
//  FW_BOLD         - �������
#define FW_DONTCARE         0
#define FW_THIN             100
#define FW_EXTRALIGHT       200
#define FW_LIGHT            300
#define FW_NORMAL           400
#define FW_MEDIUM           500
#define FW_SEMIBOLD         600
#define FW_BOLD             700
#define FW_EXTRABOLD        800
#define FW_HEAVY            900

#define FW_ULTRALIGHT       FW_EXTRALIGHT
#define FW_REGULAR          FW_NORMAL
#define FW_DEMIBOLD         FW_SEMIBOLD
#define FW_ULTRABOLD        FW_EXTRABOLD
#define FW_BLACK            FW_HEAVY

#endif // LINUXAPI


// ������������ �� ����������� (Windows-���������)
#define FA_LEFT      0     // ����� = TA_LEFT       // 14/09/00
#define FA_RIGHT     2     // ������ = TA_RIGHT     // 14/09/00
#define FA_CENTER    6     // �� ������ = TA_CENTER // 14/09/00

// ������������ �� ��������� (Windows-���������)
#define FA_TOP       0     // ������ = TA_TOP       // 14/09/00
#define FA_BOTTOM    8     // ����� = TA_BOTTOM     // 14/09/00
#define FA_BASELINE  24    // �� ������� ����� = TA_BASELINE  // 14/09/00
#define FA_MIDDLE    4120  // �� ������� ����� = (TA_BASELINE|0x01000) // 14/09/00

// ����� ������� ������������
#define FA_MASK     (FA_CENTER | FA_MIDDLE)         // 23/04/03


// ���� ������������ ������ (����������, � ������� �������)
#define CA_BASELINE_LEFT          20
#define CA_BASELINE_RIGHT         21
#define CA_BASELINE_CENTER        22

#define CA_MIDDLE_LEFT            23
#define CA_MIDDLE_RIGHT           24
#define CA_MIDDLE_CENTER          25

#define CA_TOP_LEFT               26
#define CA_TOP_RIGHT              27
#define CA_TOP_CENTER             28

#define CA_BOTTOM_LEFT            29
#define CA_BOTTOM_RIGHT           30
#define CA_BOTTOM_CENTER          31

// �������� ����� ������������ ������
#define CA_MINCODE  CA_BASELINE_LEFT
#define CA_MAXCODE  CA_BOTTOM_CENTER

// ������� �������� (Windows-���������)
//  RUSSIAN_CHARSET - ��� ������ (ANSI/WINDOWS)
//  OEM_CHARSET     - ��� ������ (OEM/866/DOS)
//------------------------------------------------------------------

//******************************************************************
//               ��������� ���������� ������������                 *
//******************************************************************
//      ��� ������� (�������, �����, ���������� ...) � ��������    *
//                 (� �������� ����� ����������)                   *
//******************************************************************
// ����������:                                                     *
//  1. ���� � ������� COLORREF (0x00BBGGRR) ��� ����� �������      *
//     ������� ����� � ������� �����, ���� ������� ���� ����� 0x0F *
//  2. ��� �������� �������� � ������ ������ (��������)            *
//     ������������ �������� PIX2MKM(����� ��������):              *
//     Parm->Thick = PIX2MKM(2);  (������� 2 �������)              *
//******************************************************************

typedef struct IMGLINE           // (128) �����
{                                //      (size = 8)
  unsigned long Color;           // ���� ����� (COLORREF)
  unsigned long Thick;           // ������� �����
}
  IMGLINE;

typedef struct IMGTHICKENLINE    // (162,163) ������������ �����
{                                //      (size = 12)
  unsigned long Color;           // ���� ����� (COLORREF)
  unsigned long Thick;           // ������� �����������
  unsigned long Thick2;          // ������� ������������ (���������)
}
  IMGTHICKENLINE;

typedef struct IMGDOT            // (129) ���������� �����
{                                //      (size = 16)
  unsigned long Color;           // ���� �����
  unsigned long Thick;           // ������a ��p���
  unsigned long Dash ;           // ����� ��p���
  unsigned long Blank;           // ����� �p�����
}
  IMGDOT;

typedef struct IMGSQUARE         // (135) ��������� ��'���
{                                //      (size = 4)
  unsigned long Color;           // ���� �������
}
  IMGSQUARE;



typedef struct IMGCIRCLE         // (140) ����������
{                                //      (size = 12)
  unsigned long Color ;          // ���� ����������
  unsigned long Thick ;          // ������� �����
  unsigned long Radius;          // ������ ����������
}
  IMGCIRCLE;


typedef struct IMGTEXT           // (142) �����                   // 30/01/01
{                                //      (size = 32)
  unsigned long  Color       ;   // ���� ������
  unsigned long  BkgndColor  ;   // ���� ���� (IMGC_TRANSPARENT - ����������)
  unsigned long  ShadowColor ;   // ���� ���� (IMGC_TRANSPARENT - ����������)
  unsigned long  Height      ;   // ������ (��� ������������ �� �������
                                 // �� ��������� 1800 ���)
  unsigned long  Weight      ;   // ��� ������, ������� ������� (FW_THIN, ...)
  unsigned short Align       ;   // ������������ (FA_LEFT|FA_BASELINE, ...)
  unsigned short Service     ;   // ����� 0
  unsigned char  Wide        ;   // ������������� ������ ������� (UNIW_NORMAL, ...)
  unsigned char  Horizontal  ;   // ������� ��������������� ������������ (0/1)
  unsigned char  Italic      ;   // ������� ������� �������� (0/1)
  unsigned char  Underline   ;   // ������� �������������    (0/1)
  unsigned char  StrikeOut   ;   // ������� ��������������   (0/1)
  unsigned char  Type        ;   // ��� ������ (����� � �������: 0,1,2,3,4)
  unsigned char  CharSet     ;   // ������� �������� (RUSSIAN_CHARSET, ...)
  unsigned char  Flag        ;   // ����� ��� ������ :
                                 // 1 - ������� ������������ �� �������
}
  IMGTEXT;

#define IMGTEXT_SCALE  1
#define IMGTEXT_SHOWCODE 2                       // 21/07/06

typedef IMGTEXT IMGFONT;


typedef struct IMGMARKCHAIN      // �������� ��������� ��'��� �������
{                                //      (size = 4 + 128 = 132)
  unsigned long Color    ;       // ���� �����
  unsigned char Bits[128];       // ��������� ����������� 32x32 � �������� ����
}
  IMGMARKCHAIN;


typedef struct IMGMULTIMARK      // (143) ������������ ��������
{                                //      (size = 20 + 132*Count)
  unsigned long Length;          // ������ ����� ������ �������� �������
  unsigned long Count ;          // ����� ������ � �����
  unsigned long Size  ;          // ������ � �������� (��� ������)
  unsigned long PosV  ;          // ����� �������� ����� PosV,PosH  <  Size
  unsigned long PosH  ;          //  (��� IMGMULTISQUAREMARK - ��� ����� >= Size)
                                 // �����: Count �������� ���� IMGMARKCHAIN
}
  IMGMULTIMARK;


typedef struct IMGMULTISQUAREMARK// (144) ��������� + ������������ ��������
{                                //      (size = 4 + 20+132*Count )
  unsigned short Kind    ;       // ��� ����� ���������� 4x4 (16 ���)
                                 //  (IMGK_REGULAR, ...)
  unsigned char  FullMark;       // ���� ����������
                                 //  0 - �� ���� �������
                                 //  1 - ������ ������� �������
  unsigned char  Weight  ;       // ��� �����, ������� �������   // 27/04/00
                                 //  0 - ������
                                 //  1 - ����������
  IMGMULTIMARK   Mark    ;       // (143) ������������ ��������
                                 // �����: Count �������� ���� IMGMARKCHAIN
}
  IMGMULTISQUAREMARK;


typedef struct IMGDECOR          // ��������� ����� ����������
{
  unsigned short Length;         // ����� ���������� >= 4
                                 // (������� sizeof(IMGDECOR))
  unsigned short Number;         // ����� �������
}
  IMGDECOR;

// ����� ��� ������ ����������   // 28/07/00
#define IMGD_SPLINE       0x0001 // ���� ��������� �� ���������� �������

typedef struct IMGDRAW           // (147) ����� ����������
{
  unsigned long Ident   ;        // ������������� ������ 0x7FFF7FFFE
  unsigned long Length  ;        // ������ ����� ������ �������� �������
  unsigned short Count  ;        // ���������� ����������
  unsigned short Flags  ;        // ������ ���� 0
  IMGDECOR      Image   ;        // ��������� ������� ���������
  unsigned long Parm[1] ;        // ��������� ��������� �� ����
                                 // ����� ��������� � ���������
                                 // ��������� ����������
} IMGDRAW;

typedef IMGDRAW  SCRDRAW ;

typedef struct IMGDOTSHIFT       // (148) ������� ���������
{                                //
  IMGDOT    Dot   ;              // �������
  long      Shift ;              // ����������� � �������� ������
                                 // 0 - ������� ����� ������ �������� � ���
                                 // > 0 ���������� ������ �� ���,����� �����
                                 // ��� ������ = - ������ ������� ����� �����
                                 // �������� �  ���
}
 IMGDOTSHIFT;

typedef IMGDOTSHIFT SCRDOTSHIFT;

typedef struct IMGVECTPOINT      // ��� (149) �������� ����� �������
{                                //      (size = 8)
  long Hor;                      // ���������� �� ����� ��������
  long Ver;                      // ������ � ���� � ������������
                                 // � ����� �������:
                                 //  �����  �������  ����� ������ � ���������
                                 // Circle, Round  (h,v)  (dh,dh)
                                 // Ellipse, Oval  (h,v)  (dh,dv)
                                 // Arc,      Pie  (h,v)  (dh,dv) (h1,v1)(h2,v2)
}
  IMGVECTPOINT;


typedef struct IMGPOLYDESC       // ��� (149) �������� �������
{                                //      (size = 12 + 8*Count + Length)
  unsigned char  Type    ;       // ��� ������� (VT_SQUARE, ...)
                                 // ��� ��������� ����� VT_OBJECT,
                                 // VT_SUBJECT, VT_END)
  unsigned char  Image   ;       // ��� ����������
                                 // (IMG_SQUARE, IMG_LINE, IMG_DOT,
                                 // IMG_VECTORTEXT)                 // 11/04/05
  unsigned short Length  ;       // ����� ���������� (>= 4)
  unsigned long  Parm    ;       // ��������� ������� �� �� ����
  unsigned long  Count   ;       // ����� ����� � �������
  IMGVECTPOINT   Point[1];       // ���������� �� 512 �����
}
  IMGPOLYDESC;

typedef struct IMGVECTOREX       // (149,156) ��������� ���������� ��'����
{                                //      (size = 20 + ...)
  long Length      ;             // ������ ����� ������ �������� �������
  long PosV        ;             // ����� �������� ����� �� ���������
  long PosH        ;             //  � ����������� (��������� ������ �����)
  long Base        ;             // ����� ������� ������ ����� �����
  long VLine1      ;             // ������ ������� �� ���������  (0)
  long VLine2      ;             // �����  ������� �� ���������  (VSize)
  long VSize       ;             // ��������� ������ ������� �� ���������
  long HLine1      ;             // ������ ������� �� ����������� (0)
  long HLine2      ;             // ����� ������� �� �����������  (HSize)
  long HSize       ;             // ��������� ������ ������� �� �����������
  char Static      ;             // 1 - �������������� ������������
                                 // 0 - �� �������
  char Mirror      ;             // ���� ����������� ����������� �����
                                 // � ����������� ������ ����� �������
  char NoPress     ;             // ������� ������� ������ �����
  char Scale       ;             // ������� ������������ �� �������
  char Centre      ;             // ������� ������������� �� �������
  char Reserve[3]  ;             // ������
  long Border      ;             // �������� ����� �� ������� � ��� ��� 0
  long Count       ;             // ����� ����������,����������� ����
  IMGPOLYDESC  Desc;             // �������� ���������
}
  IMGVECTOREX;                   // �� �� ��� IMG_VECTOREXTURN (156)

typedef struct TABLETEMPLATE     // ���������� ����� ���������� �������
{
  long Length  ;                 // ����� ���������
  int Order[12];                 // ������ � ����������
                                 // 0-������ ������
                                 // -1 �����  -2 ����
                                 // >0  ����� ��������� �������  (�����)
  long Origin  ;                 // ����� ������ ��������
  long Static  ;                 // 1 - �������������� ������������
                                 // 0 - �� �������
}
  TABLETEMPLATE;

typedef struct IMGTEMPLATE       // (150) ��������� ���������� �������
{                                //      (size = 20 + ...)
  long Length               ;    // ������ ����� ������ �������� �������
  TABLETEMPLATE Table       ;    // ���������� ����� ���������� �������
  long          Count       ;    // ���������� ����������
  IMGDECOR      Text        ;    // ��������� ������
  unsigned long Parmtext[1] ;    // ��������� ������
  IMGDECOR      Line        ;    // ��������� �����
  unsigned long Parmline[1] ;    // ��������� �����
  IMGDECOR      Mark        ;    // ��������� �����
  unsigned long Parmmark[1] ;    // ��������� �����
}
  IMGTEMPLATE;

typedef struct IMGTRUETYPE       // (151) ��������� ����� �� TRUETYPE ������
{
  IMGTEXT Text     ;             // ��������� ������
  char FontName[32];             // �������� �������� ������
  long Number      ;             // ����� ����� � ������
  long MinV        ;             // �������� �����
  long MinH        ;             //  ������������ ����� ��������
  long MaxV        ;             // (0,0)
  long MaxH        ;             // (H,H/2) - ��������� ��������
  long PosV        ;             // ����� �������� ����� �� ���������
  long PosH        ;             // � ����������� (0,0)
}
  IMGTRUETYPE;

typedef struct IMGTRUETEXT       // (152) �����
{                                //      (size = 64)
  IMGTEXT Text     ;             // ��������� ������ (���� Type - �����������)
  char FontName[32];             // �������� �������� ������
}
  IMGTRUETEXT;


typedef struct IMGHATCHSQUARE    // (153) ������������ ���������
{
  long int Length;               // ������ ����� ������ �������� �������,
                                 // ������� ��������� ��������� �����
  long int Angle ;               // ���� ������� ��������� � �������� (0 - 180)
                                 // ������ ������� ������� �� �����������
  long int Step  ;               // ���������� ����� ����� ��������� �����
  long int Number;               // ����� ������� ��������� ����� (IMGLINE ��� IMGDOT)
                                 // �����: ��������� ��� ��������� �����
} IMGHATCHSQUARE ;


typedef struct IMGSQUAREGLASS    // (154) ��������� ��'��� - ������
{                                //      (size = 8)
  signed long Bright;            // ������� ��������� ������� (+/- 100)
  signed long Contrast;          // ������� ��������� ��������� (+/- 100)
}
  IMGSQUAREGLASS;

typedef struct IMGSQUAREVECTOR   // (155) ��������� + ���������
{                                //
  long           Length  ;       // ����� ���������
  unsigned short Kind    ;       // ��� ����� ���������� 4x4 (16 ���)
                                 //  (IMGK_REGULAR, ...)
  unsigned char  FullMark;       // ���� ����������
                                 //  0 - �� ���� �������
                                 //  1 - ������ ������� �������
  unsigned char  Reserv  ;       // ������ ���� 0
  long           StepHor ;       // ���������� ����� ������� �� �����������
  long           StepVer ;       // ���������� ����� ������� �� ���������
  long           Angle   ;       // ���� �������� ����� �� ��������� �� �������
  IMGVECTOREX    Mark    ;       // �������� �����
}
  IMGSQUAREVECTOR;


#define DO_BASE      1           // ������� ������ (����� ���� �������)
                                 // ������� ����������� �������
#define DO_FIRST     2           // �� ������ �����
#define DO_END       3           // �� ��������� �����
#define DO_LEFT      4           // ����� �� ������ �����
#define DO_RIGHT     5           // ������ �� ������ �����
#define DO_MIDDLE1   6           // ����� ����� (1 - �����������)
#define DO_MIDDLE2   7           // ����� ����� (2 - �����������)


typedef struct IMGDECORHEAD      // ��������� ������������ ���������
{
  unsigned long Length      ;    // ������ ����� ������ �������� �������
           long Begin       ;    // ����� ������ �����
           long End         ;    // ����� ����� �����
           long Left        ;    // ����� ������ �������
           long Right       ;    // ����� ����� �������
           long First       ;    // ����� ������� ������������ �����
           long Second      ;    // ����� ������� ������������ �����
           char Equidistant ;    // ���������� ��������� �� ���� �����
           char Reserv[3]   ;    // ������ - ����� 0
}
  IMGDECORHEAD;

typedef struct IMGDECORATE        // (157) ����������� ��������
{
  IMGDECORHEAD   Head         ;   // ���������
  IMGDECOR       Base         ;   // ��������� ������� �������
  unsigned long  BaseParm[1]  ;   // ��������� ������� �� ����
  IMGDECOR       Begin        ;   // ��������� ���������� ����� �����
  unsigned long  BeginParm[1] ;   // ��������� �� ����
  IMGDECOR       End          ;   // ��������� ���������� ����� �����
  unsigned long  EndParm[1]   ;   // ��������� �� ����
  IMGDECOR       Left         ;   // ��������� ���������� ����� �������
  unsigned long  LeftParm[1]  ;   // ��������� �� ����
  IMGDECOR       Rigth        ;   // ��������� ���������� ����� �������
  unsigned long  RigthParm[1] ;   // ��������� �� ����
  IMGDECOR       First        ;   // ��������� ������� ����� ����� �������
  unsigned long  FirstParm[1] ;   // ��������� �� ����
  IMGDECOR       Second       ;   // ��������� ������� ����� ����� �������
  unsigned long  SecondParm[1];   // ��������� �� ����
}
  IMGDECORATE;

typedef struct IMGSECTION     // �������� ��������� ������ ��� (158)
{
  unsigned long Length;       // ����� ���������� (������� IMGSECTION)
  unsigned long Number;       // ����� �������(IMG_EMPTY, IMG_LINE, IMG_VECTOREX,
                              //               IMG_TRUETYPE)
  unsigned long Base;         // ����� �������, ���������� �������
  unsigned long Parm[1];      // ���������
}
  IMGSECTION;

typedef struct IMGDASH           // (158) �������� ��������� �����
{
  long int    Length;            // ������ ����� ������ �������� �������,
  long int    Count;             // ����� ��������� ������ (�������, ��������, ������)
  long int    Last;              // ���������� ����� ������ (�� 0 �� Count-1),
                                 // ����������� ������ �������
  long int    Border;            // ������������ ������� ������
  long int    Reserve;           // ������
  IMGSECTION  Section[1];        // �������� ��������� ������
}
  IMGDASH;

typedef struct IMGLINESHIFT      // (159) C�������� �����
{
  long int    Length;            // ������ ����� ������ �������� �������,
  long int    Shift;             // ����������� � �������� ������
                                 // = 0 - ����� ����� ����� ��� �������
                                 // > 0 - ����� ������ �� ���, ����� �����
  IMGDECOR    Head;              // ��������� �����
  long int    Parm[1];           // ��������� ����� �� �� ����
}
  IMGLINESHIFT;

typedef struct IMGVECTORTEXT     // (160) ��������� ������� ���������� (VT_TEXT)
{                                // (size = 68)
  IMGTEXT  Text     ;            // ��������� ������
  long int Code     ;            // ��� ��������� �������, ��� ������ �����������
                                 // ������ ��� 0 ��� ����������� ������
  char     Title[32];            // ���������� �����
}
  IMGVECTORTEXT;

typedef struct IMGSQUAREGLASSCOLOR // (164) ��������� ��'��� - ������� ������
{                                  // (size = 12)
         long Color;               // ���� ����������� (IMGC_TRANSPARENT - ����������)
  signed long Bright;              // ������� ��������� ������� (+/- 100)
  signed long Contrast;            // ������� ��������� ��������� (+/- 100)
}
  IMGSQUAREGLASSCOLOR;

typedef struct IMGLIBRARY        // (250) ��������� ��'����(������ ������������)
{
  long int Length  ;             // ������ ����� ������ �������� �������
  long int Code    ;             // ��� DLL (IML)
  long int Index   ;             // ������ DLL � ������ ���������
  long int Function;             // ��� �������
  IMGDRAW  Draw    ;             // ���������
}
  IMGLIBRARY;

typedef struct IMGDOUBLE         // (253) ��������� ��������� ���� DOUBLE
{
  double Value;
}
  IMGDOUBLE;

typedef struct IMGLONG           // (254) ��������� ��������� ���� LONG
{
  long Value;
}
  IMGLONG;

typedef struct IMGOBJECT         // (255) ����������/�������� ��'���
{                                //  � �������� ������ ��������������
                                 //      (size = 16)
  unsigned long Color ;          // ���� ��������� ������� �� �����
                                 //  (IMGC_NOMARK - �� ��������)
  unsigned long Incode;          // ���������� ��� �������
                                 //  (0 - ��������������� �� Excode � Local)
  unsigned long Excode;          // ������� ��� �������
  unsigned long Local ;          // ����������� ������� (IMGL_LINE, ...)

  // ��� ������� ���� PaintMapObject(...) Incode ���������������
  // �������������. ���� ��������� ������ �� �����, �� ������
  // ������ ��������� ����� ��������� ����.
}
  IMGOBJECT;



typedef struct IMGVECTORGRADIENT    // ��������������� ���������
{
  unsigned long Color;        // ���� ����������� ������� (COLORREF)
  unsigned long Left;         // ������� ���������� ��������� �����
  unsigned long Right;        // ������� ���������� ��������� ������
  unsigned long Bright;       // ������� ��������� ������� �������
}
  IMGVECTORGRADIENT;


//**********************************************************************
// ���������� ��������� ���������� ������������ (�������� �� IMGDRAW...)
//**********************************************************************

#define IMG_LINEDOT           130
#define IMG_DOUBLELINE        131
#define IMG_DOTDLINE          132
#define IMG_DOUBLEDOT         133
#define IMG_SHIFTLINEDOT      134
#define IMG_SQUARECROSS       136
#define IMG_MARK              137
#define IMG_SQUAREMARK        138
#define IMG_LEFTLINEDOT       145
#define IMG_DECORATELINE      146


typedef struct IMGLINEDOT        // (130) ������� �� �����
{                                //      (size = 24)
  IMGLINE Line;                  // ������ �����
  IMGDOT  Dot ;                  // ������� �����
}
  IMGLINEDOT;


typedef struct IMGDOUBLELINE     // (131) ����� �� �����
{                                //      (size = 16)
  IMGLINE OneLine;               // ������ �����
  IMGLINE TwoLine;               // ������� �����
}
  IMGDOUBLELINE;


typedef struct IMGDOTDLINE       // (132) ������� ����� �� ��������
{                                //      (size = 32)
  IMGDOT        Dot   ;          // ������ �����
  IMGDOUBLELINE Double;          // ������� �����
}
  IMGDOTDLINE;


typedef struct IMGDOUBLEDOT      // (133) ������� �������
{                                //      (size = 32)
  IMGDOT OneDot;                 // ������ �����
  IMGDOT TwoDot;                 // ������� �����
}
  IMGDOUBLEDOT;


typedef struct IMGSHIFTLINEDOT   // (134) �������, ��������� ������, �� �����
{                                //      (size = 24)
  IMGLINE Line;                  // ������ �����
  IMGDOT  Dot ;                  // ������� �����-�������
}
  IMGSHIFTLINEDOT;


typedef struct IMGSQUARECROSS    // (136) ������������ �������
{                                //      (size = 16)
  unsigned long Color;           // ���� ��p������ (IMGC_TRANSPARENT - ����������)
  unsigned long Kind ;           // ��� ��p������ (SC_HORIZONTAL, ...)
  unsigned long Thick;           // ������a ��p��a
  unsigned long Blank;           // ������a �p����a
}
  IMGSQUARECROSS;

typedef struct IMGMARK           // (137) �������� ��������� ��'���
{                                //      (size = 16 + 128 = 144)
  unsigned long Color    ;       // ���� �����
  unsigned long Size     ;       // ������ � �������� (��� ������)
  unsigned long PosV     ;       // ����� �������� ����� PosV,PosH < Size
  unsigned long PosH     ;       //  (��� IMGSQUAREMARK - ��� ����� >= Size
  unsigned char Bits[128];       // ��������� ����������� 32x32 � �������� ����
}
  IMGMARK;

typedef struct IMGSQUAREMARK     // (138) ��������� + ��������
{                                //      (size = 8 + 144 = 152)
  unsigned long  Color   ;       // ���� ���� (IMGC_TRANSPARENT - ����������)
  unsigned short Kind    ;       // ��� ����� ���������� 4x4 (16 ���)
                                 //  (IMGK_REGULAR, ...)
  unsigned char  FullMark;       // ���� ����������
                                 //  0 - �� ���� �������
                                 //  1 - ������ ������� �������
  unsigned char  Weight  ;       // ��� �����, ������� �������   // 27/04/00
                                 //  0 - ������
                                 //  1 - ����������
  IMGMARK        Mark    ;       // �������� �����
}
  IMGSQUAREMARK;



typedef struct IMGLEFTLINEDOT    // (145) �������, ��������� �����, �� �����
{                                //      (size = 24)
  IMGLINE Line;                  // ������ �����
  IMGDOT  Dot ;                  // ������� �����-�������
}
  IMGLEFTLINEDOT;


typedef struct IMGDECHEAD        // ��������� ������������ ���������
{
  unsigned long Length   ;       // ������ ����� ������ �������� �������
           long Distance ;       // ���������� ����� ������������ �������.
}
 IMGDECHEAD;
                                 // ������ �� ���������� � ������
                                 //
typedef struct IMGDECORATELINE   // (146) ����������� ��������
{
  IMGDECHEAD     Head        ;   // ���������
  IMGDECOR       Base        ;   // ��������� ������� �������
  unsigned long  BaseParm[1] ;   // ��������� ������� �� ����
  IMGDECOR       First       ;   // ��������� ����������
  unsigned long  FirstParm[1];   // ��������� �� ����
  IMGDECOR       End         ;   // ��������� ���������
  unsigned long  EndParm[1]  ;   // ��������� �� ����
  IMGDECOR       Left        ;   // ��������� ������
  unsigned long  LeftParm[1] ;   // ��������� �� ����
  IMGDECOR       Rigth       ;   // ��������� �������
  unsigned long  RigthParm[1];   // ��������� �� ����
  IMGDECOR       Middle1     ;   // ��������� ������� ������������
  unsigned long  Mid1Parm[1] ;   // ��������� �� ����
  IMGDECOR       Middle2     ;   // ��������� ������� ������������
  unsigned long  Mid2Parm[1] ;   // ��������� �� ����
}
  IMGDECORATELINE;

                                 // ( ) ����������� ��������
typedef IMGDECORATELINE SCRDECORATELINE;
                                 // ����� ��������� ������ ���������
                                 // �������� ��������� �����


#endif  // MAPGDI_H

