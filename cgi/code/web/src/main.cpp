//===============================================
#include "GWidget.h"
//===============================================
int main(int argc, char** argv) {
    printf("Content-type: text/html\n\n");
    GWidget::Create("home")->print();
    return 0;
}
//===============================================
