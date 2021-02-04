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
    printf("<h1>GOpenCVUi</h1>\n");
    printf("<img src='index.cgi?page_id=image&image_id=bmp'/a>\n");
    GManager::Instance()->showEnv();
}
//===============================================
