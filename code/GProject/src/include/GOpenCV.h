//================================================
#ifndef _GOpenCV_
#define _GOpenCV_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_OPENCV_ON_)
//================================================
class GOpenCV {
private:
	GOpenCV();

public:
	~GOpenCV();
	static GOpenCV* Instance();
	void test(int argc, char** argv);

private:
    const char* __CLASSNAME__;
	static GOpenCV* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
