INCLUDEPATH +=\
    $$PWD/include \
    /mingw32/include \
    /mingw32/include/opencv4 \
    
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
    $$PWD/manager/GWindow.cpp \
    $$PWD/manager/GJson.cpp \

LIBS += \
    -L/mingw32/lib -lopencv_gapi -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_bgsegm -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_highgui -lopencv_face -lopencv_fuzzy -lopencv_hdf -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_ovis -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_videostab -lopencv_videoio -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_video -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core -lopengl32 -lglu32 \
    -L/mingw32/lib -lsqlite3 -lz \
    -L/mingw32/lib -lgsl -lgslcblas -lm \
