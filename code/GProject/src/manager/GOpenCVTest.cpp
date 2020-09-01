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
    cv::FONT_ITALIC,
    -1
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
    "cv::FONT_ITALIC",
    0
};
//===============================================
int eMouseFlag[] = {
  cv::EVENT_FLAG_LBUTTON,
  cv::EVENT_FLAG_RBUTTON,
  cv::EVENT_FLAG_MBUTTON,
  cv::EVENT_FLAG_CTRLKEY,
  cv::EVENT_FLAG_SHIFTKEY,
  cv::EVENT_FLAG_ALTKEY,
  -1
};
//===============================================
const char* nMouseFlag[] = {
  "cv::EVENT_FLAG_LBUTTON",
  "cv::EVENT_FLAG_RBUTTON",
  "cv::EVENT_FLAG_MBUTTON",
  "cv::EVENT_FLAG_CTRLKEY",
  "cv::EVENT_FLAG_SHIFTKEY",
  "cv::EVENT_FLAG_ALTKEY",
  0
};
//===============================================
int eMouseEvent[] = {
  cv::EVENT_MOUSEMOVE,
  cv::EVENT_LBUTTONDOWN,
  cv::EVENT_RBUTTONDOWN,
  cv::EVENT_MBUTTONDOWN,
  cv::EVENT_LBUTTONUP,
  cv::EVENT_RBUTTONUP,
  cv::EVENT_MBUTTONUP,
  cv::EVENT_LBUTTONDBLCLK,
  cv::EVENT_RBUTTONDBLCLK,
  cv::EVENT_MBUTTONDBLCLK,
  cv::EVENT_MOUSEWHEEL,
  cv::EVENT_MOUSEHWHEEL,
  -1
};
//===============================================
const char* nMouseEvent[] = {
  "cv::EVENT_MOUSEMOVE",
  "cv::EVENT_LBUTTONDOWN",
  "cv::EVENT_RBUTTONDOWN",
  "cv::EVENT_MBUTTONDOWN",
  "cv::EVENT_LBUTTONUP",
  "cv::EVENT_RBUTTONUP",
  "cv::EVENT_MBUTTONUP",
  "cv::EVENT_LBUTTONDBLCLK",
  "cv::EVENT_RBUTTONDBLCLK",
  "cv::EVENT_MBUTTONDBLCLK",
  "cv::EVENT_MOUSEWHEEL",
  "cv::EVENT_MOUSEHWHEEL",
  0
};
//===============================================
struct _sGMouseEvent {
    bool onFlag;
    int event;
    int x;
    int y;
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
    
    cv::Mat lImg(lHeight, lWidth, CV_8UC3, lBgColor);
    for(int i = 0; eFontMap[i] != -1; i++) {
        cv::Size lSize = cv::getTextSize (nFontMap[i], eFontMap[i], 0.5, 1, 0);
        printf("%s : %d ; %d\n", nFontMap[i], lSize.width, lSize.height);
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
void GOpenCVTest::mouse() {
    double lWidth = 640;
    double lHeight = 480;
    cv::Scalar lBgColor(0, 20, 0);
    std::string lTitle = "Mouse | OpenCV";
    m_mouseEvent = new sGMouseEvent;
    m_mouseEvent->onFlag = 0;

    cv::namedWindow(lTitle, cv::WINDOW_AUTOSIZE);
    m_img = cv::Mat(lHeight, lWidth, CV_8UC3, lBgColor);
    cv::setMouseCallback(lTitle, onMouse, m_mouseEvent);
    m_copy = m_img.clone();
    m_org = m_img.clone();
    
    while(1) {
        eventLock();
        pointAdd();
        pointRemove();
        imageCopy();
        imageUpdate();
        eventUnlock();
        cv::imshow(lTitle, m_copy);
        int lKey = cv::waitKey(30);
        if(lKey != -1) break;
    }
    
    cv::destroyAllWindows();
    delete m_mouseEvent;
    exit(0);
}
//===============================================
void GOpenCVTest::pointAdd() {
    if(m_mouseEvent->event == cv::EVENT_LBUTTONDOWN) {
        cv::Point* lPoint = new cv::Point(m_mouseEvent->x, m_mouseEvent->y);
        m_pointMap.push_back(lPoint);
    }
}
//===============================================
void GOpenCVTest::pointDraw() {
    if(m_mouseEvent->event == cv::EVENT_LBUTTONDOWN) {
        cv::Point* lPoint = m_pointMap[m_pointMap.size()-1];
        cv::Scalar lPointColor(255, 0, 0);
        double lPointSize = 6;
        cv::circle(m_copy, *lPoint, lPointSize, lPointColor, -1);
        m_img = m_copy.clone();
    }
}
//===============================================
double GOpenCVTest::pointDistance(cv::Point pt1, cv::Point pt2) {
    double lX = pt2.x - pt1.x;
    double lY = pt2.y - pt1.y;
    return sqrt(lX*lX + lY*lY);
}
//===============================================
void GOpenCVTest::pointRemove() {
    if(m_mouseEvent->event == cv::EVENT_RBUTTONDOWN) {
        cv::Point lPoint1(m_mouseEvent->x, m_mouseEvent->y);
        for(int i = 0; i < m_pointMap.size(); i++) {
            cv::Point* lPoint2 = m_pointMap[i];
            double lPointSize1 = pointDistance(lPoint1, *lPoint2);
            double lPointSize2 = 6;
            if(lPointSize1 <= lPointSize2) {
                m_pointMap.erase(m_pointMap.begin() + i);
                m_copy = m_org.clone();
                delete lPoint2;
                break;
            }
        }
    }
}
//===============================================
void GOpenCVTest::pointsDraw() {
    if(m_mouseEvent->event == cv::EVENT_RBUTTONDOWN) {
        for(int i = 0; i < m_pointMap.size(); i++) {
            cv::Point* lPoint = m_pointMap[i];
            cv::Scalar lPointColor(255, 0, 0);
            double lPointSize = 6;
            cv::circle(m_copy, *lPoint, lPointSize, lPointColor, -1);
            m_img = m_copy.clone();

        }
    }
}
//===============================================
void GOpenCVTest::eventLock() {
    m_mouseEvent->onFlag = 0;
}
//===============================================
void GOpenCVTest::eventUnlock() {
    m_mouseEvent->onFlag = 1;
}
//===============================================
void GOpenCVTest::imageCopy() {
    if(m_mouseEvent->event == cv::EVENT_LBUTTONDOWN) {
        m_copy = m_img.clone();
    }
}
//===============================================
void GOpenCVTest::imageUpdate() {
    pointDraw();
    pointsDraw();
}
//===============================================
void GOpenCVTest::onMouse(int event, int x, int y, int flags, void* params) {
    sGMouseEvent* lMouseEvent = (sGMouseEvent*)params;
    if(lMouseEvent->onFlag == 0) return;
    lMouseEvent->event = event;
    lMouseEvent->x = x;
    lMouseEvent->y = y;
}
//===============================================
