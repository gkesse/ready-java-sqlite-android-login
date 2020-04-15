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
    char* homePath();

private:
    void homePath(char* buffer);
    void homePathWin(char* buffer);
    void homePathUnix(char* buffer);

private:
    const char* __CLASSNAME__;
	static GDir* m_instance;
	char m_homePath[256];
};
//================================================
#endif
//================================================
