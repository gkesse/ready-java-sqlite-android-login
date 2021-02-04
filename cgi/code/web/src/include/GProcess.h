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
    virtual ~GProcess();
    static GProcess* Instance();
    void run(int argc, char** argv);
    void runWeb(int argc, char** argv);
    void runImg(int argc, char** argv);
    
private:
    static GProcess* m_instance;
};
//===============================================
#endif
//===============================================
