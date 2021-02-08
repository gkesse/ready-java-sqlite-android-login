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
        printf("<div><img src='/index.cgi?page_id=image&image_path=%s'/></div>\n",
        lApp->image_file.toStdString().c_str());
    }
    printf("</div>\n");
}
//===============================================
void GOpenCVPg::request() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->opencv_state == "upload_image") {
        //lApp->image_file = lApp->upload_file;
    }
}
//===============================================
