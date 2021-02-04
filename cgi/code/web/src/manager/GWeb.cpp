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
    GManager::Instance()->loadEnv();
    loadPage();
    selectPage();
    mimeType();
    printf("Content-type: %s\n\n", lApp->mime_type.toStdString().c_str());
    GWidget::Create("header")->print();
    showPage();
    GWidget::Create("footer")->print();
}
//===============================================
void GWeb::addPage(QString address, QString key) {
    m_addressMap[address] = key;
}
//===============================================
void GWeb::loadPage() {
    addPage("", "home");
    addPage("home", "home");
    addPage("home/login", "login");
    addPage("home/sqlite", "sqlite");
    addPage("home/opencv", "opencv");
    addPage("home/error", "error");
}
//===============================================
void GWeb::selectPage() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->page_id == "") {redirect("/home"); return;}
    if(!m_addressMap.count(lApp->page_id)) {redirect("/"+lApp->page_last);}
    else {setCookie("page_last", lApp->page_id);}
}
//===============================================
void GWeb::showPage() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QString lPageId = m_addressMap[lApp->page_id];
    GWidget::Create(lPageId)->print();
}
//===============================================
void GWeb::redirect(QString newUrl) {
    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("<head>\n");
    printf("<title>Redirection</title>\n");
    printf("<meta http-equiv='refresh' content='0; URL=%s'>\n", newUrl.toStdString().c_str());
    printf("</head>\n");
    printf("<body>\n");
    printf("</body>\n");
    printf("</html>\n");
    exit(0);
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
