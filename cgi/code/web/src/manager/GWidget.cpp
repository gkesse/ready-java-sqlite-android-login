//===============================================
// widget
#include "GWidget.h"
#include "GHeader.h"
#include "GFooter.h"
#include "GListBox.h"
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
GWidget* GWidget::Create(std::string key) {
    // widget
    if(key =="widget") {return new GWidget;}
    if(key =="header") {return new GHeader;}
    if(key =="footer") {return new GFooter;}
    if(key =="listbox") {return new GListBox;}
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
void GWidget::addItem(std::string text) {}
void GWidget::addItem(std::string text, std::string link, std::string icon) {}
//===============================================
