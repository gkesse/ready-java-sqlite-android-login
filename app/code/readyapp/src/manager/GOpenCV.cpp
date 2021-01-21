//===============================================
#include "GOpenCV.h"
#include "GManager.h"
//===============================================
GOpenCV* GOpenCV::m_instance = 0;
//===============================================
GOpenCV::GOpenCV() {

}
//===============================================
GOpenCV::~GOpenCV() {
    
}
//===============================================
GOpenCV* GOpenCV::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCV;
    }
    return m_instance;
}
//===============================================
// image
//===============================================
void GOpenCV::loadImage(QString imgPath) {
    std::string lFilename = GManager::Instance()->getFilename(imgPath).toStdString();
    cv::Mat lImg = cv::imread(imgPath.toStdString());
    cv::namedWindow(lFilename, cv::WINDOW_AUTOSIZE);
    cv::imshow(lFilename, lImg);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
//===============================================
void GOpenCV::invertImage(QString imgPath) {
    std::string lFilename = GManager::Instance()->getFilename(imgPath).toStdString();
    cv::Mat lImg = cv::imread(imgPath.toStdString());
    cv::Mat lInvert;
    cv::bitwise_not(lImg, lInvert);
    cv::namedWindow(lFilename, cv::WINDOW_AUTOSIZE);
    cv::imshow(lFilename, lInvert);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
//===============================================
