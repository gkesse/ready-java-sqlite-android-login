//===============================================
#include "GShell.h"
#include "GDebug.h"
//===============================================
GShell* GShell::m_instance = 0;
//===============================================
GShell::GShell() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GShell::~GShell() {

}
//===============================================
GShell* GShell::Instance() {
	if(m_instance == 0) {
		m_instance = new GShell;
	}
	return m_instance;
}
//===============================================
void GShell::process(const char* key, ...) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	bool lRunFlag = 0;
	va_list lArgs;
	va_start(lArgs, key);
	while(1) {
		if(strcmp(key, "load") == 0) {
			lRunFlag = 1; break;
		}
		break;
	}
	va_end(lArgs);
}
//===============================================
