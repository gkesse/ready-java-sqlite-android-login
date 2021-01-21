//===============================================
#ifndef _GOpenCVUi_
#define _GOpenCVUi_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCVUi {
private:
    GOpenCVUi();
    
public:
    ~GOpenCVUi();
    static GOpenCVUi* Instance();
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
    void run_OPEN(int argc, char** argv);
    void run_CLOSE(int argc, char** argv);
    //
    void run_IMAGE_LOAD_IMAGE_PATH(int argc, char** argv);
    void run_IMAGE_LOAD_IMAGE_NAME(int argc, char** argv);
    void run_IMAGE_LOAD(int argc, char** argv);
    //
    void run_IMAGE_INVERT_IMAGE_PATH(int argc, char** argv);
    void run_IMAGE_INVERT_IMAGE_NAME(int argc, char** argv);
    void run_IMAGE_INVERT(int argc, char** argv);

public:
    static GOpenCVUi* m_instance;
    std::string G_STATE;
};
//===============================================
#endif
//===============================================
