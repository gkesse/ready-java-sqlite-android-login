//===============================================
#include "GProcess.h"
#include "GWindowMath.h"
#include "GDebug.h"
#include "GStyle.h"
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
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	bool lRunFlag = 0;
	string lKey = "";
	for(int i = 1; i < argc;) {
		lKey = argv[i++];
		if(lKey == "math") {
			window(argc, argv, lKey.c_str()); lRunFlag = 1; break;
		}
		if(lKey == "string") {
			window(argc, argv, lKey.c_str()); lRunFlag = 1; break;
		}
		break;
	}
	if(lRunFlag == 0) help(argc, argv);
}
//===============================================
void GProcess::help(int argc, char** argv) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	const char* lModule = "gp_cpp";
	printf("\n");
	printf("%s\n", "Description:");
	printf("\t%s\n", "Operations sur le module gp_cpp.");
	printf("\n");
	printf("%s\n", "Utilisation:");
	printf("\t\033[0;35m%s\033[0m : \033[0;33m%s\033[0m\n", lModule, "afficher aide");
	printf("\t\033[0;35m%s\033[0m \033[36m%s\033[0m : \033[0;33m%s\033[0m\n", lModule, "math", "operations mathematiques");
	printf("\t\033[0;35m%s\033[0m \033[36m%s\033[0m : \033[0;33m%s\033[0m\n", lModule, "string", "operations chaines caracteres");
	printf("\n");
}
//===============================================
void GProcess::window(int argc, char** argv, const char* key) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
#if defined(_GUSE_QT_ON_)
	QApplication lApp(argc, argv);
	GStyle::Instance()->process("load", ":/css/style.css");
	GWindow* lWindow = GWindow::Create(key);
	lWindow->show();
	lApp.exec();
#endif
}
//===============================================
