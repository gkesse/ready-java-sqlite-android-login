//===============================================
#ifndef _GOpenCVTest_
#define _GOpenCVTest_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCVTest {
private:
    GOpenCVTest();
    
public:
    ~GOpenCVTest();
    static GOpenCVTest* Instance();
    void text();
    
public:
    static GOpenCVTest* m_instance;
};
//===============================================
#endif
//===============================================
