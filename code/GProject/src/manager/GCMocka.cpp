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
		cmocka_unit_test(onTest)
	};
	cmocka_run_group_tests(lTestMap, onStart, onEnd);
}
//===============================================
void GCMocka::onTest(void** state) {
	GDebug::Instance()->process("log", "GCMocka", "::", __FUNCTION__, "()", 0);
}
//===============================================
int GCMocka::onStart(void** state) {
	GDebug::Instance()->process("log", "GCMocka", "::", __FUNCTION__, "()", 0);
	return 0;
}
//===============================================
int GCMocka::onEnd(void** state) {
	GDebug::Instance()->process("log", "GCMocka", "::", __FUNCTION__, "()", 0);
	return 0;
}
//================================================
#endif
//===============================================
