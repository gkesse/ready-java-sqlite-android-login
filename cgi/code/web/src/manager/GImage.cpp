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
    sGApp* lApp = GManager::Instance()->getData()->app;
    printf("content-type: image/jpeg\n\n");
    QString lFilename = lApp->image_path;
    cv::Mat lImg = cv::imread(lFilename.toStdString());
    if(lImg.empty()) {return;}
    std::vector<uchar> lBuffer;
    cv::imencode(".jpg", lImg, lBuffer);
    std::fwrite(lBuffer.data(), 1, lBuffer.size(), stdout);
}
//===============================================
