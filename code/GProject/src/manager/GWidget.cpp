//===============================================
#include "GWidget.h"
#include "GWidgetTitleBar.h"
#include "GWidgetLineEdit.h"
#include "GWidgetLineEditRun.h"
#include "GWidgetLineEditCheck.h"
#include "GWidgetTextEdit.h"
#include "GWidgetPlot.h"
#include "GWidgetPushButton.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWidget::GWidget(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWidget");
}
//===============================================
GWidget::~GWidget() {

}
//===============================================
GWidget* GWidget::Create(string key) {
	GDebug::Instance()->write("GWidget", "::", __FUNCTION__, "()", _EOA_);
	if(key == "title_bar") return new GWidgetTitleBar;
	if(key == "line_edit") return new GWidgetLineEdit;
	if(key == "line_edit_run") return new GWidgetLineEditRun;
	if(key == "line_edit_check") return new GWidgetLineEditCheck;
	if(key == "text_edit") return new GWidgetTextEdit;
	if(key == "plot") return new GWidgetPlot;
	if(key == "push_button") return new GWidgetPushButton;
	return new GWidgetLineEdit;
}
//===============================================
void GWidget::setLabel(QString label) {}
QString GWidget::getText() {return "";}
bool GWidget::getCheck() {return 0;}
QTextEdit* GWidget::textEdit() {return 0;}
QCustomPlot* GWidget::plot() {return 0;}
//===============================================
void GWidget::slotWindowTitleChange(QString text) {}
void GWidget::slotWindowIconChange(QIcon icon) {}
void GWidget::slotWindowMaximize(int oldState, int newState) {}
void GWidget::slotWindowFullScreen(int oldState, int newState) {}
void GWidget::slotCheck(bool ok) {}
//================================================
#endif
//===============================================
