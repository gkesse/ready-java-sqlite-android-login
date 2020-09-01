//===============================================
#ifndef _GOpenCVTest_
#define _GOpenCVTest_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGMouseEvent sGMouseEvent;
//===============================================
class GOpenCVTest {
private:
    GOpenCVTest();
    
public:
    ~GOpenCVTest();
    static GOpenCVTest* Instance();
    void text();
    void mouse();
    
private:
    static void onMouse(int event, int x, int y, int flags, void* params);
    void pointAdd();
    void pointDraw();
    void pointsDraw();
    double pointDistance(cv::Point pt1, cv::Point pt2);
    void pointRemove();
    void eventLock();
    void eventUnlock();
    void imageCopy();
    void imageUpdate();
    
public:
    static GOpenCVTest* m_instance;
    cv::Mat m_org;
    cv::Mat m_img;
    cv::Mat m_copy;
    sGMouseEvent* m_mouseEvent;
    std::vector<cv::Point*> m_pointMap;
};
//===============================================
#endif
//===============================================
