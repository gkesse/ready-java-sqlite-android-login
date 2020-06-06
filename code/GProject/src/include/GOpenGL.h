//================================================
#ifndef _GOpenGL_
#define _GOpenGL_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_OPENGL_ON_)
//===============================================
typedef struct _sGParams sGParams;
//===============================================
typedef void* (*GOPENGL_PARAMS)(void* params);
typedef void (*GOPENGL_DRAW)(GLFWwindow* window, std::string drawId);
//================================================
class GOpenGL {
private:
    GOpenGL();

public:
    ~GOpenGL();
    static GOpenGL* Instance();
    void test(int argc, char** argv);
    void initGlfw(std::string windowId, int width, int height, std::string title);
    void createThreadGlfw(std::string windowId, std::string drawId);
    void joinThreadGlfw();
    static void* onThreadGlfw(void* params);
    static void drawGlfw(GLFWwindow* window, std::string drawId);
    static void drawTriangleGlfw(GLFWwindow* window);
    
private:
    const char* __CLASSNAME__;
    static GOpenGL* m_instance;
    std::map<std::string, sGParams*> m_paramsMap;
};
//================================================
#endif
//================================================
#endif
//================================================
