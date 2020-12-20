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
    loadPage(argc, argv);
    GWidget::Create("footer")->print();
}
//===============================================
void GWeb::loadPage(int argc, char** argv) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->page_id == "") {GWidget::Create("home")->print(); return;}
    if(lApp->page_id == "home") {GWidget::Create("home")->print(); return;}
    GWidget::Create("window")->print();
    printf("%s.........\n", lApp->page_id.c_str());
}
//===============================================
