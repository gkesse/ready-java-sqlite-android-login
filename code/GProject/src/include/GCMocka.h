//================================================
#ifndef _GCMocka_
#define _GCMocka_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_CMOCKA_ON_)
//================================================
class GCMocka {
private:
	GCMocka();

public:
	~GCMocka();
	static GCMocka* Instance();
	void test(int argc, char** argv);

private:
	static void onTest(void** state);
	static int onStart(void** state);
	static int onEnd(void** state);

private:
    const char* __CLASSNAME__;
	static GCMocka* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
