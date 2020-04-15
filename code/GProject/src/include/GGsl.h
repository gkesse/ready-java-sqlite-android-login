//================================================
#ifndef _GGsl_
#define _GGsl_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_GSL_ON_)
//================================================
class GGsl {
private:
	GGsl();

public:
	~GGsl();
	static GGsl* Instance();
	void test(int argc, char** argv);

private:
    const char* __CLASSNAME__;
	static GGsl* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
