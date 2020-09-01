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
    void basisPointDraw(double x, double y);
    void basisLineDraw(double x1, double y1, double x2, double y2);
    void basisFunctionDraw(void* func, void* params);
    
public:
    static GOpenCVSysMgr* m_instance;
    //
    cv::Mat m_window;
    std::string m_title;
    cv::Scalar m_bgColor;
    cv::Scalar m_gridColor;
    cv::Scalar m_axisColor;
    cv::Scalar m_pointColor;
    cv::Scalar m_lineColor;
    int m_delay;
    double m_pointSize;
    double m_lineWidth;
    double m_width;
    double m_height;
    double m_gridDiv;
    double m_x0;
    double m_y0;
    double m_xMin;
    double m_xMax;
    double m_yMin;
    double m_yMax;
    double m_xTick;
};
//===============================================
#endif
//===============================================
