# #####################################################################
# Bezier tool MultiFusion build script # #####################################################################
TEMPLATE = lib
TARGET = Bezier
CONFIG += plugin
DEPENDPATH += . \
    ./../../../pluginTool
INCLUDEPATH += . \
    ./../../../pluginTool \
    ./../../../interfaces
QT += xml \
    xmlpatterns \
    widgets
LIBS += -L./../../../pluginTool
DESTDIR = ./../../../bin/plugins/Bezier
HEADERS += Bezier.h \
    Plugin.h \
    FigureToolInterface.h \
    InterfacePlugin.h \
    ./../../../pluginTool/SignalHolder.h
SOURCES += Bezier.cpp
RESOURCES += Bezier.qrc
