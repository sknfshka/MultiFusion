# #####################################################################
# PolyChain tool MultiFusion build script # #####################################################################
TEMPLATE = lib
TARGET = PolyChain
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
DESTDIR = ./../../../bin/plugins/PolyChain
HEADERS += PolyChain.h \
    Plugin.h \
    FigureToolInterface.h \
    InterfacePlugin.h \
    ./../../../pluginTool/SignalHolder.h
SOURCES += PolyChain.cpp
RESOURCES += PolyChain.qrc
