//===============================================
#ifndef _GPdf_
#define _GPdf_
//===============================================
#include "GInclude.h"
//===============================================
class GPdf {
private:
    GPdf();
    
public:
    ~GPdf();
    static GPdf* Instance();
    void generate();
    
private:
    static GPdf* m_instance;
};
//===============================================
#endif
//===============================================