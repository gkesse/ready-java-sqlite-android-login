//===============================================
#include "GSelectFile.h"
#include "GManager.h"
//===============================================
GSelectFile::GSelectFile() {

}
//===============================================
GSelectFile::~GSelectFile() {
    
}
//===============================================
// method
//===============================================
void GSelectFile::print() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    request();
    printf("<div class='body'>\n");
    printf("<div>GSelectFile</div>\n");
    printf("</div>\n");
}
//===============================================
void GSelectFile::request() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->req == "upload_image") {
        
    }
    else if(lApp->req == "open_image") {
        
    }
}
//===============================================
