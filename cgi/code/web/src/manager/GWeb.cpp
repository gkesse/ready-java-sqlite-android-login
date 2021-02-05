//===============================================
#include "GWeb.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
GWeb* GWeb::m_instance = 0;
//===============================================
GWeb::GWeb() {

}
//===============================================
GWeb::~GWeb() {
    
}
//===============================================
GWeb* GWeb::Instance() {
    if(m_instance == 0) {
        m_instance = new GWeb;
    }
    return m_instance;
}
//===============================================
// method
//===============================================
void GWeb::run(int argc, char** argv) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    loadPage();
    selectPage();
    mimeType();
    printf("content-type: %s\n\n", lApp->mime_type.toStdString().c_str());
    GWidget::Create("header")->print();
    GWidget::Create("titlebar")->print();
    GWidget::Create("addresskey")->print();
    showPage();
    GWidget::Create("footer")->print();
}
//===============================================
void GWeb::addPage(QString address, QString key, QString title) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    lApp->address_map[address] = key;
    lApp->title_map[address] = title;
}
//===============================================
void GWeb::loadPage() {
    addPage("", "home", "Accueil");
    addPage("home", "home", "Accueil");
    addPage("home/login", "login", "Connexion");
    addPage("home/sqlite", "sqlite", "SQLite");
    addPage("home/opencv", "opencv", "OpenCV");
    addPage("home/error", "error", "Erreur");
}
//===============================================
void GWeb::selectPage() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->page_id == "") {GManager::Instance()->redirect("/home");}
    if(!lApp->address_map.count(lApp->page_id)) {GManager::Instance()->redirect("/"+lApp->page_last);}
    else {setCookie("page_last", lApp->page_id);}
}
//===============================================
void GWeb::showPage() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QString lPageId = lApp->address_map[lApp->page_id];
    printf("<div class='window'>\n");
    GWidget::Create(lPageId)->print();
    printf("</div>\n");
}
//===============================================
void GWeb::setCookie(QString key, QString value) {
    printf("Set-Cookie:%s = %s;\n", key.toStdString().c_str(), value.toStdString().c_str());
}
//===============================================
void GWeb::mimeType() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->page_id == "home/opencv2") {lApp->mime_type = "image/bmp";}
}
//===============================================
