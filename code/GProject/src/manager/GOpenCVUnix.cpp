//===============================================
#include "GOpenCVUnix.h"
#include "GManager.h"
//===============================================
#if defined (__unix)
//===============================================
GOpenCVUnix* GOpenCVUnix::m_instance = 0;
//===============================================
GOpenCVUnix::GOpenCVUnix() {

}
//===============================================
GOpenCVUnix::~GOpenCVUnix() {
    
}
//===============================================
GOpenCVUnix* GOpenCVUnix::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCVUnix;
    }
    return m_instance;
}
//===============================================
void GOpenCVUnix::open() {
	pthread_t lThreadId;
    int lAns = pthread_create(&lThreadId, 0, onOpen, 0);
    if(lAns) {
        printf("[GOpenCVUnix] error open() : %d\n", lAns);
        exit(0);
    }
}
//===============================================
void* GOpenCVUnix::onOpen(void* params) {
    GOpenCV::onOpen();
    return 0;
}
//===============================================
#endif
//===============================================
