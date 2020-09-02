//===============================================
#include "GOpenCVSysMgr.h"
#include "GConfig.h"
#include "GFunction.h"
#include "GManager.h"
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
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGWindow* lWin = lMgr->win;
    pthread_create(&lWin->threadId, 0, onSystemOpen, 0);
}
//===============================================
void* GOpenCVSysMgr::onSystemOpen(void* params) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGWindow* lWin = lMgr->win;
    
    lWin->title = "MainWindow | OpenCV";
    lWin->width = 640;
    lWin->height = 480;
    lWin->bgColor = cv::Scalar(50, 100, 150);
    lWin->delay = 30;
    lWin->runMe = 1;
    
    lWin->img.release();
    lWin->img = cv::Mat(lWin->height, lWin->width, CV_8UC3, lWin->bgColor);
    cv::namedWindow(lWin->title, cv::WINDOW_AUTOSIZE);
    
    while(1) {
        if(lWin->runMe == 0) break;
        cv::imshow(lWin->title, lWin->img);
        cv::waitKey(lWin->delay);
    }
    
    cv::destroyAllWindows();
    return 0;
}
//===============================================
void GOpenCVSysMgr::systemClose() {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGWindow* lWin = lMgr->win;
    lWin->runMe = 0;
}
//===============================================
void GOpenCVSysMgr::imageLoad(std::string imgFile) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGWindow* lWin = lMgr->win;
    cv::Mat lImg = cv::imread(imgFile);
    cv::Mat lOut;
    
    double lWinW = lWin->img.cols;
    double lWinH = lWin->img.rows;
    double lOutW;
    double lOutH;
    
    imageRatioKeep(lImg, lOut, lWinW, lWinH, lOutW, lOutH);

    double lWinRX = (lWinW - lOutW)/2;
    double lWinRY = (lWinH - lOutH)/2;
    cv::Rect lWinR(lWinRX, lWinRY, lOutW - 1, lOutH - 1);
    cv::Rect lOutR(0, 0, lOutW - 1, lOutH - 1);
    
    cv::Mat lWinRO(lWin->img, lWinR);
    cv::Mat lOutRO(lOut, lOutR);
    cv::addWeighted(lOutRO, 1.0, lWinRO, 0.0, 0.0, lWinRO);
}
//===============================================
void GOpenCVSysMgr::imageRatioKeep(cv::Mat img, cv::Mat& out, double refW, double refH, double& outW, double &outH) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGWindow* lWin = lMgr->win;
    
    double lImgW = img.cols;
    double lImgH = img.rows;
    
    outW = (lImgW*refH)/lImgH;
    outH = (lImgH*refW)/lImgW;

    if(outH < refH) {outW = refW;}
    else if(outH > refH) {outH = refH;}
    
    cv::resize(img, out, cv::Size(outW, outH));
    printf("[info] %-10s : %.0f\n", "outW", outW);
    printf("[info] %-10s : %.0f\n", "outH", outH);
}
//===============================================
