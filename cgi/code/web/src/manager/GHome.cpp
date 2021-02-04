//===============================================
#include "GHome.h"
#include "GWidget.h"
//===============================================
// constructor
//===============================================
GHome::GHome() {

}
//===============================================
GHome::~GHome() {
    
}
//===============================================
// method
//===============================================
void GHome::print() {    
    GWidget* lListBox = GWidget::Create("listbox");
    lListBox->start();
    lListBox->addItem("Connexion", "home/login", "user");
    lListBox->addItem("SQLite", "home/sqlite", "database");
    lListBox->addItem("OpenCV", "home/opencv", "camera");
    lListBox->end();    
}
//===============================================
