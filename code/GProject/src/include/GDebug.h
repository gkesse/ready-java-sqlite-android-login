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
    void process(char* key, ...);

private:
    void test();
    void help();
    void write(va_list args);

private:
    const char* __CLASSNAME__;
	static GDebug* m_instance;
};
//================================================
#endif
//================================================
