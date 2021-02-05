//===============================================
#include "GTitleBar.h"
#include "GManager.h"
//===============================================
GTitleBar::GTitleBar() {

}
//===============================================
GTitleBar::~GTitleBar() {
    
}
//===============================================
// method
//===============================================
void GTitleBar::print() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    request();
    if(lApp->mime_type != "text/html") {return;}
    QString lTitle = lApp->title_map[lApp->page_id];
    printf("<div class='titlebar'>\n");
    printf("<div class='content'>\n");
    printf("<a href='/home'>\n");
    printf("<img class='logo' src='/data/img/logo_flat.png'/>\n");
    printf("<div class='app_name'>%s</div>\n", lApp->app_name.toStdString().c_str());
    printf("</a>\n");
    printf("<div class='title'>%s</div>\n", lTitle.toStdString().c_str());
    printf("<form action='' method='post'>\
    <button class='login button' type='submit' id='req' name='req' value='login'>\
    <i class='icon fa fa-user'></i> Se Connecter</button></form>\n");
    printf("</div>\n");
    printf("</div>\n");
}
//===============================================
void GTitleBar::request() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->req == "login") {
        GManager::Instance()->redirect("/home/login");
    }
}
//===============================================
