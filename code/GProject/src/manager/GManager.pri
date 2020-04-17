SOURCES += \
    $$PWD/GShell.cpp \
    $$PWD/GDir.cpp \
    $$PWD/GExprTk.cpp \
    $$PWD/GMuParser.cpp \
    $$PWD/GGsl.cpp \
    $$PWD/GCMocka.cpp \
    $$PWD/GOpenCV.cpp \
    $$PWD/GOpenGL.cpp \
    $$PWD/GQCustomPlot.cpp \
    $$PWD/GProcess.cpp \
    $$PWD/GDebug.cpp \
    $$PWD/GStyle.cpp \
    $$PWD/GPicto.cpp \
    $$PWD/GWindow.cpp \
    $$PWD/GWindowMath.cpp \
    $$PWD/GWidget.cpp \
    $$PWD/GWidgetTitleBar.cpp \
    $$PWD/GWidgetLineEdit.cpp \
    $$PWD/GWidgetLineEditRun.cpp \
    $$PWD/GWidgetLineEditCheck.cpp \
    $$PWD/GWidgetTextEdit.cpp \
    $$PWD/GWidgetPushButton.cpp \

LIBS += \
    -lcmocka \
    -lmuparser \
    -lgsl -lgslcblas -lm \
    -lopencv_core2413 -lopencv_highgui2413 -lopencv_imgproc2413 \
    -lglfw3 -lopengl32 -lgdi32 \
    