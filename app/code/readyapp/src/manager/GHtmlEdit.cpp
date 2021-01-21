//===============================================
#include "GHtmlEdit.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GHtmlEdit::GHtmlEdit(QWidget* parent) : GWidget(parent) {
    setObjectName("GHtmlEdit");
    
    QTextEdit* lTextEdit = new QTextEdit;
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lTextEdit);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GHtmlEdit::~GHtmlEdit() {
    
}
//===============================================
