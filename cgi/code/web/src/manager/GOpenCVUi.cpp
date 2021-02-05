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
    //
    printf("<div class='header'>\n");
    // settings
    printf("<div class='menu_id'>\n");
    printf("<button class='button button_id'><i class='icon fa fa-cog'></i> Paramètres</button>\n");
    printf("<div class='content'>\n");
    addItem("upload_image", "Charger une image", "upload");
    addItem("open_image", "Ouvrir une image", "folder-open-o");
    addItem("save_image", "Enregistrer une image", "floppy-o");
    addItem("gray_image", "Convertir une image en niveau de gris", "picture-o");
    addItem("canny_image", "Appliquer le filtre de canny à une image", "picture-o");
    printf("</div>\n");
    printf("</div>\n");
    //
    printf("</div>\n");
    // body
    printf("<div class='body'>Body</div>\n");
    //
    printf("</div>\n");
}
//===============================================
void GOpenCVUi::request() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->req == "
}
//===============================================
void GOpenCVUi::addItem(QString key, QString text, QString icon) {
    printf("<form action='' method='post'>\
    <button class='item' id='req' name='req' value='%s'>\
    <i class='icon fa fa-%s'></i> %s</button></form>\n",
    key.toStdString().c_str(), icon.toStdString().c_str(), text.toStdString().c_str());
}
//===============================================
