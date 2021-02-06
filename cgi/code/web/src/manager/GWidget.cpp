//===============================================
// widget
#include "GWidget.h"
#include "GHeader.h"
#include "GFooter.h"
#include "GListBox.h"
#include "GTitleBar.h"
#include "GAddressKey.h"
#include "GUploadFile.h"
#include "GSelectFile.h"
#include "GStackWidget.h"
#include "GWindow.h"
// page
#include "GHome.h"
#include "GLogin.h"
#include "GSQLiteUi.h"
#include "GOpenCVUi.h"
#include "GOpenCVPg.h"
#include "GError.h"
//===============================================
GWidget::GWidget() {

}
//===============================================
GWidget::~GWidget() {
    
}
//===============================================
GWidget* GWidget::Create(QString key) {
    // widget
    if(key =="widget") {return new GWidget;}
    if(key =="header") {return new GHeader;}
    if(key =="footer") {return new GFooter;}
    if(key =="listbox") {return new GListBox;}
    if(key =="titlebar") {return new GTitleBar;}
    if(key =="addresskey") {return new GAddressKey;}
    if(key =="uploadfile") {return new GUploadFile;}
    if(key =="selectfile") {return new GSelectFile;}
    if(key =="stackwidget") {return new GStackWidget;}
    if(key =="window") {return new GWindow;}
    // page
    if(key =="home") {return new GHome;}
    if(key =="login") {return new GLogin;}
    if(key =="sqlite") {return new GSQLiteUi;}
    if(key =="opencv") {return new GOpenCVUi;}
    if(key =="opencvpg") {return new GOpenCVPg;}
    // error
    if(key =="error") {return new GError;}
    // default
    return new GWidget;
}
//===============================================
// method
//===============================================
void GWidget::print() {}
void GWidget::start() {}
void GWidget::end() {}
void GWidget::addItem(QString text) {}
void GWidget::addItem(QString text, QString link, QString icon) {}
void GWidget::addPage(QString key, QString page, QString title) {}
void GWidget::showPage(QString key) {}
QString GWidget::getTitle(QString key) {return "";}
QString GWidget::getPage(QString key) {return "";}
void GWidget::setCookies(QString key) {}
void GWidget::setCookies() {}
//===============================================
