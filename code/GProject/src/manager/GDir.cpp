//===============================================
#include "GDir.h"
#include "GShell.h"
#include "GDebug.h"
//===============================================
GDir* GDir::m_instance = 0;
//===============================================
GDir::GDir() {
    __CLASSNAME__ = __FUNCTION__;
    homePath(m_homePath);
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
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", 0);
    char lHome[256];
    homePath(lHome);
    cout << lHome << "\n";
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
    void GDir::homePath(char* buffer) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", 0);
#if defined(__WIN32)
    homePathWin(buffer);
#else
    homePathUnix(buffer);
#endif
}
//===============================================
void GDir::homePathWin(char* buffer) {
#if defined(__WIN32)
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", 0);
    char lCommand[256];
    sprintf(lCommand, "%s", "echo %HOMEDRIVE%%HOMEPATH%");
    GShell::Instance()->run(lCommand, buffer, 255, 1);
#endif
}
//===============================================
void GDir::homePathUnix(char* buffer) {
#if defined(__WIN32)
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", 0);
    char lCommand[256];
    sprintf(lCommand, "%s", "echo $HOME");
    GShell::Instance()->run(lCommand, buffer, 255, 1);
#endif
}
//===============================================
