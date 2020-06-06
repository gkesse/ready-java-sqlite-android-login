//===============================================
#include "GOpenGL.h"
#include "GString.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_OPENGL_ON_)
//===============================================
GOpenGL* GOpenGL::m_instance = 0;
std::map<std::string, std::string> GOpenGL::m_dataMap; 
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
    glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // point
    setData("point_color", "0;0;1;1");
    setData("point_size", "10");
    // line
    setData("line_color", "0;1;0;1");
    setData("line_width", "2");
    // grid
    setData("grid_xmin", "-5");
    setData("grid_xmax", "5");
    setData("grid_ymin", "-1");
    setData("grid_ymax", "1");
    setData("grid_zmin", "-5");
    setData("grid_zmax", "5");
    setData("grid_div", "0.1");
    setData("grid_div_width", "1");
    setData("grid_div_color", "0.5;0.5;0.5;1");
    setData("grid_xdiv_val", "1");
    setData("grid_ydiv_val", "1");
    setData("grid_zdiv_val", "1");
    setData("grid_axis_width", "2");
    setData("grid_axis_color", "1;0.5;0.5;1");
    setData("grid_org_color", "0.52;0.52;0.52;1");
    setData("grid_x0", "0");
    setData("grid_y0", "0");


    while(!glfwWindowShouldClose(lWindow)) {
        lParams->draw(lWindow, lParams->drawId);
        glfwSwapBuffers(lWindow);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(lWindow);
    return 0;
}
//===============================================
void GOpenGL::setData(std::string key, std::string value) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    m_dataMap[key] = value;
}
//===============================================
std::string GOpenGL::getData(std::string key) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    return m_dataMap[key];
}
//===============================================
double GOpenGL::getDataDouble(std::string key) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    return atof(m_dataMap[key].c_str());
}
//===============================================
sGColor GOpenGL::getDataColor(std::string key) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    std::string lData = m_dataMap[key];
    std::vector<std::string> lDataMap = GString::Instance()->split(lData, ';');
    sGColor lColor = {atof(lDataMap[0].c_str()), atof(lDataMap[1].c_str()), atof(lDataMap[2].c_str()), atof(lDataMap[3].c_str())};
    return lColor;
}
//===============================================
void GOpenGL::draw(GLFWwindow* window, std::string drawId) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    if(drawId == "drawPoint") {drawPoint(window); return;} 
    if(drawId == "drawLine") {drawLine(window); return;} 
    if(drawId == "drawTriangle") {drawTriangle(window); return;}
    if(drawId == "drawGrid") {drawGrid(window); return;}
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
    glOrtho(-lRatio, lRatio, -1, 1, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    drawGrid();
    sGVertex lVertex = {0, 0, 0};
    drawPoint(lVertex);
}
//===============================================
void GOpenGL::drawPoint(sGVertex vertex, sGColor color, double size) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);   
	glPointSize(size);
	glBegin(GL_POINTS);
	glColor4f(color.r, color.g, color.b, color.a); 
	glVertex3f(vertex.x, vertex.y, vertex.z);
	glEnd(); 
}
//===============================================
void GOpenGL::drawPoint(sGVertex vertex) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
	sGColor lPointColor = getDataColor("point_color");
	double lPointSize = getDataDouble("point_size");
	double lGridDiv = getDataDouble("grid_div");
	double lGridXdivVal = getDataDouble("grid_xdiv_val");
	double lGridYdivVal = getDataDouble("grid_ydiv_val");
	double lGridZdivVal = getDataDouble("grid_zdiv_val");
    
	glPointSize(lPointSize);
	glBegin(GL_POINTS);
	glColor4f(lPointColor.r, lPointColor.g, lPointColor.b, lPointColor.a); 
	glVertex3f(vertex.x*lGridDiv/lGridXdivVal, vertex.y*lGridDiv/lGridYdivVal, vertex.z*lGridDiv/lGridZdivVal);
	glEnd(); 
}
//===============================================
void GOpenGL::drawLine(GLFWwindow* window) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    int lWidth, lHeight;
    glfwGetFramebufferSize(window, &lWidth, &lHeight);
    float lRatio = (float) lWidth / (float)lHeight;
    glViewport(0, 0, lWidth, lHeight);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-lRatio, lRatio, -1, 1, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    sGVertex lVertex[] = {{0, 0, 0}, {1, 1, 0}};
    drawLine(lVertex);
}
//===============================================
void GOpenGL::drawLine(sGVertex* vertex, sGColor color, double width) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    glLineWidth(width);
    glBegin(GL_LINES);
	for(int i = 0; i < 2; i++) {
        sGVertex lVertex = vertex[i];
        glColor4f(color.r, color.g, color.b, color.a);
        glVertex3f(lVertex.x, lVertex.y, lVertex.z);
    }
	glEnd();
}
//===============================================
void GOpenGL::drawLine(sGVertex* vertex) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
	sGColor lLineColor = getDataColor("line_color");
	double lLineWidth = getDataDouble("line_width");
	double lGridDiv = getDataDouble("grid_div");
	double lGridXdivVal = getDataDouble("grid_xdiv_val");
	double lGridYdivVal = getDataDouble("grid_ydiv_val");
	double lGridZdivVal = getDataDouble("grid_zdiv_val");

    glLineWidth(lLineWidth);
    glBegin(GL_LINES);
	for(int i = 0; i < 2; i++) {
        sGVertex lVertex = vertex[i];
        glColor4f(lLineColor.r, lLineColor.g, lLineColor.b, lLineColor.a);
        glVertex3f(lVertex.x*lGridDiv/lGridXdivVal, lVertex.y*lGridDiv/lGridYdivVal, lVertex.z*lGridDiv/lGridZdivVal);
    }
	glEnd();
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
    glOrtho(-lRatio, lRatio, -1, 1, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float)glfwGetTime() * 50, 0, 0, 1);
    
    sGVertex lVertex[] = {
        {-0.6, -0.4, 0},
        {0.6, -0.4, 0},
        {0, 0.6, 0}
    };
    sGColor lColor = {
        1, 0, 0, 1
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
void GOpenGL::drawGrid(GLFWwindow* window) {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    int lWidth, lHeight;
    glfwGetFramebufferSize(window, &lWidth, &lHeight);
    float lRatio = (float)lWidth/(float)lHeight;
    glViewport(0, 0, lWidth, lHeight);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-lRatio, lRatio, -1, 1, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    drawGrid();
    if(1) {
        sGVertex lVertex = {3, 5, 0};
        drawPoint(lVertex);
    }
    if(1) {
        sGVertex lVertex[] = {{0, 0, 0}, {3, 5, 0}};
        drawLine(lVertex);
    }
}
//===============================================
void GOpenGL::drawGrid() {
	//GDebug::Instance()->write("GOpenGL", "::", __FUNCTION__, "()", _EOA_);
    double lXmin = getDataDouble("grid_xmin");
    double lXmax = getDataDouble("grid_xmax");
    double lYmin = getDataDouble("grid_ymin");
    double lYmax = getDataDouble("grid_ymax");
    double lDiv = getDataDouble("grid_div");
    double lDivWidth = getDataDouble("grid_div_width");
    sGColor lDivColor = getDataColor("grid_div_color");
    double lAxisWidth = getDataDouble("grid_axis_width");
    sGColor lAxisColor = getDataColor("grid_axis_color");
    sGColor lOrgColor = getDataColor("grid_org_color");
    double lX0 = getDataDouble("grid_x0");
    double lY0 = getDataDouble("grid_y0");
    
    for(double x = lXmin; x <= lXmax; x += lDiv) {
        sGVertex lVertex[] = {
            {x, lYmin, 0},
            {x, lYmax, 0}
        };
        drawLine(lVertex, lDivColor, lDivWidth);
    }
    for(double y = lYmin; y <= lYmax; y += lDiv) {
        sGVertex lVertex[] = {
            {lXmin, y, 0},
            {lXmax, y, 0}
        };
        drawLine(lVertex, lDivColor, lDivWidth);
    }
    if(1) {
        sGVertex lVertex[] = {
            {lXmin, 0, 0},
            {lXmax, 0, 0}
        };
        drawLine(lVertex, lOrgColor, lDivWidth);
    }
    if(1) {
        sGVertex lVertex[] = {
            {0, lYmin, 0},
            {0, lYmax, 0}
        };
        drawLine(lVertex, lOrgColor, lDivWidth);
    }
    if(1) {
        sGVertex lVertex[] = {
            {lXmin, lY0*lDiv, 0},
            {lXmax, lY0*lDiv, 0}
        };
        drawLine(lVertex, lAxisColor, lAxisWidth);
    }
    if(1) {
        sGVertex lVertex[] = {
            {lX0*lDiv, lYmin, 0},
            {lX0*lDiv, lYmax, 0}
        };
        drawLine(lVertex, lAxisColor, lAxisWidth);
    }
}
//===============================================
#endif
//===============================================
