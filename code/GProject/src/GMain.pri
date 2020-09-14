INCLUDEPATH += \
    $$PWD/include \    

HEADERS += \
    $$PWD/include/GWindow.h \
    $$PWD/include/GAdminQt.h \
    $$PWD/include/GSQLiteQt.h \
    $$PWD/include/GOpenCVQt.h \

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/manager/GProcess.cpp \
    $$PWD/manager/GManager.cpp \
    $$PWD/manager/GConfig.cpp \
    $$PWD/manager/GSQLite.cpp \
    $$PWD/manager/GSQLiteMgr.cpp \
    $$PWD/manager/GOpenCV.cpp \
    $$PWD/manager/GOpenCVMgr.cpp \
    $$PWD/manager/GOpenCVSys.cpp \
    $$PWD/manager/GOpenCVSysMgr.cpp \
    $$PWD/manager/GFunction.cpp \
    $$PWD/manager/GQtUi.cpp \
    $$PWD/manager/GQtMgr.cpp \
    $$PWD/manager/GJson.cpp \
    $$PWD/manager/GWindow.cpp \
    $$PWD/manager/GAdminQt.cpp \
    $$PWD/manager/GSQLiteQt.cpp \
    $$PWD/manager/GOpenCVQt.cpp \

RESOURCES += \
    ../res/resources.qrc
