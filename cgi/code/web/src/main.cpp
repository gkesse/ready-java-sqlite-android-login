//===============================================
#include "GWidget.h"
//===============================================
int main(int argc, char** argv) {
    printf("Content-type: text/html\n\n");
    GWidget::Create("footer")->print();
    return 0;
}
//===============================================
