//===============================================
#ifndef _GOpenCV_
#define _GOpenCV_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCV {
private:
    GOpenCV();
    
public:
    ~GOpenCV();
    static GOpenCV* Instance();
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
    void run_VIDEO_LOAD(int argc, char** argv);

public:
    static GOpenCV* m_instance;
    std::string G_STATE;
};
//===============================================
#endif
//===============================================
