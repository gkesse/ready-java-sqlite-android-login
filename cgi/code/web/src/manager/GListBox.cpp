//===============================================
#include "GListBox.h"
//===============================================
// constructor
//===============================================
GListBox::GListBox() {

}
//===============================================
GListBox::~GListBox() {
    
}
//===============================================
// method
//===============================================
void GListBox::start() {
    printf("<div class='listbox'>\n");
}
//===============================================
void GListBox::end() {
    printf("</div>\n");
}
//===============================================
void GListBox::addItem(QString text) {
    printf("<div class='item'>%s</div>\n", text.toStdString().c_str());
}
//===============================================
void GListBox::addItem(QString text, QString link, QString icon) {
    printf("<a href='%s'><div class='item'><i class='fa fa-%s'></i> %s</div></a>\n", link.toStdString().c_str(), icon.toStdString().c_str(), text.toStdString().c_str());
}
//===============================================
