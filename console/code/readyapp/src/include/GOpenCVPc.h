//===============================================
#ifndef _GOpenCVPc_
#define _GOpenCVPc_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCVPc {
private:
    GOpenCVPc();
    
public:
    ~GOpenCVPc();
    static GOpenCVPc* Instance();
    void run(int argc, char** argv);
    
private:
    void runTest(int argc, char** argv);
    void runImageLoad(int argc, char** argv);

private:
    static GOpenCVPc* m_instance;
};
//===============================================
#endif
//===============================================
