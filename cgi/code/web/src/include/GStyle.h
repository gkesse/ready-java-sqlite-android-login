//===============================================
#ifndef _GStyle_
#define _GStyle_
//===============================================
#include "GInclude.h"
//===============================================
class GStyle {
private:
    GStyle();
    
public:
    virtual ~GStyle();
    static GStyle* Instance();
    void run(int argc, char** argv);
    
private:
    static GStyle* m_instance;
};
//===============================================
#endif
//===============================================
