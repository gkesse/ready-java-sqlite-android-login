//===============================================
#ifndef _GQt_
#define _GQt_
//===============================================
#include "GInclude.h"
//===============================================
class GQt {
private:
    GQt();
    
public:
    ~GQt();
    static GQt* Instance();
    void run(int argc, char** argv);

private:
    static GQt* m_instance;
};
//===============================================
#endif
//===============================================