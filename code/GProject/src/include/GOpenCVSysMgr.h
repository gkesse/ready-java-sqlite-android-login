//===============================================
#ifndef _GOpenCVSysMgr_
#define _GOpenCVSysMgr_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCVSysMgr {
private:
    GOpenCVSysMgr();
    
public:
    ~GOpenCVSysMgr();
    static GOpenCVSysMgr* Instance();
    //
    void systemOpen();
    void systemClose();
    //
    void imageLoad(std::string imgFile);
    
private:
    void imageRatioKeep(cv::Mat img, cv::Mat& out, double refW, double refH, double& outW, double &outH);

private:
    static void* onSystemOpen(void* params);
    
public:
    static GOpenCVSysMgr* m_instance;
};
//===============================================
#endif
//===============================================
