//===============================================
#ifndef _GManagerUnix_
#define _GManagerUnix_
//===============================================
#include "GInclude.h"
#include "GManager.h"
//===============================================
#if defined(__unix)
//===============================================
class GManagerUnix : public GManager {
private:
    GManagerUnix();
    
public:
    ~GManagerUnix();
    static GManagerUnix* Instance();
    
private:
    static GManagerUnix* m_instance;
};
//===============================================
#endif
//===============================================
#endif
//===============================================
