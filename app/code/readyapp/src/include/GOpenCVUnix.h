//===============================================
#ifndef _GOpenCVUnix_
#define _GOpenCVUnix_
//===============================================
#include "GInclude.h"
#include "GOpenCV.h"
//===============================================
#if defined (__unix)
//===============================================
class GOpenCVUnix : public GOpenCV {
private:
    GOpenCVUnix();
    
public:
    ~GOpenCVUnix();
    static GOpenCVUnix* Instance();
    void open();
    
private:
    static void* onOpen(void* params);

public:
    static GOpenCVUnix* m_instance;
};
//===============================================
#endif
//===============================================
#endif
//===============================================
