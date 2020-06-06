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
    GOPENGL_DRAW draw;
    std::string drawId;
};
//================================================
struct _sGVertex {
    double x, y, z;
};
//================================================
struct _sGColor {
    double r, g, b, a;
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
    GOpenGL::Instance()->init(lWindow, 400, 400, "OpenGL | ReadyDev");
    GOpenGL::Instance()->createThread(lWindow, "drawPoint");
    GOpenGL::Instance()->joinThread();
}
//===============================================
void GOpenGL::init(std::string windowId, int width, int height, std::string title) {
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
void GOpenGL::createThread(std::string windowId, std::string drawId) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    sGParams* lParams = m_paramsMap[windowId];
    pthread_t* lThread = lParams->threadId;
    lParams->draw = draw;
    lParams->drawId = drawId;
    pthread_create(lThread, NULL, onThread, lParams);
}
//===============================================
void GOpenGL::joinThread() {
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
void* GOpenGL::onThread(void* params) {
	GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    sGParams* lParams = (sGParams*)params;
    GLFWwindow* lWindow = lParams->windowId;
    glfwMakeContextCurrent(lWindow);
    glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    while(!glfwWindowShouldClose(lWindow)) {
        lParams->draw(lWindow, lParams->drawId);
        glfwSwapBuffers(lWindow);
        glfwPollEvents();
    }
    glfwDestroyWindow(lWindow);
    return 0;
}
//===============================================
void GOpenGL::draw(GLFWwindow* window, std::string drawId) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    if(drawId == "drawPoint") {drawPoint(window); return;} 
    if(drawId == "drawTriangle") {drawTriangle(window); return;}
}
//===============================================
void GOpenGL::drawTriangle(GLFWwindow* window) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    int lWidth, lHeight;
    glfwGetFramebufferSize(window, &lWidth, &lHeight);
    float lRatio = (float)lWidth/(float)lHeight;
    glViewport(0, 0, lWidth, lHeight);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-lRatio, lRatio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    
    sGVertex lVertex[] = {
        {-0.6f, -0.4f, 0.f},
        {0.6f, -0.4f, 0.f},
        {0.f, 0.6f, 0.f}
    };
    sGColor lColor = {
        1.f, 0.f, 0.f, 1.f
    };
    drawTriangle(lVertex, lColor);
}
//===============================================
void GOpenGL::drawTriangle(sGVertex* vertex, sGColor color) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < 3; i++) {
        sGVertex lVertex = vertex[i];
        glColor4f(color.r, color.g, color.b, color.a);
        glVertex3f(lVertex.x, lVertex.y, lVertex.z);
    }
    glEnd();
}
//===============================================
void GOpenGL::drawPoint(GLFWwindow* window) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    int lWidth, lHeight;
    glfwGetFramebufferSize(window, &lWidth, &lHeight);
    float lRatio = (float) lWidth / (float)lHeight;
    glViewport(0, 0, lWidth, lHeight);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-lRatio, lRatio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    sGVertex lVertex = {
        0.0, 0.0, 0.0
    };
    sGColor lColor = {
        1.0, 0.0, 0.0, 1.0
    };
    drawPoint(lVertex, lColor, 10);
}
//===============================================
void GOpenGL::drawPoint(sGVertex vertex, sGColor color, int size) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
	glPointSize(size);
	glBegin(GL_POINTS);
	glColor4f(color.r, color.g, color.b, color.a); 
	glVertex3f(vertex.x, vertex.y, vertex.z);
	glEnd(); 
}
//===============================================
#endif
//===============================================
