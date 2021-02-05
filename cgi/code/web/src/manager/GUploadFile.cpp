//===============================================
#include "GUploadFile.h"
#include "GManager.h"
//===============================================
GUploadFile::GUploadFile() {

}
//===============================================
GUploadFile::~GUploadFile() {
    
}
//===============================================
// method
//===============================================
void GUploadFile::print() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    request();
    printf("<div class='body'>\n");
    printf("<div>GUploadFile</div>\n");
    printf("</div>\n");
}
//===============================================
void GUploadFile::request() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->req == "upload_image") {
        
    }
    else if(lApp->req == "open_image") {
        
    }
}
//===============================================
