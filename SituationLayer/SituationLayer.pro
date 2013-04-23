TARGET = SituationLayer
TEMPLATE = lib

DESTDIR = $$PWD/../_bin
QT += core gui

DEFINES += SITUATION_LAYER_DLL_EXPORT

HEADERS  += \
    dll.h \
    SituationLayer.h

SOURCES  += \
    SituationLayer.cpp

INCLUDEPATH += \
	$$PWD \
	$$PWD/../LayersManager

LIBS += \
	-L$$PWD/../_bin -lLayersManager \
