//===============================================
#include "GOpenCVPc.h"
#include "GManager.h"
//===============================================
GOpenCVPc* GOpenCVPc::m_instance = 0;
//===============================================
GOpenCVPc::GOpenCVPc() {
    
}
//===============================================
GOpenCVPc::~GOpenCVPc() {
    
}
//===============================================
GOpenCVPc* GOpenCVPc::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCVPc;
    }
    return m_instance;
}
//===============================================
void GOpenCVPc::run(int argc, char** argv) {
    std::string lKey = "test";
    if(argc > 2) {lKey = argv[2];}
    if(lKey == "test") {runTest(argc, argv); return;}
    if(lKey == "image_load") {runImageLoad(argc, argv); return;}
    if(lKey == "video_load") {runVideoLoad(argc, argv); return;}
    runTest(argc, argv);
}
//===============================================
void GOpenCVPc::runTest(int argc, char** argv) {
    printf("GSQLite::Instance()->test(argc, argv);\n");
}
//===============================================
// image
//===============================================
void GOpenCVPc::runImageLoad(int argc, char** argv) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    std::string lFilename = lApp->img_paths["gazebo_uav.png"];
    cv::Mat lImg = cv::imread(lFilename, -1);
    cv::namedWindow(lApp->app_name, cv::WINDOW_AUTOSIZE);
    cv::imshow(lApp->app_name, lImg );
    cv::waitKey(0);
    cv::destroyAllWindows();
}
//===============================================
// video
//===============================================
void GOpenCVPc::runVideoLoad(int argc, char** argv) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    std::string lFilename = lApp->video_paths["cgi_animation.mp4"];
    
    cv::namedWindow(lApp->app_name, cv::WINDOW_AUTOSIZE);
    cv::VideoCapture lCap;
    lCap.open(lFilename);
    cv::Mat lImg;

    while(1) {
        lCap >> lImg;
        if(lImg.empty()) {break;}
        cv::imshow(lApp->app_name, lImg);
        char lKey = cv::waitKey(33);
        if(lKey != -1 ) {break;}
    }
}
//===============================================
