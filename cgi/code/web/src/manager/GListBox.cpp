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
void GListBox::addItem(std::string text) {
    printf("<div class='item'>%s</div>\n", text.c_str());
}
//===============================================
void GListBox::addItem(std::string text, std::string icon) {
    printf("<div class='item'><i class='fa fa-%s'></i> %s</div>\n", icon.c_str(), text.c_str());
}
//===============================================
