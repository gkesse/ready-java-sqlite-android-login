//================================================
#ifndef _GDir_
#define _GDir_
//================================================
#include "GInclude.h"
//================================================
#define GDIR_DATA_PATH "/Programs/ReadyC/unix"
//================================================
class GDir {
private:
    GDir();

public:
    ~GDir();
    static GDir* Instance();
    void test(int argc, char** argv);
    std::string getPath(std::string path);

private:
    void initHomePath();
    void initXdgRuntimeDir();
#if defined(__unix)
    void initHomePathUnix();
    void initXdgRuntimeDirUnix();
#elif defined(__WIN32)
    void initHomePathWin();
    void initXdgRuntimeDirWin();
#endif

private:
    const char* __CLASSNAME__;
    static GDir* m_instance;
    std::string m_homePath;
    std::string m_dataPath;
    std::string m_xdgRuntimeDir;
};
//================================================
#endif
//================================================
