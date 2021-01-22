//===============================================
#include "GStackWidget.h"
//===============================================
// constructor
//===============================================
GStackWidget::GStackWidget(QWidget* parent) : QStackedWidget(parent) {
    setObjectName("GStackWidget");
}
//===============================================
GStackWidget::~GStackWidget() {
    
}
//===============================================
// method
//===============================================
QSize GStackWidget::sizeHint() const {
    if(count() == 0) return QSize(0, 0);
    return currentWidget()->sizeHint();
}
//===============================================
QSize GStackWidget::minimumSizeHint() const {
    if(count() == 0) return QSize(0, 0);
    return currentWidget()->minimumSizeHint();
}
//===============================================