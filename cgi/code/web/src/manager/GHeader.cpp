//===============================================
#include "GHeader.h"
#include "GManager.h"
//===============================================
GHeader::GHeader() {

}
//===============================================
GHeader::~GHeader() {
    
}
//===============================================
// method
//===============================================
void GHeader::print() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->mime_type != "text/html") {return;}
    printf("<!DOCTYPE html>\n");
    printf("<html lang='fr'>\n");
    printf("<head>\n");
    printf("<title>%s</title>\n", lApp->app_name.toStdString().c_str());
    printf("<meta charset='UTF-8'/>\n");
    printf("<link rel='shortcut icon' type='image/png' href='%s'/>\n", lApp->logo_path.toStdString().c_str());
    printf("<meta http-equiv='X-UA-Compatible' content='IE=edge,chrome=1'/>\n");
    printf("<meta name='viewport' content='width=device-width, maximum-scale=1.0, minimum-scale=1.0, initial-scale=1.0, user-scalable=no'/>\n");
    printf("<link rel='stylesheet' href='%s'/>\n", "/libs/google_fonts/Allan/css.css");
    printf("<link rel='stylesheet' href='%s'/>\n", lApp->icon_path.toStdString().c_str());
    //printf("<link rel='stylesheet' href='%s'/>\n", lApp->style_path.toStdString().c_str());
    printf("<link rel='stylesheet' href='/index.cgi?page_id=style'/>\n");
    printf("</head>\n");
    printf("<body>\n");
    printf("<div class='html_page'>\n");
    printf("<div class='main_page'>\n");
}
//===============================================
