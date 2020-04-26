//===============================================
#include "GDir.h"
#include "GShell.h"
#include "GDebug.h"
//===============================================
GDir* GDir::m_instance = 0;
//===============================================
GDir::GDir() {
	__CLASSNAME__ = __FUNCTION__;
	initHomePath();
	initXdgRuntimeDir();
	m_dataPath = homePath() + "/.readydev/readycpp";
}
//===============================================
GDir::~GDir() {

}
//===============================================
GDir* GDir::Instance() {
	if(m_instance == 0) {
		m_instance = new GDir;
	}
	return m_instance;
}
//===============================================
void GDir::test(int argc, char** argv) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	cout << m_homePath << "\n";
	cout << m_dataPath << "\n";
	cout << m_xdgRuntimeDir << "\n";
}
//===============================================
string GDir::homePath() {
	return string(m_homePath);
}
//===============================================
string GDir::dataPath() {
	return m_dataPath;
}
//===============================================
string GDir::xdgRuntimeDir() {
	return m_xdgRuntimeDir;
}
//===============================================
void GDir::initHomePath() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
#if defined(__WIN32)
	initHomePathWin();
#elif defined(__unix)
	initHomePathUnix();
#endif
}
//===============================================
void GDir::initXdgRuntimeDir() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
#if defined(__unix)
	char lCommand[256];
	char lOutput[256];
	sprintf(lCommand, "%s", "echo $TMP/runtime-$USER");
	GShell::Instance()->run(lCommand, lOutput, 255, 1);
	m_xdgRuntimeDir = string(lOutput);
#endif
}
//===============================================
#if defined(__WIN32)
void GDir::initHomePathWin() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	char lCommand[256];
	char lOutput[256];
	sprintf(lCommand, "%s", "echo %HOMEDRIVE%%HOMEPATH%");
	GShell::Instance()->run(lCommand, lOutput, 255, 1);
	m_homePath = string(lOutput);
}
#endif
//===============================================
#if defined(__unix)
void GDir::initHomePathUnix() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	char lCommand[256];
	char lOutput[256];
	sprintf(lCommand, "%s", "echo $HOME");
	GShell::Instance()->run(lCommand, lOutput, 255, 1);
	m_homePath = string(lOutput);
}
#endif
//===============================================
