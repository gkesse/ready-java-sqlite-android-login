//===============================================
#include "GEnv.h"
#include "GDir.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_GSL_ON_)
//===============================================
GEnv* GEnv::m_instance = 0;
//===============================================
GEnv::GEnv() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GEnv::~GEnv() {

}
//===============================================
GEnv* GEnv::Instance() {
    if(m_instance == 0) {
        m_instance = new GEnv;
    }
    return m_instance;
}
//===============================================
void GEnv::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
void GEnv::setEnv() {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
#if defined(__unix)
    const char* lXdgRuntimeDir = GDir::Instance()->xdgRuntimeDir().c_str();
    setenv("XDG_RUNTIME_DIR", lXdgRuntimeDir, 1);
    setenv("NO_AT_BRIDGE", "1", 1);
    setenv("LIBGL_ALWAYS_INDIRECT", "1", 1);
#endif
}
//================================================
#endif
//===============================================
