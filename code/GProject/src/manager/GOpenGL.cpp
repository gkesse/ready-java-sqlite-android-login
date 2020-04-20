//===============================================
#include "GOpenGL.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_OPENGL_ON_)
//===============================================
GOpenGL* GOpenGL::m_instance = 0;
//===============================================
GOpenGL::GOpenGL() {
	__CLASSNAME__ = __FUNCTION__;
	m_window = 0;
}
//===============================================
GOpenGL::~GOpenGL() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", 0);
}
//===============================================
GOpenGL* GOpenGL::Instance() {
	if(m_instance == 0) {
		m_instance = new GOpenGL;
	}
	return m_instance;
}
//===============================================
void GOpenGL::test(int argc, char** argv) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", 0);
	glfwInit();
	m_window = glfwCreateWindow(640, 480, "OpenGL | ReadyDev", NULL, NULL);
	glfwMakeContextCurrent(m_window);
	while(1) {
		bool lClose = glfwWindowShouldClose(m_window);
		if(lClose == true) break;
		int lWidth;
		int lHeight;
		glfwGetFramebufferSize(m_window, &lWidth, &lHeight);
		glViewport(0, 0, lWidth, lHeight);
		glClear(GL_COLOR_BUFFER_BIT);
		double lRatio = (double)lWidth/lHeight;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-lRatio, lRatio, -1.0, 1.0, 1.0, -1.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		sGVertex lVertex[] = {
            {-0.6, -0.4, 0.0},
            {0.6, -0.4, 0.0},
            {0.0, 0.6, 0.0}
		};
		sGColor lColor[] = {
            {1.0, 0.0, 0.0, 1.0},
            {0.0, 1.0, 0.0, 1.0},
            {0.0, 0.0, 1.0, 1.0}
        };

		glBegin(GL_TRIANGLES);
		for(int i = 0; i < 3; i++) {
			glColor4d(lColor[i].r, lColor[i].g, lColor[i].b, lColor[i].a);
			glVertex3d(lVertex[i].x, lVertex[i].y, lVertex[i].z);
		}
		glEnd();

	    glfwSwapBuffers(m_window);
	    glfwPollEvents();
	}
    glfwDestroyWindow(m_window);
	glfwTerminate();
}
//================================================
#endif
//===============================================
