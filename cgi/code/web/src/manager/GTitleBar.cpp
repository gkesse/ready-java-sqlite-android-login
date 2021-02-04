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
    printf("<div class='border_id0 logo'>logo</div>\n");
    printf("<div class='border_id0 app_name'>app_name</div>\n");
    printf("<div class='border_id0 title'>title</div>\n");
    printf("<form class='border_id0' action='' method='post'>\
    <button class='login button_id' type='submit' id='req' name='req' value='login'>\
    <i class='icon fa fa-user'></i> Se Connecter</button></form>\n");
    printf("</div>\n");
}
//===============================================
