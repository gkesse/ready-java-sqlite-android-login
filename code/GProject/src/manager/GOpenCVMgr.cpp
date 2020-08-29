//===============================================
#include "GOpenCVMgr.h"
#include "GConfig.h"
#include "GManager.h"
//===============================================
GOpenCVMgr* GOpenCVMgr::m_instance = 0;
//===============================================
GOpenCVMgr::GOpenCVMgr() {

}
//===============================================
GOpenCVMgr::~GOpenCVMgr() {
    
}
//===============================================
GOpenCVMgr* GOpenCVMgr::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCVMgr;
    }
    return m_instance;
}
//===============================================
void GOpenCVMgr::imageLoad(std::string imageFileIn) {
    cv::Mat lImg = cv::imread(imageFileIn);
    cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
    cv::imshow("original", lImg);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
//===============================================
void GOpenCVMgr::imageInvert(std::string imageFileIn) {
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
void GOpenCVMgr::videoLoad(std::string videoFileIn) {
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
void GOpenCVMgr::videoTrackbar(std::string videoFileIn) {
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
void GOpenCVMgr::basis() {
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
void GOpenCVMgr::basisPoint() {
    m_title = "Graphique 2D | OpenCV";
    m_width = 640;
    m_height = 480;
    m_bgColor = cv::Scalar(255, 255, 255);
    m_gridColor = cv::Scalar(127, 127, 127);
    m_axisColor = cv::Scalar(0, 0, 0);
    m_pointColor = cv::Scalar(255, 0, 0, 0.2);
    m_gridDiv = 20;
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
void GOpenCVMgr::basisFunction() {
    m_title = "Graphique 2D | OpenCV";
    m_width = 640;
    m_height = 480;
    m_bgColor = cv::Scalar(255, 255, 255);
    m_gridColor = cv::Scalar(127, 127, 127);
    m_axisColor = cv::Scalar(0, 0, 0);
    m_pointColor = cv::Scalar(255, 0, 0, 0.2);
    m_gridDiv = 20;
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
void GOpenCVMgr::basisDraw() {
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
void GOpenCVMgr::basisPointDraw(int x, int y) {
    cv::Point lPoint(m_x0 + x*m_gridDiv, m_y0 - y*m_gridDiv);
    cv::circle(m_basis, lPoint, 6, m_pointColor, -1);
}
//===============================================
void GOpenCVMgr::basisFunctionDraw() {

}
//===============================================
