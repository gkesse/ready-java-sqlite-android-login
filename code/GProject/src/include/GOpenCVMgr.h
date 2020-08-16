//===============================================
#ifndef _GOpenCVMgr_
#define _GOpenCVMgr_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCVMgr {
private:
    GOpenCVMgr();
    
public:
    ~GOpenCVMgr();
    static GOpenCVMgr* Instance();
    void imageLoad(std::string imageFileIn);

public:
    static GOpenCVMgr* m_instance;
};
//===============================================
#endif
//===============================================
