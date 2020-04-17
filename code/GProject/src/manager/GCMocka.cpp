//===============================================
#include "GCMocka.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_CMOCKA_ON_)
//===============================================
GCMocka* GCMocka::m_instance = 0;
//===============================================
GCMocka::GCMocka() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GCMocka::~GCMocka() {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
}
//===============================================
GCMocka* GCMocka::Instance() {
	if(m_instance == 0) {
		m_instance = new GCMocka;
	}
	return m_instance;
}
//===============================================
void GCMocka::test(int argc, char** argv) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	CMUnitTest lTestMap[] = {

	};
}
//================================================
#endif
//===============================================
