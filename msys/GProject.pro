TEMPLATE = app
TARGET = gp_cpp
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build
CONFIG += console release gnu++11
QT += widgets script printsupport dbus
RESOURCES += resources.qrc

include(../code/GProject/src/GMain.pri)
