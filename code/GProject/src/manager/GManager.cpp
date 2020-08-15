//===============================================
#include "GManager.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
GManager::GManager() {
    
}
//===============================================
GManager::~GManager() {
    
}
//===============================================
GManager* GManager::Instance() {
    if(m_instance == 0) {
        m_instance = new GManager;
    }
    return m_instance;
}
//===============================================
std::string GManager::getSeparator() {
    std::string lSep = "/";
#if defined(__WIN32)
    lSep = "\\";
#endif
    return lSep;
}
//===============================================
