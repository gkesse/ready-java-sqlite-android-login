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
    //sGApp* lApp = GManager::Instance()->getData()->app;
    request();
    printf("<div class='opencv_id'>\n");
    // settings
    printf("<div class='setting'>\n");
    printf("<button class='button_id'><i class='icon fa fa-cog'></i> Paramètres</button>\n");
    printf("</div>\n");
    // body
    printf("<div class='body'>Body</div>\n");
    //
    printf("</div>\n");
}
//===============================================
void GOpenCVUi::request() {
    //sGApp* lApp = GManager::Instance()->getData()->app;
}
//===============================================
