//===============================================
#include "GGsl.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_GSL_ON_)
//===============================================
GGsl* GGsl::m_instance = 0;
//===============================================
GGsl::GGsl() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GGsl::~GGsl() {

}
//===============================================
GGsl* GGsl::Instance() {
    if(m_instance == 0) {
        m_instance = new GGsl;
    }
    return m_instance;
}
//===============================================
void GGsl::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    double x = 5.0;
    double y = gsl_sf_bessel_J0 (x);
    printf ("J0(%g) = %.18e\n", x, y);
}
//================================================
#endif
//===============================================
