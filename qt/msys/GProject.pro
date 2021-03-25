TEMPLATE = app
TARGET = $$(GPROJECT_EXE)
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build
CONFIG += console release gnu++11
QT += widgets

include($$(GPROJECT_SRC)/GMain.pri)

QMAKE_CXXFLAGS +=\
    -Wno-unused-parameter \
    -Wno-deprecated-declarations \
