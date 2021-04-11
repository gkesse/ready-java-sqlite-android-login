//===============================================
#ifndef _GTest_
#define _GTest_
//===============================================
#include "GInclude.h"
//===============================================
class GTest {
private:
    GTest();
    
public:
    ~GTest();
    static GTest* Instance();
    void run(int argc, char** argv);
    
public:
    static GTest* m_instance;
};
//===============================================
#endif
//===============================================
