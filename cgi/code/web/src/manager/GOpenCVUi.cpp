//===============================================
#include "GOpenCVUi.h"
#include "GManager.h"
//===============================================
GOpenCVUi::GOpenCVUi() {
    m_workspace = GWidget::Create("stackwidget");
    m_workspace->addPage("home", "opencvpg", "");
    m_workspace->addPage("upload_image", "uploadfile", "Charger une image");
    m_workspace->addPage("open_image", "selectfile", "Ouvrir une image");
    m_title = "";
}
//===============================================
GOpenCVUi::~GOpenCVUi() {
    
}
//===============================================
// method
//===============================================
void GOpenCVUi::print() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    m_title = m_workspace->getTitle(lApp->req);
    request();
    printf("<div class='opencv'>\n");
    //
    printf("<div class='header'>\n");
    // settings
    printf("<div class='menu'>\n");
    printf("<button class='button'><i class='icon fa fa-cog'></i> Paramètres</button>\n");
    printf("<div class='content2'>\n");
    addItem("upload_image", "Charger une image", "upload");
    addItem("open_image", "Ouvrir une image", "folder-open-o");
    addItem("save_image", "Enregistrer une image", "floppy-o");
    addItem("gray_image", "Convertir une image en niveau de gris", "picture-o");
    addItem("canny_image", "Appliquer le filtre de canny à une image", "picture-o");
    printf("</div>\n");
    printf("</div>\n");
    //
    printf("<div class='title2'>%s</div>\n", m_title.toStdString().c_str());
    //
    printf("</div>\n");
    // body
    m_workspace->showPage(lApp->req);
    //
    printf("</div>\n");
}
//===============================================
void GOpenCVUi::setCookies() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->req == "") {lApp->req = "home";}
    m_workspace->setCookies(lApp->req);
}
//===============================================
void GOpenCVUi::request() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->req == "") {lApp->req = "home";}
}
//===============================================
void GOpenCVUi::addItem(QString key, QString text, QString icon) {
    printf("<form action='' method='post'>\
    <button class='item2' id='req' name='req' value='%s'>\
    <i class='icon fa fa-%s'></i> %s</button></form>\n",
    key.toStdString().c_str(), icon.toStdString().c_str(), text.toStdString().c_str());
}
//===============================================
