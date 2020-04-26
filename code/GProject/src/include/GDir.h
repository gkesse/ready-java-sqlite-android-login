//================================================
#ifndef _GDir_
#define _GDir_
//================================================
#include "GInclude.h"
//================================================
class GDir {
private:
    GDir();

public:
    ~GDir();
    static GDir* Instance();
    void test(int argc, char** argv);
    string homePath();
    string dataPath();
    string xdgRuntimeDir();

private:
    void initHomePath();
    void initXdgRuntimeDir();
#if defined(__WIN32)
    void initHomePathWin();
#elif defined(__unix)
    void initHomePathUnix();
#endif

private:
    const char* __CLASSNAME__;
    static GDir* m_instance;
    string m_homePath;
    string m_dataPath;
    string m_xdgRuntimeDir;
};
//================================================
#endif
//================================================
