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
void GShell::run(const char* command, char* output, int size) {
	//GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	FILE* lpFile = popen(command, "r");
	if(output != 0) {
		int lBytes = fread(output, 1, size, lpFile);
		output[lBytes] = 0;
	}
	pclose(lpFile);
}
//===============================================
