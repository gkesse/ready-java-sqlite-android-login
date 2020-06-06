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
    static void setData(std::string key, std::string value);
    static std::string getData(std::string key);
    static double getDataDouble(std::string key);
    static sGColor getDataColor(std::string key);
    static void draw(GLFWwindow* window, std::string drawId);
    static void drawPoint(GLFWwindow* window);
    static void drawPoint(sGVertex vertex, sGColor color, double size);
    static void drawPoint(sGVertex vertex);
    static void drawPoints(sGVertex* vertex, int count);
    static void drawLine(GLFWwindow* window);
    static void drawLine(sGVertex* vertex, sGColor color, double width);
    static void drawLine(sGVertex* vertex);
    static void drawLines(sGVertex* vertex, int count);
    static void drawTriangle(GLFWwindow* window);
    static void drawTriangle(sGVertex* vertex, sGColor color);
    static void drawGrid(GLFWwindow* window);
    static void drawGrid();
    
private:
    const char* __CLASSNAME__;
    static GOpenGL* m_instance;
    std::map<std::string, sGParams*> m_paramsMap;
    static std::map<std::string, std::string> m_dataMap;
};
//================================================
#endif
//================================================
#endif
//================================================
