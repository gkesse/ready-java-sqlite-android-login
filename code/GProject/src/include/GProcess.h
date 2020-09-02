//===============================================
#ifndef _GProcess_
#define _GProcess_
//===============================================
#include "GInclude.h"
//===============================================
class GProcess {
private:
    GProcess();
    
public:
    ~GProcess();
    static GProcess* Instance();
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
    void run_SQLITE(int argc, char** argv);
    void run_OPENCV(int argc, char** argv);
    void run_OPENCV_SYS(int argc, char** argv);
    void run_QT(int argc, char** argv);

public:
    static GProcess* m_instance;
    std::string G_STATE;
};
//===============================================
#endif
//===============================================
