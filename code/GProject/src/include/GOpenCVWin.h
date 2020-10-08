//===============================================
#ifndef _GOpenCVWin_
#define _GOpenCVWin_
//===============================================
#include "GInclude.h"
#include "GOpenCV.h"
//===============================================
#if defined (__WIN32)
//===============================================
class GOpenCVWin : public GOpenCV {
private:
    GOpenCVWin();
    
public:
    ~GOpenCVWin();
    static GOpenCVWin* Instance();
    void open();
    
private:
    static DWORD WINAPI onOpen(LPVOID params);

public:
    static GOpenCVWin* m_instance;
};
//===============================================
#endif
//===============================================
#endif
//===============================================
