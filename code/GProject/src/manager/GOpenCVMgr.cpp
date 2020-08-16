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
    cv::namedWindow("original", cv::WINDOW_AUTOSIZE );
    cv::imshow("original", lImg);
    cv::waitKey(0);
    cv::destroyAllWindows();
}
//===============================================
