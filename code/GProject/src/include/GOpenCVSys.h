//===============================================
#ifndef _GOpenCVSys_
#define _GOpenCVSys_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCVSys {
private:
    GOpenCVSys();
    
public:
    ~GOpenCVSys();
    static GOpenCVSys* Instance();
    void run(int argc, char** argv);
    
private:
    void run_ADMIN(int argc, char** argv);
    void run_INIT(int argc, char** argv);
    void run_METHOD(int argc, char** argv);
    void run_CHOICE(int argc, char** argv);
    void run_SAVE(int argc, char** argv);
    void run_LOAD(int argc, char** argv);
    void run_QUIT(int argc, char** argv);
    
private:
    void run_IMAGE_LOAD_IMAGE_PATH(int argc, char** argv);
    void run_IMAGE_LOAD_IMAGE_NAME(int argc, char** argv);
    void run_IMAGE_LOAD(int argc, char** argv);
    //
    void run_IMAGE_INVERT_IMAGE_PATH(int argc, char** argv);
    void run_IMAGE_INVERT_IMAGE_NAME(int argc, char** argv);
    void run_IMAGE_INVERT(int argc, char** argv);
    //
    void run_VIDEO_LOAD_VIDEO_PATH(int argc, char** argv);
    void run_VIDEO_LOAD_VIDEO_NAME(int argc, char** argv);
    void run_VIDEO_LOAD(int argc, char** argv);
    //
    void run_VIDEO_TRACKBAR_VIDEO_PATH(int argc, char** argv);
    void run_VIDEO_TRACKBAR_VIDEO_NAME(int argc, char** argv);
    void run_VIDEO_TRACKBAR(int argc, char** argv);
    //
    void run_BASIS(int argc, char** argv);
    void run_BASIS_POINT(int argc, char** argv);
    void run_BASIS_FUNCTION(int argc, char** argv);

public:
    static GOpenCVSys* m_instance;
    std::string G_STATE;
};
//===============================================
#endif
//===============================================
