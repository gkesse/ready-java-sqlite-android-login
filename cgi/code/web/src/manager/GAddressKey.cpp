//===============================================
#include "GAddressKey.h"
#include "GManager.h"
//===============================================
GAddressKey::GAddressKey() {

}
//===============================================
GAddressKey::~GAddressKey() {
    
}
//===============================================
// method
//===============================================
void GAddressKey::print() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->mime_type != "text/html") {return;}
    
    QStringList lMap = lApp->page_id.split("/");
    QString lKeyId = "/";
    
    printf("<div class='addresskey'>");
    
    for(int i = 0; i < lMap.size(); i++) {
        if(i != 0) {
            printf("<i class='sep fa fa-chevron-right'></i>\n");
        }
        
        QString lKey = lMap[i];
        
        if(i != 0) {lKeyId += "/";}
        lKeyId += lKey;
        
        printf("<a href='%s'>%s</a>\n", lKeyId.toStdString().c_str(), lKey.toStdString().c_str());
    }
    
    printf("</div>");
}
//===============================================
