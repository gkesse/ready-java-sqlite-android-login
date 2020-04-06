//===============================================
#include "GProcess.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GProcess::~GProcess() {

}
//===============================================
GProcess* GProcess::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcess;
	}
	return m_instance;
}
//===============================================
void GProcess::process(int argc, char** argv) {
	bool lRunFlag = 0;
	for(int i = 1; i < argc;) {
		string lKey = argv[i++];
		if(lKey == "test") {
			test(); lRunFlag = 1; break;
		}
		else if(lKey == "math") {
			math(); lRunFlag = 1; break;
		}
	}
	if(lRunFlag == 0) cout << "le process est inconnu\n";
}
//===============================================
void GProcess::test() {
	cout << __CLASSNAME__ << "::" << __FUNCTION__ << "()\n";
}
//===============================================
void GProcess::math() {
	cout << __CLASSNAME__ << "::" << __FUNCTION__ << "()\n";
}
//===============================================
