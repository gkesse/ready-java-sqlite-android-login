//===============================================
#include "GOpenGL.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_OPENGL_ON_)
//===============================================
GOpenGL* GOpenGL::m_instance = 0;
//===============================================
struct _sGParams {
    GLFWwindow* windowId;
    pthread_t* threadId;
};
//===============================================
GOpenGL::GOpenGL() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GOpenGL::~GOpenGL() {

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
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::string lWindow = "lWindow";
    std::string lWindow2 = "lWindow2";
    GOpenGL::Instance()->initGlfw(lWindow, 400, 400, "OpenGL | ReadyDev");
    GOpenGL::Instance()->initGlfw(lWindow2, 400, 400, "OpenGL | ReadyDev");
    GOpenGL::Instance()->createThreadGlfw(lWindow, onThreadGlfw);
    GOpenGL::Instance()->createThreadGlfw(lWindow2, onThreadGlfw2);
    GOpenGL::Instance()->joinThreadGlfw();
}
//===============================================
void GOpenGL::initGlfw(std::string windowId, int width, int height, std::string title) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    if(!glfwInit()) {std::cout << "[GOpenGL] erreur initialisation\n"; exit(0);}
    GLFWwindow* lWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if(!lWindow) {glfwTerminate(); std::cout << "[GOpenGL] erreur creation fenetre\n"; exit(0);}
    sGParams* lParams = new sGParams;
    lParams->windowId = lWindow;
    lParams->threadId = new pthread_t;
    m_paramsMap[windowId] = lParams;
}
//===============================================
void GOpenGL::createThreadGlfw(std::string windowId, GOPENGL_THREAD onThread) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    sGParams* lParams = m_paramsMap[windowId];
    pthread_t* lThread = lParams->threadId;
    pthread_create(lThread, NULL, onThread, lParams);
}
//===============================================
void GOpenGL::joinThreadGlfw() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    for(std::map<std::string, sGParams*>::iterator lItem = m_paramsMap.begin(); lItem != m_paramsMap.end(); lItem++) {
        std::string lWindowId = lItem->first;
        sGParams* lParams = lItem->second;
        pthread_t* lThread = lParams->threadId;
        pthread_join(*lThread, NULL);
    }
    glfwTerminate();
    for(std::map<std::string, sGParams*>::iterator lItem = m_paramsMap.begin(); lItem != m_paramsMap.end(); lItem++) {
        std::string lWindowId = lItem->first;
        sGParams* lParams = lItem->second;
        pthread_t* lThread = lParams->threadId;
        delete lThread;
        delete lParams;
    }
}
//===============================================
void* GOpenGL::onThreadGlfw(void* params) {
	GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    sGParams* lParams = (sGParams*)params;
    GLFWwindow* lWindow = lParams->windowId;
    glfwMakeContextCurrent(lWindow);
    while(!glfwWindowShouldClose(lWindow)) {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(lWindow, &width, &height);
        ratio = (float) width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();

        glfwSwapBuffers(lWindow);
        glfwPollEvents();
    }
    glfwDestroyWindow(lWindow);
    return 0;
}
//===============================================
void* GOpenGL::onThreadGlfw2(void* params) {
	GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    sGParams* lParams = (sGParams*)params;
    GLFWwindow* lWindow = lParams->windowId;
    glfwMakeContextCurrent(lWindow);
    while(!glfwWindowShouldClose(lWindow)) {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(lWindow, &width, &height);
        ratio = (float) width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();

        glfwSwapBuffers(lWindow);
        glfwPollEvents();
    }
    glfwDestroyWindow(lWindow);
    return 0;
}
//===============================================
#endif
//===============================================
