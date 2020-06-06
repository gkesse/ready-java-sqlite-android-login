//================================================
#ifndef _GOpenGL_
#define _GOpenGL_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_OPENGL_ON_)
//===============================================
typedef struct _sGParams sGParams;
typedef struct _sGVertex sGVertex;
typedef struct _sGColor sGColor;
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
    void init(std::string windowId, int width, int height, std::string title);
    void createThread(std::string windowId, std::string drawId);
    void joinThread();
    static void* onThread(void* params);
    static void draw(GLFWwindow* window, std::string drawId);
    static void drawPoint(GLFWwindow* window);
    static void drawPoint(sGVertex vertex, sGColor color, int size);
    static void drawTriangle(GLFWwindow* window);
    static void drawTriangle(sGVertex* vertex, sGColor color);
    
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
