TARGET = Map
TEMPLATE = lib
			
DESTDIR = $$PWD/../_bin
QT += core gui sql xml

DEFINES += MAP_DLL_EXPORT

SOURCES += \
	Map.cpp \
	MapWindow.cpp \
   	ImageProperty.cpp \
  	HeightFinder.cpp \
  	MapsListWidget.cpp \
  	Data.cpp \
   	ConverterGeoToPlane.cpp \
   	ConverterGeoToGK.cpp \
   	ConverterPixelToPlane.cpp \
	PropertyWidget.cpp \
	Object.cpp \
	Layer.cpp \
	CompositionObject.cpp \
	ObjectsListWidget.cpp \
	Atlas.cpp \ 
	MapImage.cpp \
	GisToolWrapper.cpp \
	Scale.cpp \
	HistoryModel.cpp \
	ScaleWidget.cpp \
	MapInfoWidget.cpp \ 
	MapMenuWidget.cpp \
	TracePresenter/tracepresenter.cpp \
	TracePresenter/tracegraphicsitem.cpp \
	ZonePresenter/ZonePresenter.cpp \
	ZonePresenter/ZoneGraphicsItem.cpp \
    ConverterComposite.cpp \
    AbstractTileContainer.cpp \
    GistoolTileContainer.cpp
  
HEADERS += \
	Map.h \
	MapWindow.h \
   	ImageProperty.h \
   	HeightFinder.h \
   	MapsListWidget.h \
   	Data.h \
	Converter.h \
   	ConverterGeoToPlane.h \
   	ConverterGeoToGK.h \
	ConverterPixelToPlane.h \
	PropertyWidget.h \
	Object.h \
	CompositionObject.h \
	ObjectsListWidget.h \
	Atlas.h \ 
	MapImage.h \
	GisToolWrapper.h \
	Scale.h \
	HistoryModel.h \
	ScaleWidget.h \
	MapInfoWidget.h \
	MapMenuWidget.h \
	Line.h \	
	LibraryDeclaration.h \
	TracePresenter/tracepresenter.h \
	TracePresenter/tracegraphicsitem.h \
	ZonePresenter/ZonePresenter.h \
	ZonePresenter/ZoneGraphicsItem.h \
    AbstractTileContainer.h \
    ConverterComposite.h \
    GistoolTileContainer.h

RESOURCES += MapWindow.qrc

FORMS += \
	MapWindow.ui \
	MapsListWidget.ui \
	PropertyWidget.ui \
	ObjectsListWidget.ui \
	MapInfoWidget.ui \
	MapMenuWidget.ui \
	ScaleWidget.ui \	

unix::INCLUDEPATH += \
        $$PWD/../Include/MapApi/Linux
	
win32::INCLUDEPATH += \
    $$PWD/../Include/MapApi/Windows
	
unix::LIBS += $$PWD/../Library/libqdmapacces24.so
win32::LIBS += $$PWD/../Library/gisacces.lib
