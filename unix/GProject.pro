TEMPLATE = app
TARGET = gp_cpp
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build
CONFIG += console release c++17
QT += widgets script
RESOURCES += resources.qrc

include(../code/GProject/src/GMain.pri)
