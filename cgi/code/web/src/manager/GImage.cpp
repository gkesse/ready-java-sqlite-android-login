//===============================================
#include "GImage.h"
#include "GManager.h"
//===============================================
GImage* GImage::m_instance = 0;
//===============================================
GImage::GImage() {
    m_tmpImgFile = GManager::Instance()->getFilePath("tmp", "tmp_img_file.jpg");
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
    run(lApp->image_run);
}
//===============================================
void GImage::run(QString action) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(action == "") {
        cv::Mat lImg = cv::imread(lApp->image_path.toStdString());
        if(lImg.empty()) {return;}
        printSave(lImg);
        return;
    }
    if(action == "download_image") {
        cv::Mat lImg = cv::imread(m_tmpImgFile.toStdString(), cv::IMREAD_COLOR);
        if(lImg.empty()) {return;}
        printImg(lImg);
        return;
    }
    if(action == "gray_image") {
        cv::Mat lImg = cv::imread(m_tmpImgFile.toStdString(), cv::IMREAD_COLOR);
        if(lImg.empty()) {return;}
        cv::cvtColor(lImg, lImg, cv::COLOR_BGR2GRAY);
        printSave(lImg);
        return;
    }
    if(action == "canny_image") {
        cv::Mat lImg = cv::imread(m_tmpImgFile.toStdString(), cv::IMREAD_GRAYSCALE);
        if(lImg.empty()) {return;}
        cv::Canny(lImg, lImg, 10, 350);
        printSave(lImg);
        return;
    }
}
//===============================================
void GImage::printImg(const cv::Mat& img) {
    std::vector<uchar> lBuffer;
    cv::imencode(".jpg", img, lBuffer);
    std::fwrite(lBuffer.data(), 1, lBuffer.size(), stdout);
}
//===============================================
void GImage::saveImg(const cv::Mat& img) {
    cv::imwrite(m_tmpImgFile.toStdString(), img);
}
//===============================================
void GImage::printSave(const cv::Mat& img) {
    printImg(img);
    saveImg(img);
}
//===============================================
