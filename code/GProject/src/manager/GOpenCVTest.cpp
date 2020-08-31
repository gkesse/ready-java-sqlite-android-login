//===============================================
#include "GOpenCVTest.h"
//===============================================
GOpenCVTest* GOpenCVTest::m_instance = 0;
//===============================================
int eFontMap[] = {
    cv::FONT_HERSHEY_SIMPLEX,
    cv::FONT_HERSHEY_PLAIN,
    cv::FONT_HERSHEY_DUPLEX,
    cv::FONT_HERSHEY_COMPLEX,
    cv::FONT_HERSHEY_TRIPLEX,
    cv::FONT_HERSHEY_COMPLEX_SMALL,
    cv::FONT_HERSHEY_SCRIPT_SIMPLEX,
    cv::FONT_HERSHEY_SCRIPT_COMPLEX,
    cv::FONT_ITALIC
};
//===============================================
const char* nFontMap[] = {
    "cv::FONT_HERSHEY_SIMPLEX",
    "cv::FONT_HERSHEY_PLAIN",
    "cv::FONT_HERSHEY_DUPLEX",
    "cv::FONT_HERSHEY_COMPLEX",
    "cv::FONT_HERSHEY_TRIPLEX",
    "cv::FONT_HERSHEY_COMPLEX_SMALL",
    "cv::FONT_HERSHEY_SCRIPT_SIMPLEX",
    "cv::FONT_HERSHEY_SCRIPT_COMPLEX",
    "cv::FONT_ITALIC"
};
//===============================================
GOpenCVTest::GOpenCVTest() {
    
}
//===============================================
GOpenCVTest::~GOpenCVTest() {
   
}
//===============================================
GOpenCVTest* GOpenCVTest::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCVTest;
    }
    return m_instance;
}
//===============================================
void GOpenCVTest::text() {
    double lWidth = 640;
    double lHeight = 480;
    cv::Scalar lBgColor(0, 0, 0);
    cv::Scalar lTextColor(0, 255, 0);
    cv::Scalar lRectColor(0, 0, 255);
    std::string lTitle = "Text | OpenCV";
    int lFontSize = sizeof(eFontMap)/sizeof(int);
    
    cv::Mat lImg(lHeight, lWidth, CV_8UC3, lBgColor);
    for(int i = 0; i < lFontSize; i++) {
        cv::Size lSize = cv::getTextSize (nFontMap[i], eFontMap[i], 0.5, 1, 0);
        printf("%s : %d ; %d", nFontMap[i], lSize.width, lSize.height);
        cv::Point lPoint(10, (i+1)*50);
        cv::Rect lRect(lPoint.x-2, lPoint.y - lSize.height - 2, lSize.width + 4, lSize.height + 8);
        cv::rectangle(lImg, lRect, lRectColor, 1);
        cv::putText(lImg, nFontMap[i], lPoint, eFontMap[i], 0.5, lTextColor);
    }
    
    cv::namedWindow(lTitle, cv::WINDOW_AUTOSIZE);
    cv::imshow(lTitle, lImg);
    cv::waitKey(0);
    cv::destroyAllWindows();
    exit(0);
}
//===============================================
