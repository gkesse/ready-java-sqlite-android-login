//================================================
#ifndef _GOpenGL_
#define _GOpenGL_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_OPENGL_ON_)
//================================================
class GOpenGL {
private:
	GOpenGL();

public:
	~GOpenGL();
	static GOpenGL* Instance();
	void test(int argc, char** argv);

private:
    const char* __CLASSNAME__;
	static GOpenGL* m_instance;
	GLFWwindow* m_window;
};
//================================================
#endif
//================================================
#endif
//================================================
