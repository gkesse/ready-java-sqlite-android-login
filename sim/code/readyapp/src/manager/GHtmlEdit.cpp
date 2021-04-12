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
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lTextEdit);
    lMainLayout->setAlignment(Qt::AlignTop);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);
}
//===============================================
GHtmlEdit::~GHtmlEdit() {
    
}
//===============================================
