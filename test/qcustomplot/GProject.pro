TEMPLATE = app
TARGET = rdcpp
QT += widgets printsupport
CONFIG += release console gnu++11

INCLUDEPATH +=\
    $$PWD

SOURCES +=\
    main.cpp \
    qcustomplot.cpp

HEADERS +=\
    qcustomplot.h
