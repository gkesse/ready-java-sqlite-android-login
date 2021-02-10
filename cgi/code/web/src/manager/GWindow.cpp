//===============================================
#include "GWindow.h"
#include "GManager.h"
//===============================================
GWindow::GWindow() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    lApp->page_map = GWidget::Create("stackwidget");
    lApp->page_map->addPage("home", "home", "Accueil");
    lApp->page_map->addPage("home/login", "login", "Connexion");
    lApp->page_map->addPage("home/sqlite", "sqlite", "SQLite");
    lApp->page_map->addPage("home/opencv", "opencv", "OpenCV");
    lApp->page_map->addPage("home/error", "error", "Erreur");
}
//===============================================
GWindow::~GWindow() {
    
}
//===============================================
// method
//===============================================
void GWindow::print() {    
    sGApp* lApp = GManager::Instance()->getData()->app;
    GManager::Instance()->selectPage();
    lApp->page_map->setCookies(lApp->page_id);
    printf("content-type: text/html\n\n");
    GWidget::Create("header")->print();
    GWidget::Create("titlebar")->print();
    GWidget::Create("addresskey")->print();
    printf("<div class='window'>\n");
    lApp->page_map->showPage(lApp->page_id);
    printf("</div>\n");
    GWidget::Create("footer")->print();
}
//===============================================
