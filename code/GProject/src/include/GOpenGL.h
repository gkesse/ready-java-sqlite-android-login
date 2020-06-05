//================================================
#ifndef _GOpenGL_
#define _GOpenGL_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_OPENGL_ON_)
//===============================================
typedef struct _sGParams sGParams;
typedef void* (*GOPENGL_THREAD)(void* params);
//================================================
class GOpenGL {
private:
    GOpenGL();

public:
    ~GOpenGL();
    static GOpenGL* Instance();
    void test(int argc, char** argv);
    void initGlfw(std::string windowId, int width, int height, std::string title);
    void createThreadGlfw(std::string windowId, GOPENGL_THREAD onThread);
    void joinThreadGlfw();
    static void* onThreadGlfw(void* params);
    static void* onThreadGlfw2(void* params);
    
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
