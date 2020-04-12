//================================================
#ifndef _GShell_
#define _GShell_
//================================================
#include "GInclude.h"
//================================================
class GShell {
private:
	GShell();

public:
	~GShell();
	static GShell* Instance();
    void process(const char* key, ...);

private:

private:
    const char* __CLASSNAME__;
	static GShell* m_instance;
};
//================================================
#endif
//================================================
