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
    sGApp* lApp = GManager::Instance()->getData()->app;
    request();
    printf("<div class='body'>\n");
    if(lApp->image_file != "") {
        printf("<div><img src='/index.cgi?page_id=image&image_path=%s&image_run=%s'/></div>\n",
        lApp->image_file.toStdString().c_str(), lApp->action.toStdString().c_str());
    }
    printf("</div>\n");
}
//===============================================
void GOpenCVPg::request() {

}
//===============================================
