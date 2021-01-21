//===============================================
#include "GHtmlView.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GHtmlView::GHtmlView(QWidget* parent) : GWidget(parent) {
    setObjectName("GHtmlView");
        
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    //lMainLatout->addWidget(lWidget);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GHtmlView::~GHtmlView() {
    
}
//===============================================
