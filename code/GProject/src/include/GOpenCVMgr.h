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
    void imageInvert(std::string imageFileIn);
    //
    void videoLoad(std::string videoFileIn);
    void videoTrackbar(std::string videoFileIn);

public:
    static GOpenCVMgr* m_instance;
};
//===============================================
#endif
//===============================================
