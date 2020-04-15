SOURCES += \
    $$PWD/GShell.cpp \
    $$PWD/GExprTk.cpp \
    $$PWD/GMuParser.cpp \
    $$PWD/GGsl.cpp \
    $$PWD/GQCustomPlot.cpp \
    $$PWD/GProcess.cpp \
    $$PWD/GDebug.cpp \
    $$PWD/GStyle.cpp \
    $$PWD/GPicto.cpp \
    $$PWD/GWindow.cpp \
    $$PWD/GWindowMath.cpp \
    $$PWD/GWindowString.cpp \
    $$PWD/GWidget.cpp \
    $$PWD/GWidgetTitleBar.cpp \
    $$PWD/GWidgetLineEdit.cpp \
    $$PWD/GWidgetLineEditRun.cpp \
    $$PWD/GWidgetLineEditCheck.cpp \
    $$PWD/GWidgetTextEdit.cpp \
    $$PWD/GWidgetPushButton.cpp \

LIBS += \
    -lmuparser \
    -lgsl -lgslcblas -lm \
    