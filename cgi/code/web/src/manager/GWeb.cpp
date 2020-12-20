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
    printf("Content-type: text/html\n\n");
    GManager::Instance()->loadEnv();
    GWidget::Create("header")->print();
    loadPage();
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
    addPage("home/error", "error");
}
//===============================================
void GWeb::showPage() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->page_id == "") {redirect("/home"); return;}
    if(!m_addressMap.count(lApp->page_id)) {lApp->page_id = "home/error";}
    std::string lPageId = m_addressMap[lApp->page_id];
    GWidget::Create(lPageId)->print();
}
//===============================================
void GWeb::redirect(std::string newUrl) {
    printf("<html>\n");
    printf("<head>\n");
    printf("<title>Redirection en HTML</title>\n");
    printf("<meta http-equiv='refresh' content='0; URL=%s'>\n", newUrl.c_str());
    printf("</head>\n");
    printf("<body>\n");
    printf("</body>\n");
    printf("</html>\n");
}
//===============================================
