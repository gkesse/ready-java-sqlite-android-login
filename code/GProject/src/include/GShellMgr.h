//===============================================
#ifndef _GShellMgr_
#define _GShellMgr_
//===============================================
#include "GInclude.h"
//===============================================
class GShellMgr {
private:
    GShellMgr();
    
public:
    ~GShellMgr();
    static GShellMgr* Instance();
    void run(const char* command, char* output, int size, int shift);
    void system(const char* command);
    
public:
    static GShellMgr* m_instance;
};
//===============================================
#endif
//===============================================
