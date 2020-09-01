//===============================================
#include "GOpenCVSysMgr.h"
#include "GConfig.h"
#include "GFunction.h"
#include "GManager.h"
//===============================================
typedef double (*GFUNC_CB)(double x, void* params);
//===============================================
typedef struct _sGPoly sGPoly;
//===============================================
struct _sGPoly {
    double* coef;
    int size;
};
//===============================================
GOpenCVSysMgr* GOpenCVSysMgr::m_instance = 0;
//===============================================
GOpenCVSysMgr::GOpenCVSysMgr() {

}
//===============================================
GOpenCVSysMgr::~GOpenCVSysMgr() {
    
}
//===============================================
GOpenCVSysMgr* GOpenCVSysMgr::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCVSysMgr;
    }
    return m_instance;
}
//===============================================
void GOpenCVSysMgr::systemOpen() {
    m_title = "MainWindow | OpenCV";
    m_width = 640;
    m_height = 480;
    m_bgColor = cv::Scalar(50, 100, 150);
    m_delay = 30;
    m_continue = 1;
    
    m_window = cv::Mat(m_height, m_width, CV_8UC3, m_bgColor);
    cv::namedWindow(m_title, cv::WINDOW_AUTOSIZE);
    cv::imshow(m_title, m_window);
    
    
    while(1) {
        if(m_continue == 0) break;
        int lKey = cv::waitKey(m_delay);
        if(lKey == -1) break;
    }
    
    cv::destroyAllWindows();
}
//===============================================
void GOpenCVSysMgr::systemClose() {
    
}
//===============================================
void GOpenCVSysMgr::imageLoad(std::string imageFileIn) {
    cv::Mat lImg = cv::imread(imageFileIn);
    cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
    cv::imshow("original", lImg);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
//===============================================
void GOpenCVSysMgr::imageInvert(std::string imageFileIn) {
    cv::Mat lImg = cv::imread(imageFileIn);
    cv::Mat lInvert;
    cv::bitwise_not(lImg, lInvert);
    cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("invert", cv::WINDOW_AUTOSIZE);
    cv::imshow("original", lImg);
    cv::imshow("invert", lInvert);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
//===============================================
void GOpenCVSysMgr::videoLoad(std::string videoFileIn) {
    cv::VideoCapture lVideo;
    lVideo.open(videoFileIn);
    cv::Mat lImg;
    cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
    while(1) {
        lVideo >> lImg;
        if(lImg.empty()) break;
        cv::imshow("original", lImg);
        if((char)cv::waitKey(30) >= 0) break;
    }
    cv::destroyAllWindows();
}
//===============================================
void GOpenCVSysMgr::videoTrackbar(std::string videoFileIn) {
    cv::VideoCapture lVideo;
    lVideo.open(videoFileIn);
    cv::Mat lImg;
    cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
    while(1) {
        lVideo >> lImg;
        if(lImg.empty()) break;
        cv::imshow("original", lImg);
        if((char)cv::waitKey(30) >= 0) break;
    }
    cv::destroyAllWindows();
}
//===============================================
void GOpenCVSysMgr::basis() {
    m_title = "Graphique 2D | OpenCV";
    m_width = 640;
    m_height = 480;
    m_bgColor = cv::Scalar(255, 255, 255);
    m_gridColor = cv::Scalar(127, 127, 127);
    m_axisColor = cv::Scalar(0, 0, 0);
    m_gridDiv = 20;
    m_x0 = m_width/2;
    m_y0 = m_height/2;
    
    basisDraw();

    cv::namedWindow(m_title, cv::WINDOW_AUTOSIZE);
    cv::imshow(m_title, m_basis);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
//===============================================
void GOpenCVSysMgr::basisPoint() {
    m_title = "Graphique 2D | OpenCV";
    m_width = 640;
    m_height = 480;
    m_bgColor = cv::Scalar(255, 255, 255);
    m_gridColor = cv::Scalar(127, 127, 127);
    m_axisColor = cv::Scalar(0, 0, 0);
    m_pointColor = cv::Scalar(255, 0, 0, 0.2);
    m_gridDiv = 20;
    m_pointSize = 5;
    m_x0 = m_width/2;
    m_y0 = m_height/2;
    
    basisDraw();
    basisPointDraw(0, 0);
    basisPointDraw(5, 3);

    cv::namedWindow(m_title, cv::WINDOW_AUTOSIZE);
    cv::imshow(m_title, m_basis);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
//===============================================
void GOpenCVSysMgr::basisFunction() {
    m_title = "Graphique 2D | OpenCV";
    m_width = 640;
    m_height = 480;
    m_bgColor = cv::Scalar(255, 255, 255);
    m_gridColor = cv::Scalar(127, 127, 127);
    m_axisColor = cv::Scalar(0, 0, 0);
    m_pointColor = cv::Scalar(255, 0, 0);
    m_lineColor = cv::Scalar(0, 0, 255);
    m_gridDiv = 20;
    m_pointSize = 6;
    m_lineWidth = 2;
    m_x0 = m_width/2;
    m_y0 = m_height/2;
    m_xMin = -m_x0/m_gridDiv;
    m_xMax = +m_x0/m_gridDiv;
    m_yMin = -m_y0/m_gridDiv;
    m_yMax = +m_y0/m_gridDiv;
    m_xTick = 0.1;
    
    basisDraw();
    basisPointDraw(0, 0); 
    basisPointDraw(5, 3);
    double lCoef[] = {-4, 0, 1};
    sGPoly lParams = {lCoef, 3};
    basisFunctionDraw((void*)GFunction::onPoly, &lParams);
    
    cv::namedWindow(m_title, cv::WINDOW_AUTOSIZE);
    cv::imshow(m_title, m_basis);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
//===============================================
void GOpenCVSysMgr::basisDraw() {
    m_basis = cv::Mat(m_height, m_width, CV_8UC3, m_bgColor);

    cv::Point lPoint1;
    cv::Point lPoint2;
    
    for(int lX = 0; lX <= m_width; lX += m_gridDiv) {
        lPoint1 = cv::Point(lX, 0);
        lPoint2 = cv::Point(lX, m_height);
        cv::line(m_basis, lPoint1, lPoint2, m_gridColor, 1);
    }
    
    for(int lY = 0; lY <= m_height; lY += m_gridDiv) {
        lPoint1 = cv::Point(0, lY);
        lPoint2 = cv::Point(m_width, lY);
        cv::line(m_basis, lPoint1, lPoint2, m_gridColor, 1);
    }

    lPoint1 = cv::Point(m_x0, 0);
    lPoint2 = cv::Point(m_x0, m_height);
    cv::line(m_basis, lPoint1, lPoint2, m_axisColor, 2);
    
    lPoint1 = cv::Point(0, m_y0);
    lPoint2 = cv::Point(m_width, m_y0);
    cv::line(m_basis, lPoint1, lPoint2, m_axisColor, 2);
}
//===============================================
void GOpenCVSysMgr::basisPointDraw(double x, double y) {
    cv::Point lPoint(m_x0 + x*m_gridDiv, m_y0 - y*m_gridDiv);
    cv::circle(m_basis, lPoint, m_pointSize, m_pointColor, -1);
}
//===============================================
void GOpenCVSysMgr::basisLineDraw(double x1, double y1, double x2, double y2) {
    cv::Point lPoint1(m_x0 + x1*m_gridDiv, m_y0 - y1*m_gridDiv);
    cv::Point lPoint2(m_x0 + x2*m_gridDiv, m_y0 - y2*m_gridDiv);
    cv::line(m_basis, lPoint1, lPoint2, m_lineColor, m_lineWidth);
}
//===============================================
void GOpenCVSysMgr::basisFunctionDraw(void* func, void* params) {
    for(double lX = m_xMin; lX <= m_xMax; lX += m_xTick) {
        double lX2 = lX + m_xTick;
        GFUNC_CB onFunc = (GFUNC_CB)func;
        double lY = onFunc(lX, params);
        double lY2 = onFunc(lX2, params);
        if(lY < m_yMin - 1 || lY > m_yMax + 1) continue;
        basisLineDraw(lX, lY, lX2, lY2);
    }
}
//===============================================
