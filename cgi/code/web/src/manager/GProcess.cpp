//===============================================
#include "GProcess.h"
#include "GWeb.h"
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
    QString lKey = "web";
    if(argc > 1) {lKey = argv[1];}
    if(lKey == "web") {runWeb(argc, argv); return;}
    if(lKey == "img") {runImg(argc, argv); return;}
    runWeb(argc, argv);
}
//===============================================
void GProcess::runWeb(int argc, char** argv) {
    GWeb::Instance()->run(argc, argv);
}
//===============================================
void GProcess::runImg(int argc, char** argv) {
    printf("content-type: image/bmp\n\n");
    QString lFilename = "./data/img/logo.bmp";
    FILE* lFile = fopen(lFilename.toStdString().c_str(), "rb");
    if(lFile != 0) {
        char lData;
        while(feof(lFile) == 0) {
            fread(&lData, 1, 1, lFile);
            printf("%c", lData);
        }
        fclose(lFile);
    }
}
//===============================================
