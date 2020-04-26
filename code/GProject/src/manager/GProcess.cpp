//===============================================
#include "GProcess.h"
#include "GWindowMath.h"
#include "GDebug.h"
#include "GStyle.h"
#include "GShell.h"
#include "GDir.h"
#include "GEnv.h"
#include "GMuParser.h"
#include "GMuParserX.h"
#include "GExprTk.h"
#include "GGsl.h"
#include "GOpenCV.h"
#include "GOpenGL.h"
#include "GQt.h"
#include "GQCustomPlot.h"
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
    string lKey = "";
    for(int i = 1; i < argc;) {
    	string lKey = argv[i++];
        if(lKey == "test") {
            test(argc, argv); lRunFlag = 1; break;
        }
        if(lKey == "math") {
            window(argc, argv, lKey.c_str()); lRunFlag = 1; break;
        }
        break;
    }
    if(lRunFlag == 0) help(argc, argv);
}
//===============================================
void GProcess::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GQCustomPlot::Instance()->test(argc, argv);
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
    printf("\t\%s %s : %s\n", lModule, "math", "operations mathematiques");
    printf("\t\%s %s : %s\n", lModule, "muparser <expr> <var>", "operations mathematiques muparser");
    printf("\t\%s %s : %s\n", lModule, "exprtk <expr> <var>", "operations mathematiques exprtk");
    printf("\t\%s %s : %s\n", lModule, "string", "operations chaines caracteres");
    printf("\n");
}
//===============================================
void GProcess::window(int argc, char** argv, const char* key) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GEnv::Instance()->setEnv();
#if defined(_GUSE_QT_ON_)
    QApplication lApp(argc, argv);
    GStyle::Instance()->load(":/css/style.css");
    GWindow* lWindow = GWindow::Create(key);
    lWindow->show();
    lApp.exec();
#endif
}
