//===============================================
#include "GWidget.h"
#include "GWidgetLineEdit.h"
#include "GWidgetLineEditRun.h"
#include "GWidgetTextEdit.h"
#include "GWidgetTitleBar.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
GWidget::GWidget(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWidget");
	m_label = 0;
	m_lineEidt = 0;
	m_run = 0;
	m_clear = 0;
	m_textEdit = 0;
	m_icon = 0;
	m_title = 0;
	m_minimize = 0;
	m_maximize = 0;
	m_close = 0;
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
	if(key == "title_bar") return new GWidgetTitleBar;
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
QTextEdit* GWidget::textEdit() {
    GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	return m_textEdit;
}
//===============================================
void GWidget::slotWindowTitleChange(QString text) {
    GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	m_title->setText(text);
}
//===============================================
void GWidget::slotWindowIconChange(QIcon icon) {
    GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	m_icon->setPixmap(icon.pixmap(QSize(20, 20)));
}
//===============================================
void GWidget::slotWindowMaximize(int oldState, int newState) {
    GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
    GPicto::Instance()->process("color", "orange");
    if(oldState == Qt::WindowMaximized) {
		m_maximize->setIcon(GPicto::Instance()->process("picto", fa::windowmaximize));
	}
	else if(oldState == Qt::WindowFullScreen) {
		m_maximize->setIcon(GPicto::Instance()->process("picto", fa::windowmaximize));
	}
	else {
		m_maximize->setIcon(GPicto::Instance()->process("picto", fa::windowrestore));
	}
}
//===============================================
void GWidget::slotWindowFullScreen(int oldState, int newState) {
    GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
    GPicto::Instance()->process("color", "orange");
	if(oldState == Qt::WindowFullScreen) {
		if(newState == Qt::WindowMaximized) {
			m_maximize->setIcon(GPicto::Instance()->process("picto", fa::windowrestore));
		}
		else {
			m_maximize->setIcon(GPicto::Instance()->process("picto", fa::windowmaximize));
		}
	}
	else {
		m_maximize->setIcon(GPicto::Instance()->process("picto", fa::windowrestore));
	}
}
//===============================================
