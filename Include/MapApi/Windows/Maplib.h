/*** 17/01/2006 ****************************** Vitsko D.A.     *****
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*              Œœ–≈ƒ≈À≈Õ»≈ »Ã≈Õ ¡»¡À»Œ“≈  √»—-ﬂƒ–¿                 *
*                                                                  *
*******************************************************************/

#define GISLIB
//#define MAPLIB

// MAPLIB.H  ‰Îˇ GIS TOOLKIT
// --------------------------
#ifdef GISLIB

	#define MTRLIB      "GISMTREX.DLL"
	#define MAP43LIB    "GISACC43.DLL"
	#define MAPACCLIB   "GISACCES.DLL"
	#define MAPVECEXLIB "GISVECEX.DLL"
	#define MTLLIB      "GISMTLEX.DLL"
	#define MAPPICEXLIB "GISPICEX.DLL" 
	
	#define MAPPICTRLIB  "GISFORMS.DLL" 

	#define MAPRUSLIB    "GISFORMS.DLL"
	#define MAPENGLLIB   "GISFORMS.DLL"
	#define MAPSELECLIB  "GISFORMS.DLL"
	#define MAPOBJLIB    "GISFORMS.DLL"
	#define MAPLISTLIB   "GISFORMS.DLL"
	#define MAPEDFRM     "GISFORMS.DLL"  //17/01/2006

	#define MAPGPSLIB    "GISGPS.DLL"


#else
// MAPLIB.H  ‰Îˇ PANORAMA
// -----------------------
	#define MTRLIB      "MAPMTREX.DLL"
	#define MAP43LIB    "MAPACC43.DLL"
	#define MAPACCLIB   "MAPACCES.DLL"
	#define MAPVECEXLIB "MAPVECEX.DLL"
	#define MTLLIB      "MAPMTLEX.DLL"
	#define MAPPICTRLIB "MAPPICTR.DLL" 
	#define MAPPICEXLIB "MAPPICEX.DLL" 
	
	#define MAPRUSLIB    "MAPRUS.DLL"
	#define MAPENGLLIB   "MAPENGL.DLL"
	#define MAPSELECLIB  "MAPSELEC.DLL"
	#define MAPOBJLIB    "MAPOBJ.DLL"
	#define MAPLISTLIB   "MAPLIST.DLL"
	#define MAPEDFRM     "MAPEDFRM.DLL"  //17/01/2006

	#define MAPGPSLIB    "GPSTEST.DLL"


#endif