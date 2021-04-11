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
    void runTest(int argc, char** argv);
    void runUi(int argc, char** argv);
    void runOpenCV(int argc, char** argv);

private:
    static GProcess* m_instance;
};
//===============================================
#endif
//===============================================
