//===============================================
#include "GWidget.h"
#include "GHeader.h"
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
    if(key =="widget") {return new GWidget;}
    if(key =="header") {return new GHeader;}
    return new GWidget;
}
//===============================================
// method
//===============================================
void GWidget::print() {
    printf("<h1>Bonjour tout le monde</h1>\n");
}
//===============================================
