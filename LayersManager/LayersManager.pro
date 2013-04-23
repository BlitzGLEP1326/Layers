TARGET = LayersManager
TEMPLATE = lib
			
DESTDIR = $$PWD/../_bin
QT += core gui

DEFINES += LAYERS_MANAGER_DLL_EXPORT

SOURCES += \
    Manager.cpp

HEADERS  += \
    Manager.h \
    ILayer.h \
    dll.h
