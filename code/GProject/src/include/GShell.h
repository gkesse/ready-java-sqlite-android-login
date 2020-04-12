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
    void run(const char* command, char* output, int size);

private:
    const char* __CLASSNAME__;
	static GShell* m_instance;
};
//================================================
#endif
//================================================
