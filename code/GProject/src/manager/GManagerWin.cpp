//===============================================
#include "GManagerWin.h"
//===============================================
#if defined(__WIN32)
//===============================================
GManagerWin* GManagerWin::m_instance = 0;
//===============================================
GManagerWin::GManagerWin() {
    // sqlite
    m_mgr->sqlite->db_path = "C:/Users/Admin/Downloads/Programs/ReadyBin/win/.CONFIG_O.dat";
}
//===============================================
GManagerWin::~GManagerWin() { 
    
}
//===============================================
GManagerWin* GManagerWin::Instance() {
    if(m_instance == 0) {
        m_instance = new GManagerWin;
    }
    return m_instance;
}
//===============================================
#endif
//===============================================
