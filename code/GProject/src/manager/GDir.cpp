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
	std::cout << "m_homePath: " << m_homePath << "\n";
	std::cout << "m_dataPath: " << m_dataPath << "\n";
	std::cout << "m_xdgRuntimeDir: " << m_xdgRuntimeDir << "\n";
	std::cout << "getPath(): " << GDir::Instance()->getPath("Makefile") << "\n";
}
//===============================================
std::string GDir::getPath(std::string path) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::string lDataPath = m_dataPath + "/" + path;
	return lDataPath;
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
#if defined(__WIN32)
void GDir::initHomePathWin() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	char lCommand[256];
	char lOutput[256];
	sprintf(lCommand, "%s", "echo %HOMEDRIVE%%HOMEPATH%");
	GShell::Instance()->run(lCommand, lOutput, 255, 1);
	m_homePath = std::string(lOutput);
    m_dataPath = m_homePath + GDIR_DATA_PATH;
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
	m_homePath = std::string(lOutput);
    m_dataPath = m_homePath + GDIR_DATA_PATH;
}
#endif
//===============================================
void GDir::initXdgRuntimeDir() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
#if defined(__unix)
	initXdgRuntimeDirUnix();
#elif defined(__WIN32)
	initXdgRuntimeDirWin();
#endif
}
//===============================================
#if defined(__unix)
void GDir::initXdgRuntimeDirUnix() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	char lCommand[256];
	char lOutput[256];
	sprintf(lCommand, "%s", "echo $TMP/runtime-$USER");
	GShell::Instance()->run(lCommand, lOutput, 255, 1);
	m_xdgRuntimeDir = std::string(lOutput);
}
#endif
//===============================================
#if defined(__WIN32)
void GDir::initXdgRuntimeDirWin() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
#endif
//===============================================
