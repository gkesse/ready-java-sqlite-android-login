//===============================================
#ifndef _GImage_
#define _GImage_
//===============================================
#include "GInclude.h"
//===============================================
class GImage {
private:
    GImage();
    
public:
    virtual ~GImage();
    static GImage* Instance();
    void run(int argc, char** argv);
    
private:
    static GImage* m_instance;
};
//===============================================
#endif
//===============================================
