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
    printf("<div class='box'>\n");
    printf("<form action='' method='post' enctype='multipart/form-data'>\n");
    printf("<label class='label' for='upload_file'>Sélectionner une image à télécharger :</label>\n");
    printf("<input class='button item3' type='file' id='upload_file' name='upload_file' required/>\n");
    printf("<input type='hidden' id='req' name='req' value='upload_image'/>\n");
    printf("<div class=''>\n");
    printf("<a class='button' href='/home/opencv'>\
    <i class='icon fa fa-times'></i> Annuler</a>\n");
    printf("<button class='button' type='submit' id='action' name='action' value='send'>\
    <i class='icon fa fa-upload'></i> Envoyer</button>\n");
    printf("</form>\n");
    printf("</div>\n");
    printf("</div>\n");
    printf("</div>\n");
}
//===============================================
void GUploadFile::setCookies() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    if(lApp->action == "send") {
        QString lUploadFile = GManager::Instance()->getUploadFile("upload_file", "img");
        GManager::Instance()->setCookie("image_file", lUploadFile);
        GManager::Instance()->setCookie("opencv_state", "upload_image");
    }    
}
//===============================================
void GUploadFile::request() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->action == "send") {
        GManager::Instance()->uploadFile("upload_file", "img");
        GManager::Instance()->redirect("/home/opencv");
    }    
}
//===============================================
