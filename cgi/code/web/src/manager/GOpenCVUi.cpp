//===============================================
#include "GOpenCVUi.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GOpenCVUi::GOpenCVUi() {

}
//===============================================
GOpenCVUi::~GOpenCVUi() {
    
}
//===============================================
// method
//===============================================
void GOpenCVUi::print() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    request();
    printf("<h1>GOpenCVUi : %s</h1>\n", lApp->req.toStdString().c_str());
    printf("<img src='index.cgi?page_id=image&image_id=bmp'/a>\n");
    GManager::Instance()->showEnv();
}
//===============================================
void GOpenCVUi::request() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    lApp->req = GManager::Instance()->getPost();
}
//===============================================
