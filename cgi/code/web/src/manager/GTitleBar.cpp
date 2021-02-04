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
    if(lApp->mime_type != "text/html") {return;}
    printf("<div class='titlebar_id'>\n");
    printf("<div class='content'>\n");
    printf("<img class='logo' src='/data/img/logo_flat.png'/>\n");
    printf("<div class='app_name'>%s</div>\n", lApp->app_name.toStdString().c_str());
    printf("<div class='title'>title</div>\n");
    printf("<form action='' method='post'>\
    <button class='login button_id' type='submit' id='req' name='req' value='login'>\
    <i class='icon fa fa-user'></i> Se Connecter</button></form>\n");
    printf("</div>\n");
    printf("</div>\n");
}
//===============================================
