//===============================================
#include "GProcess.h"
#include "GWeb.h"
#include "GImage.h"
#include "GStyle.h"
#include "GManager.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess() {

}
//===============================================
GProcess::~GProcess() {
    
}
//===============================================
GProcess* GProcess::Instance() {
    if(m_instance == 0) {
        m_instance = new GProcess;
    }
    return m_instance;
}
//===============================================
void GProcess::run(int argc, char** argv) {
    QString lKey = "cgi";
    if(argc > 1) {lKey = argv[1];}
    if(lKey == "web") {runWeb(argc, argv); return;}
    if(lKey == "img") {runImg(argc, argv); return;}
    runWeb(argc, argv);
}
//===============================================
void GProcess::runWeb(int argc, char** argv) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    GManager::Instance()->loadEnv();
    if(lApp->page_id == "image") {runImg(argc, argv); return;}
    if(lApp->page_id == "style") {runStyle(argc, argv); return;}
    GWeb::Instance()->run(argc, argv);
}
//===============================================
void GProcess::runImg(int argc, char** argv) {
    GImage::Instance()->run(argc, argv);
}
//===============================================
void GProcess::runStyle(int argc, char** argv) {
    GStyle::Instance()->run(argc, argv);
}
//===============================================
