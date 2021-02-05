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
    printf("<div class='menu'>\n");
    addItem("open_image", "Ouvrir une image", "file-text-o");
    addItem("open_image", "Ouvrir une image", "file-text-o");
    addItem("open_image", "Ouvrir une image", "file-text-o");
    addItem("open_image", "Ouvrir une image", "file-text-o");
    printf("</div>\n");
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
void GOpenCVUi::addItem(QString key, QString text, QString icon) {
    printf("<form action='' method='post'>\
    <button class='item' id='req' name='req' value='%s'>\
    <i class='icon fa fa-%s'></i> %s</button></form>\n",
    key.toStdString().c_str(), icon.toStdString().c_str(), text.toStdString().c_str());
}
//===============================================
