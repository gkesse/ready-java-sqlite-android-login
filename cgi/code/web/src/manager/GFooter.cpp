//===============================================
#include "GFooter.h"
#include "GManager.h"
//===============================================
GFooter::GFooter() {

}
//===============================================
GFooter::~GFooter() {
    
}
//===============================================
// method
//===============================================
void GFooter::print() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->mime_type != "text/html") {return;}
    printf("</div>\n");
    printf("</div>\n");
    printf("</body>\n");
    printf("</html>\n");
}
//===============================================
