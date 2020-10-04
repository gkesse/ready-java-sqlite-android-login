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
    sGOpenCV* lOpenCV = GManager::Instance()->dataGet()->opencv;
        
    int lAns = pthread_create(&lOpenCV->thread_id, 0, onOpen, 0);
    printf("[info] lOpenCV->thread_id : %p\n", lOpenCV->thread_id);
    
    if(lAns) {
        printf("[error] GOpenCVUnix::open : pthread_create\n");
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
