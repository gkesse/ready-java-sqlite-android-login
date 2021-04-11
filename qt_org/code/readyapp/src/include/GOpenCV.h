//===============================================
#ifndef _GOpenCV_
#define _GOpenCV_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCV { 
private:
    GOpenCV();
   
public:
    virtual ~GOpenCV();
    static GOpenCV* Instance();
    // transform
    void affineTransform(const cv::Mat& mat, cv::Mat& out);

private:
    static GOpenCV* m_instance;
};
//===============================================
#endif
//===============================================
