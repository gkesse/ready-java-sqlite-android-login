//===============================================
#include "GManagerWin.h"
//===============================================
#if defined(__WIN32)
//===============================================
GManagerWin* GManagerWin::m_instance = 0;
//===============================================
GManagerWin::GManagerWin() {
    // opencv
    m_mgr->img->img_file = "C:\Users\Admin\Pictures\rec_drogba.jpg";
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
