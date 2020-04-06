//===============================================
#include "GProcess.h"
#include "GWindowMath.h"
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
	cout << __CLASSNAME__ << "::" << __FUNCTION__ << "()\n";
}
//===============================================
void GProcess::help(int argc, char** argv) {
	cout << __CLASSNAME__ << "::" << __FUNCTION__ << "()\n";
}
//===============================================
void GProcess::math(int argc, char** argv) {
	QApplication lApp(argc, argv);
	GWindow* lWindow = GWindow::Create("math");
	lWindow->show();
	lApp.exec();
}
//===============================================
