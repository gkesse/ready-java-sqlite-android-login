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
    printf("<div class='border_id'>\n");
    printf("<div class='logo'>logo</div>\n");
    printf("<div class='app_name'>app_name</div>\n");
    printf("<div class='title'>title</div>\n");
    printf("<form action='' method='post'>\
    <button class='login button_id' type='submit' id='req' name='req' value='login'>\
    <i class='icon fa fa-sign-in'></i> Se Connecter</button></form>\n");
    printf("</div>\n");
}
//===============================================
