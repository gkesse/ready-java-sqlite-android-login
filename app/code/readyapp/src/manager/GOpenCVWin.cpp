//===============================================
#include "GOpenCVWin.h"
#include "GManager.h"
//===============================================
#if defined (__WIN32)
//===============================================
GOpenCVWin* GOpenCVWin::m_instance = 0;
//===============================================
GOpenCVWin::GOpenCVWin() {

}
//===============================================
GOpenCVWin::~GOpenCVWin() {
    
}
//===============================================
GOpenCVWin* GOpenCVWin::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCVWin;
    }
    return m_instance;
}
//===============================================
void GOpenCVWin::open() {
    sGOpenCV* lOpenCV = GManager::Instance()->dataGet()->opencv;

	HANDLE lAns = CreateThread(0, 0, onOpen, 0, 0, &lOpenCV->thread_id);
    
    printf("[info] lOpenCV->thread_id : %p\n", lOpenCV->thread_id);
    printf("[info] lAns : %p\n", lAns);
    
    if(!lAns) {
        printf("[error] GOpenCVWin::open : CreateThread\n");
        exit(0);
    }
}
//===============================================
DWORD WINAPI GOpenCVWin::onOpen(LPVOID params) {
    GOpenCV::onOpen();
    return 0;
}
//===============================================
#endif
//===============================================
