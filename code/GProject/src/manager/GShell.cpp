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
void GShell::test() {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	char lCommand[256];
	char lOuput[256];

	sprintf(lCommand, "%s", "echo %HOMEDRIVE%%HOMEPATH%");
	run(lCommand, lOuput, 1023);
	cout << lOuput << "\n";
}
//===============================================
void GShell::run(const char* command, char* output, int size) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	FILE* lpFile = popen(command, "r");
	if(output != 0) {
		int lBytes = fread(output, 1, size, lpFile);
		if(lBytes >= 1) output[lBytes] = 0;
	}
	pclose(lpFile);
}
//===============================================
