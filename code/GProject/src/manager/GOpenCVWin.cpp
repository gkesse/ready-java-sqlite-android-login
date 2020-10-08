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
	DWORD lThreadId;
	HANDLE lThreadH = CreateThread(0, 0, onOpen, 0, 0, &lThreadId);
}
//===============================================
DWORD WINAPI GOpenCVWin::onOpen(LPVOID params) {
    GOpenCV::onOpen();
    return 0;
}
//===============================================
#endif
//===============================================
