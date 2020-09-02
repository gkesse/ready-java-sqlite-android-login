//===============================================
#ifndef _GQtMgr_
#define _GQtMgr_
//===============================================
#include "GInclude.h"
//===============================================
class GQtMgr {
private:
    GQtMgr();
    
public:
    ~GQtMgr();
    static GQtMgr* Instance();
    void systemOpen();
    void systemClose();
    
private:
    static void* onSystemOpen(void* params);
    
public:
    static GQtMgr* m_instance;
};
//===============================================
#endif
//===============================================
