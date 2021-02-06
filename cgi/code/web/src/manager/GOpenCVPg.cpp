//===============================================
#include "GOpenCVPg.h"
#include "GManager.h"
//===============================================
GOpenCVPg::GOpenCVPg() {

}
//===============================================
GOpenCVPg::~GOpenCVPg() {
    
}
//===============================================
// method
//===============================================
void GOpenCVPg::print() {
    //sGApp* lApp = GManager::Instance()->getData()->app;
    request();
    printf("<div class='body'>\n");
    printf("<div><img src='/index.cgi?page_id=image'/></div>\n");
    printf("</div>\n");
}
//===============================================
void GOpenCVPg::request() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->req == "upload_image") {
        
    }
    else if(lApp->req == "open_image") {
        
    }
}
//===============================================
