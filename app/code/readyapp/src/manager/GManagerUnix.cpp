//===============================================
#include "GManagerUnix.h"
//===============================================
#if defined(__unix)
//===============================================
GManagerUnix* GManagerUnix::m_instance = 0;
//===============================================
GManagerUnix::GManagerUnix() {
    // sqlite
    m_mgr->sqlite->db_path = "/home/osboxes/Programs/ReadyBin/unix/.CONFIG_O.dat";
}
//===============================================
GManagerUnix::~GManagerUnix() {
    
}
//===============================================
GManagerUnix* GManagerUnix::Instance() {
    if(m_instance == 0) {
        m_instance = new GManagerUnix;
    }
    return m_instance;
}
//===============================================
#endif
//===============================================
