//===============================================
#include "GWidget.h"
#include "GWidgetLineEdit.h"
#include "GWidgetLineEditRun.h"
#include "GWidgetTextEdit.h"
#include "GDebug.h"
//===============================================
GWidget::GWidget(QWidget* parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWidget");
	m_label = 0;
	m_lineEidt = 0;
	m_run = 0;
	m_clear = 0;
	m_textEdit = 0;
}
//===============================================
GWidget::~GWidget() {

}
//===============================================
GWidget* GWidget::Create(string key) {
	//GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	if(key == "line_edit") return new GWidgetLineEdit;
	if(key == "line_edit_run") return new GWidgetLineEditRun;
	if(key == "text_edit") return new GWidgetTextEdit;
	return new GWidgetLineEdit;
}
//===============================================
void GWidget::setLabel(QString label) {
    GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	m_label->setText(label);
}
//===============================================
QString GWidget::getText() {
    GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	return m_lineEidt->text();
}
//===============================================
