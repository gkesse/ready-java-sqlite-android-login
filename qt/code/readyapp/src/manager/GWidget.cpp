//===============================================
// widget
#include "GWidget.h"
#include "GLineEdit.h"
#include "GListBox.h"
#include "GListWidget.h"
#include "GTableWidget.h"
#include "GTitleBar.h"
#include "GAddressBar.h"
#include "GAddressKey.h"
#include "GKeyValue.h"
#include "GTitle.h"
#include "GButtonRow.h"
#include "GStackWidget.h"
#include "GTextEdit.h"
// page
#include "GWindow.h"
#include "GHome.h"
// tuto
#include "GDemo.h"
#include "GOpenCVQt.h"
#include "GOpenGLQt.h"
#include "GGslQt.h"
// qt
#include "GQtPg.h"
#include "GGraphicsView.h"
#include "GMainWindow.h"
#include "GDataStream.h"
#include "GQCustomPlotQt.h"
// login
#include "GLogin.h"
#include "GProfil.h"
#include "GUserAdd.h"
#include "GUserShow.h"
#include "GUserMap.h"
// table
#include "GSQLiteTables.h"
#include "GSchema.h"
// html
#include "GPdfUi.h"
#include "GHtmlEdit.h"
#include "GHtmlView.h"
// timesheet
#include "GTimesheet.h"
// debug
#include "GDebug.h"
// error
#include "GError.h"
//===============================================
// constructor
//===============================================
GWidget::GWidget(QWidget* parent) : QFrame(parent) {
    setObjectName("workspace");
    m_oneOnly = true;
}
//===============================================
GWidget::~GWidget() {
    
}
//===============================================
GWidget* GWidget::Create(QString key, QWidget* parent) {
    // widget
    if(key == "widget") return new GWidget(parent);
    if(key == "lineedit") return new GLineEdit(parent);
    if(key == "listbox") return new GListBox(parent);
    if(key == "listwidget") return new GListWidget(parent);
    if(key == "tablewidget") return new GTableWidget(parent);
    if(key == "titlebar") return new GTitleBar(parent);
    if(key == "addressbar") return new GAddressBar(parent);
    if(key == "addresskey") return new GAddressKey(parent);
    if(key == "keyvalue") return new GKeyValue(parent);
    if(key == "title") return new GTitle(parent);
    if(key == "buttonrow") return new GButtonRow(parent);
    if(key == "stackwidget") return new GStackWidget(parent);
    if(key == "textedit") return new GTextEdit(parent);
    // page
    if(key == "window") return new GWindow(parent);
    if(key == "home") return new GHome(parent);
    // tuto
    if(key == "demo") return new GDemo(parent);
    if(key == "opencv") return new GOpenCVQt(parent);
    if(key == "opengl") return new GOpenGLQt(parent);
    if(key == "gsl") return new GGslQt(parent);
    // qt
    if(key == "qt") return new GQtPg(parent);
    if(key == "qgraphicsview") return new GGraphicsView(parent);
    if(key == "qmainwindow") return new GMainWindow(parent);
    if(key == "qdatastream") return new GDataStream(parent);
    if(key == "qcustomplot") return new GQCustomPlotQt(parent);
    // login
    if(key == "login") return new GLogin(parent);
    if(key == "profil") return new GProfil(parent);
    if(key == "useradd") return new GUserAdd(parent);
    if(key == "usershow") return new GUserShow(parent);
    if(key == "usermap") return new GUserMap(parent);
    // table
    if(key == "sqlitetables") return new GSQLiteTables(parent);
    if(key == "schema") return new GSchema(parent);
    // pdf
    if(key == "pdfui") return new GPdfUi(parent);
    if(key == "htmledit") return new GHtmlEdit(parent);
    if(key == "htmlview") return new GHtmlView(parent);
    // timesheet
    if(key == "timesheet") return new GTimesheet(parent);
    // debug
    if(key == "debug") return new GDebug(parent);
    // widget
    return new GError(parent);
}
//===============================================
// method
//===============================================
void GWidget::addPage(QString key, QString title, QWidget* widget, bool isDefault) {}
//
int GWidget::loadPage() {return 1;}
//
void GWidget::addItem(QString key, QString text) {}
void GWidget::addItem(QString key, QString text, int icon) {}
void GWidget::addItem(int row, int col, QString text) {}
void GWidget::addItem(QLayout* layout) {}
//
void GWidget::removeItem(int index) {}
//
void GWidget::setContent(QString text) {}
void GWidget::setContent(QString key, QString text) {}
void GWidget::setContent(QString key, int icon, QColor color) {}
void GWidget::setContent(QString key, int data) {}
//
void GWidget::setOption(QString key, QVariant data) {}
void GWidget::setOption(QString key) {}
//
void GWidget::getData(QString key, QString& data) {}
//
void GWidget::resetContent() {}
//
void GWidget::clearContent() {}
//
void GWidget::fillContent() {}
//
void GWidget::setLabel(QString text) {}
void GWidget::setLabelWidth(int width) {}
void GWidget::setLabelIcon(int icon, QColor color) {}
void GWidget::setGoToIcon(int icon, QColor color) {}
void GWidget::setIcon(int icon, QColor color) {}
void GWidget::setText(QString text) {}
void GWidget::setEchoMode(int mode) {}
void GWidget::setReadOnly(bool flag) {}
void GWidget::setTitle(QString text) {}
void GWidget::setTitleIcon(int icon) {}
void GWidget::setAlignment(int alignment) {}
void GWidget::setPage(QString page) {}
void GWidget::setClear(bool flag) {}
void GWidget::append(QString text) {}
void GWidget::setName(QString text) {}
void GWidget::setValue(QString text) {}
void GWidget::setNameLabel(QString text) {}
void GWidget::setValueLabel(QString text) {}
QString GWidget::getText() {return "";}
QString GWidget::getName() {return "";}
QString GWidget::getValue() {return "";}
GWidget* GWidget::getPage(QString key) {return 0;}
int GWidget::getPageId(QString key) {return 0;}
QWidget* GWidget::getWidget(QString key) {return 0;}
QString GWidget::getTitle(QString key) {return "";}
QString GWidget::getDefaultKey() {return "";}
//===============================================
// slot
//===============================================
void GWidget::slotItemClick() {}
void GWidget::slotItemClick(QAction* action) {}
void GWidget::slotPageOpen() {}
//===============================================
