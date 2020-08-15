//===============================================
#include "GProcess.h"
#include "GOpenGL.h"
#include "GDebug.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess() {
    __CLASSNAME__ = __FUNCTION__;
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
void GProcess::process(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    bool lRunFlag = 0;
    for(int i = 1; i < argc;) {
    	std::string lKey = argv[i++];
        if(lKey == "test") {test(argc, argv); lRunFlag = 1; break;}
        break;
    }
    if(lRunFlag == 0) help(argc, argv);
}
//===============================================
void GProcess::help(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    const char* lModule = "gp_cpp";
    printf("\n");
    printf("%s\n", "Description:");
    printf("\t%s\n", "Operations sur le module gp_cpp.");
    printf("\n");
    printf("%s\n", "Utilisation:");
    printf("\t\%s : %s\n", lModule, "afficher aide");
    printf("\t\%s %s : %s\n", lModule, "test", "lancer test");
    printf("\n");
}
//===============================================
void GProcess::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenGL::Instance()->test(argc, argv);
}
//===============================================
