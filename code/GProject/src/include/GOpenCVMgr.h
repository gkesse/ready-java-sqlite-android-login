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
    //
    void basis();
    void basisPoint();
    void basisFunction();
    
private:
    void basisDraw();
    void basisPointDraw(int x, int y);
    void basisFunctionDraw();
    
public:
    static GOpenCVMgr* m_instance;
    //
    cv::Mat m_basis;
    cv::Scalar m_bgColor;
    cv::Scalar m_gridColor;
    cv::Scalar m_axisColor;
    cv::Scalar m_pointColor;
    std::string m_title;
    int m_width;
    int m_height;
    int m_gridDiv;
    int m_x0;
    int m_y0;
};
//===============================================
#endif
//===============================================
