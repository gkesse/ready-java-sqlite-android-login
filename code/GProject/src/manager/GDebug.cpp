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
	while(1) {
		if(strcmp(key, "test") == 0) {
			test(); lRunFlag = 1; break;
		}
		else if(strcmp(key, "help") == 0) {
			help(); lRunFlag = 1; break;
		}
		break;
	}
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
