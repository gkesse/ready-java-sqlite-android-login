//===============================================
#include "GQtMgr.h"
#include "GWindow.h"
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
void GQtMgr::systemOpen(int argc, char** argv) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    if(lQt->win == 0) {
        pthread_create(&lQt->threadId, 0, onSystemOpen, 0);
    }
    else {
        lQt->win->show();
    }
}
//===============================================
void* GQtMgr::onSystemOpen(void* params) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    QApplication lApp(lQt->argc, lQt->argv);
    lQt->win = new GWindow;
    lQt->win->show();
    lApp.exec();
    return 0;
}
//===============================================
void GQtMgr::systemClose() {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    lQt->win->hide();
}
//===============================================
