//===============================================
#include "GImage.h"
#include "GManager.h"
//===============================================
GImage* GImage::m_instance = 0;
//===============================================
GImage::GImage() {

}
//===============================================
GImage::~GImage() {
    
}
//===============================================
GImage* GImage::Instance() {
    if(m_instance == 0) {
        m_instance = new GImage;
    }
    return m_instance;
}
//===============================================
void GImage::run(int argc, char** argv) {
    printf("content-type: image/jpeg\n\n");
    QString lFilename = "./data/img/logo.png";
    cv::Mat lImg = cv::imread(lFilename.toStdString());
    cv::Mat lGray;
    cv::cvtColor(lImg, lGray, cv::COLOR_BGR2GRAY);
    std::vector<uchar> lBuffer;
    cv::imencode(".jpg", lGray, lBuffer);
    std::fwrite(lBuffer.data(), 1, lBuffer.size(), stdout);
}
//===============================================
