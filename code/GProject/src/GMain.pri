GRLIB = /cygdrive/c/Users/Admin/Downloads/Programs/ReadyLib/dev

CONFIG += \
    _GUSE_QTAWESOME_ON_ \
    _GUSE_QCUSTOMPLOT_ON_ \
    _GUSE_GSL_ON_ \
    _GUSE_MUPARSER_ON_ \
    _GUSE_MUPARSERX_ON_ \
    _GUSE_EXPRTK_ON_ \

_GUSE_QTAWESOME_ON_ {include($$GRLIB/qtawesome/4.7.0/mingw/QtAwesome.pri)}
_GUSE_QCUSTOMPLOT_ON_ {include($$GRLIB/qcustomplot/2.0.1/mingw/GQCustomPlot.pri)}
_GUSE_EXPRTK_ON_ {include($$GRLIB/exprtk/1.0.0/mingw/GExprTk.pri)}
_GUSE_MUPARSERX_ON_ {include($$GRLIB/muparserx/4.0.8/unix64/GMuParserX.pri)}
_GUSE_OPENGL_ON_ {include($$GRLIB/glfw/3.3.0/mingw/GGLfw.pri)}

include(include/GInclude.pri)
include(manager/GManager.pri)

SOURCES += \
    $$PWD/main.cpp \

_GUSE_GSL_ON_ {LIBS += -lgsl -lgslcblas -lm}
_GUSE_EXPRTK_ON_ {LIBS += -lexprtk}
_GUSE_MUPARSER_ON_ {LIBS += -lmuparser}
_GUSE_MUPARSERX_ON_ {LIBS += -lmuparserx}
_GUSE_OPENCV_ON_ {LIBS += -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hdf -lopencv_hfs -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_shape -lopencv_stereo -lopencv_stitching -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_plot -lopencv_ml -lopencv_videostab -lopencv_video -lopencv_photo -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_flann -lopencv_xobjdetect -lopencv_imgcodecs -lopencv_objdetect -lopencv_xphoto -lopencv_imgproc -lopencv_core}


    