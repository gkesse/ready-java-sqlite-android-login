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
// transform
//===============================================
void GOpenCV::affineTransform(const cv::Mat& input, cv::Mat& result) {
    cv::Point2f triangleA[3];
    cv::Point2f triangleB[3];

    triangleA[0] = cv::Point2f(0 , 0);
    triangleA[1] = cv::Point2f(1 , 0);
    triangleA[2] = cv::Point2f(0 , 1);

    triangleB[0] = cv::Point2f(0, 0);
    triangleB[1] = cv::Point2f(1, 0);
    triangleB[2] = cv::Point2f(1, 1);

    cv::Mat affineMatrix = cv::getAffineTransform(triangleA, triangleB);
    cv::warpAffine(
    input, result,
    affineMatrix, input.size(), 
    cv::INTER_CUBIC,
    cv::BORDER_CONSTANT
    );
}
//===============================================
