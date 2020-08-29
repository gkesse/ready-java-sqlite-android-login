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
