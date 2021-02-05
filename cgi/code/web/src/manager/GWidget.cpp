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
// page
#include "GHome.h"
#include "GLogin.h"
#include "GSQLiteUi.h"
#include "GOpenCVUi.h"
#include "GError.h"
//===============================================
// constructor
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
    // page
    if(key =="home") {return new GHome;}
    if(key =="login") {return new GLogin;}
    if(key =="sqlite") {return new GSQLiteUi;}
    if(key =="opencv") {return new GOpenCVUi;}
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
void QString getTitle(QString key) {return "";}
//===============================================
