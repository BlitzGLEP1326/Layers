TARGET = MapLayer
TEMPLATE = lib

DESTDIR = $$PWD/../_bin
QT += core gui

DEFINES += MAP_LAYER_DLL_EXPORT

HEADERS += \
	dll.h \
	MapLayer.h \
	MapImage.h \
	Map.h \
	Data.h \
	GisToolWrapper.h \
	ImageProperty.h \
	AbstractTileContainer.h

SOURCES += \
	MapLayer.cpp \
	MapImage.cpp \
	Map.cpp \
	Data.cpp \
	GisToolWrapper.cpp \
	ImageProperty.cpp \
	AbstractTileContainer.cpp

INCLUDEPATH += \
	$$PWD \
	$$PWD/../LayersManager

LIBS += \
	-L$$PWD/../_bin -lLayersManager \

unix::LIBS += \
	$$PWD/../Library/libqdmapacces24.so \
	$$PWD/../Library/libpq.so
win32::LIBS += \
	$$PWD/../Library/gisacces.lib

unix::INCLUDEPATH += \
	$$PWD/../Include/MapApi/Linux
win32::INCLUDEPATH += \
	$$PWD/../Include/MapApi/Windows
