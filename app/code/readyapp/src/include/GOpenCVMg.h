//===============================================
#ifndef _GOpenCVMg_
#define _GOpenCVMg_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCVMg { 
private:
    GOpenCVMg();
   
public:
    virtual ~GOpenCVMg();
    static GOpenCVMg* Instance();
    // image
    void loadImage(QString imgPath);
    void invertImage(QString imgPath);
    // video
    void loadVideo(QString videoPath);

private:
    static GOpenCVMg* m_instance;
};
//===============================================
#endif
//===============================================
