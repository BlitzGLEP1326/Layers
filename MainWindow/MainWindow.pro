TARGET = MainWindow
TEMPLATE = app

DESTDIR = $$PWD/../_bin
QT += core gui

CONFIG += debug_and_release

#DEFINES += MAIN_WINDOW_DLL_EXPORT

SOURCES += \
    main.cpp \
    MainWindow.cpp

HEADERS  += \
    dll.h \
    MainWindow.h

FORMS += \
    MainWindow.ui
	
INCLUDEPATH += \
        $$PWD \
        $$PWD/../LayersManager \
        $$PWD/../MapLayer \
	$$PWD/../SituationLayer

unix::QMAKE_LFLAGS_DEBUG += \
                            "-Wl,-rpath,$$PWD/../Library/" \
                            "-Wl,-rpath,$$PWD/../_bin/"

unix::QMAKE_LFLAGS_RELEASE += \
                            "-Wl,-rpath,$$PWD/../Library/" \
                            "-Wl,-rpath,$$PWD/../_bin/"

LIBS += \
        -L$$PWD/../_bin -lLayersManager \
        -L$$PWD/../_bin -lMapLayer \
        -L$$PWD/../_bin -lSituationLayer

unix::LIBS += \
        $$PWD/../Library/libqdmapacces24.so \
        $$PWD/../Library/libpq.so

win32::LIBS += \
	$$PWD/../Library/gisacces.lib
