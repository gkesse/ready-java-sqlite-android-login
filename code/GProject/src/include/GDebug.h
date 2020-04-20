//================================================
#ifndef _GDebug_
#define _GDebug_
//================================================
#include "GInclude.h"
//================================================
class GDebug {
private:
    GDebug();

public:
    ~GDebug();
    static GDebug* Instance();
    void test(int argc, char** argv);
    void write(const char* key, ...);
    void process(const char* key, ...);
    void sep();
    void line(const char* data);
    void log(const char* data);
    void clear();
    void date(char* buffer);
    void homePathWin();
    void homePathUnix();

private:
    const char* __CLASSNAME__;
    static GDebug* m_instance;
    char m_homePath[256];
    char m_debugPath[256];
    char m_filename[256];
};
//================================================
#endif
//================================================
