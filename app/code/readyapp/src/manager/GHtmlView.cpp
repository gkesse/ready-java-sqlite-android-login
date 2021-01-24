//===============================================
#include "GHtmlView.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GHtmlView::GHtmlView(QWidget* parent) : GWidget(parent) {
    setObjectName("GHtmlView");
        
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    //lMainLayout->addWidget(lWidget);
    lMainLayout->setAlignment(Qt::AlignTop);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);
}
//===============================================
GHtmlView::~GHtmlView() {
    
}
//===============================================
