//===============================================
#ifndef _GQtUi_
#define _GQtUi_
//===============================================
#include "GInclude.h"
//===============================================
class GQtUi {
private:
    GQtUi();
    
public:
    ~GQtUi();
    static GQtUi* Instance();
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
    void run_SYSTEM_OPEN(int argc, char** argv);
    void run_SYSTEM_CLOSE(int argc, char** argv);
    
public:
    static GQtUi* m_instance;
    std::string G_STATE;
    std::string G_SYSTEM;
};
//===============================================
#endif
//===============================================
