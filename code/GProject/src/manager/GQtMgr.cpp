//===============================================
#include "GQtMgr.h"
#include "GManager.h"
//===============================================
GQtMgr* GQtMgr::m_instance = 0;
//===============================================
GQtMgr::GQtMgr() {

}
//===============================================
GQtMgr::~GQtMgr() {
    
}
//===============================================
GQtMgr* GQtMgr::Instance() {
    if(m_instance == 0) {
        m_instance = new GQtMgr;
    }
    return m_instance;
}
//===============================================
void GQtMgr::systemOpen() {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGWindow* lWin = lMgr->win;
    pthread_create(&lWin->threadId, 0, onSystemOpen, 0);
}
//===============================================
void* GQtMgr::onSystemOpen(void* params) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    
    return 0;
}
//===============================================
void GQtMgr::systemClose() {
    sGManager* lMgr = GManager::Instance()->dataGet();

}
//===============================================
