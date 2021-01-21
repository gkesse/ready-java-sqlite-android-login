//===============================================
#include "GWeb.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
GWeb* GWeb::m_instance = 0;
//===============================================
// constructor
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
    GManager::Instance()->loadEnv();
    loadPage();
    selectPage();
    printf("Content-type: text/html\n\n");
    GWidget::Create("header")->print();
    showPage();
    GWidget::Create("footer")->print();
}
//===============================================
void GWeb::addPage(std::string address, std::string key) {
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
    std::string lPageId = m_addressMap[lApp->page_id];
    GWidget::Create(lPageId)->print();
}
//===============================================
void GWeb::redirect(std::string newUrl) {
    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("<head>\n");
    printf("<title>Redirection</title>\n");
    printf("<meta http-equiv='refresh' content='0; URL=%s'>\n", newUrl.c_str());
    printf("</head>\n");
    printf("<body>\n");
    printf("</body>\n");
    printf("</html>\n");
}
//===============================================
void GWeb::setCookie(std::string key, std::string value) {
    printf("Set-Cookie:%s = %s;\n", key.c_str(), value.c_str());
}
//===============================================
