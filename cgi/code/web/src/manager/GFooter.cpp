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
    printf("</div>\n");
    printf("</div>\n");
    // script
    printf("<script type='text/javascript' src='/js/class/GManager.js'></script>\n");
    printf("<script type='text/javascript' src='/js/request/request.js'></script>\n");
    //
    printf("</body>\n");
    printf("</html>\n");
}
//===============================================
