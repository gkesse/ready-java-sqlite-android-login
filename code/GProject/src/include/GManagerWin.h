//===============================================
#ifndef _GManagerWin_
#define _GManagerWin_
//===============================================
#include "GInclude.h"
#include "GManager.h"
//===============================================
#if defined(__WIN32)
//===============================================
class GManagerWin : public GManager {
private:
    GManagerWin(); 
    
public:
    ~GManagerWin();
    static GManagerWin* Instance();
    
private:
    static GManagerWin* m_instance;
};
//===============================================
#endif
//===============================================
#endif
//===============================================
