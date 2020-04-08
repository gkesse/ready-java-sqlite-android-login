//===============================================
#include "GWindow.h"
#include "GWindowMath.h"
#include "GDebug.h"
//===============================================
GWindow::GWindow(QWidget* parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWindow");
	m_expression = 0;
	m_textEdit = 0;
}
//===============================================
GWindow::~GWindow() {

}
//===============================================
GWindow* GWindow::Create(string key) {
	//GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	if(key == "math") return new GWindowMath;
	return new GWindowMath;
}
//===============================================
void GWindow::slotRun() {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	QString lExpression = m_expression->getText();
	QScriptEngine lScript;
	double lValue = lScript.evaluate(lExpression).toNumber();
	qDebug() << lExpression << " = " << lValue << "\n";
}
//===============================================
