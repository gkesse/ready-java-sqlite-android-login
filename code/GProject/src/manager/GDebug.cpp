//===============================================
#include "GDebug.h"
#include "GWindowMath.h"
//===============================================
GDebug* GDebug::m_instance = 0;
//===============================================
GDebug::GDebug() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GDebug::~GDebug() {

}
//===============================================
GDebug* GDebug::Instance() {
	if(m_instance == 0) {
		m_instance = new GDebug;
	}
	return m_instance;
}
//===============================================
void GDebug::process(char* key, ...) {
	bool lRunFlag = 0;
	va_list lArgs;
	va_start(lArgs, key);
	while(1) {
		if(strcmp(key, "test") == 0) {
			test(); lRunFlag = 1; break;
		}
		else if(strcmp(key, "help") == 0) {
			help(); lRunFlag = 1; break;
		}
		else if(strcmp(key, "write") == 0) {
			write(lArgs); lRunFlag = 1; break;
		}
		break;
	}
	va_end(lArgs);
}
//===============================================
void GDebug::test() {
	cout << __CLASSNAME__ << "::" << __FUNCTION__ << "()\n";
}
//===============================================
void GDebug::help() {
	cout << __CLASSNAME__ << "::" << __FUNCTION__ << "()\n";
}
//===============================================
void GDebug::write(va_list args) {
	char lBuffer[256];
	int lIndex = 0;
	while(1) {
		char* lData = va_arg(args, char*);
		if(lData == 0) break;
		lIndex = sprintf(&lBuffer[lIndex], "%s", lData);
	}
	cout << lBuffer << "\n";
}
//===============================================
