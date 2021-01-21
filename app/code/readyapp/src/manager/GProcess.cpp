//===============================================
#include "GProcess.h"
#include "GProcessUi.h"
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
    std::string lKey = "test";
    if(argc > 1) {lKey = argv[1];}
    if(lKey == "test") {runTest(argc, argv); return;}
    if(lKey == "ui") {runUi(argc, argv); return;}
    if(lKey == "qt") {runQt(argc, argv); return;}
    runTest(argc, argv);
}
//===============================================
void GProcess::runTest(int argc, char** argv) {
    printf("runTest\n");
}
//===============================================
void GProcess::runUi(int argc, char** argv) {
    GProcessUi::Instance()->run(argc, argv);
}
//===============================================
void GProcess::runQt(int argc, char** argv) {
    printf("runQt\n");
}
//===============================================
