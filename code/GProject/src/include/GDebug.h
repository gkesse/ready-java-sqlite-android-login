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

private:
    const char* __CLASSNAME__;
	static GDebug* m_instance;
	const char* m_filename;
};
//================================================
#endif
//================================================
