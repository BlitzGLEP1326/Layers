#-------------------------------------------------
#
# Project created by QtCreator 2013-02-04T09:40:54
#
#-------------------------------------------------

QMAKE_CXXFLAGS_RELEASE += -MP5

TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS += \
	    LayersManager \
	    MapLayer \
	    SituationLayer \
	    MainWindow

MainWindow.depends = LayersManager
MainWindow.depends = MapLayer
MainWindow.depends = SituationLayer
