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
    void test();
    void homePath(char* buffer);

private:
    void homePathWin(char* buffer);
    void homePathUnix(char* buffer);

private:
    const char* __CLASSNAME__;
	static GDir* m_instance;
};
//================================================
#endif
//================================================
