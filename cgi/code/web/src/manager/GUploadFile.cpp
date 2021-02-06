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
    request();
    printf("<div class='body'>\n");
    printf("<div class='upload'>\n");
    printf("<form action='' method='post' enctype='multipart/form-data'>\n");
    printf("<div class=''>Sélectionner une image à télécharger :</div>\n");
    printf("<input class='button item3' type='file' id='upload_file' name='upload_file' required/>\n");
    printf("<button class='button' type='submit' id='req' name='req' value='send'>\
    <i class='icon fa fa-upload'></i> Envoyer</button>\n");
    printf("</form>\n");
    printf("</div>\n");
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
