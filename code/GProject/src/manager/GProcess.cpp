//===============================================
#include "GProcess.h"
#include "GWindowMath.h"
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
    GDebug::Instance()->process("write", __CLASSNAME__, "::", __FUNCTION__, "()");
	bool lRunFlag = 0;
	for(int i = 1; i < argc;) {
		string lKey = argv[i++];
		if(lKey == "test") {
			test(argc, argv); lRunFlag = 1; break;
		}
		else if(lKey == "help") {
			help(argc, argv); lRunFlag = 1; break;
		}
		else if(lKey == "math") {
			math(argc, argv); lRunFlag = 1; break;
		}
		break;
	}
	if(lRunFlag == 0) cout << "le process est inconnu\n";
}
//===============================================
void GProcess::test(int argc, char** argv) {
    GDebug::Instance()->process("write", __CLASSNAME__, "::", __FUNCTION__, "()");
}
//===============================================
void GProcess::help(int argc, char** argv) {
    GDebug::Instance()->process("write", __CLASSNAME__, "::", __FUNCTION__, "()");
}
//===============================================
void GProcess::math(int argc, char** argv) {
    GDebug::Instance()->process("write", __CLASSNAME__, "::", __FUNCTION__, "()");
	QApplication lApp(argc, argv);
	GWindow* lWindow = GWindow::Create("math");
	lWindow->show();
	lApp.exec();
}
//===============================================
