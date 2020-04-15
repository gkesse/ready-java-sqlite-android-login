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
    void process(const char* key, ...);

private:
    void log(va_list args);
    void sep();
    void line(const char* data);
    void write(const char* data);
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
