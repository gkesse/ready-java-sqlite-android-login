//===============================================
#include "GForm.h"
#include "GWidget.h"
//===============================================
GForm* GForm::m_instance = 0;
//===============================================
GForm::GForm() {
    
}
//===============================================
GForm::~GForm() {
    
}
//===============================================
GForm* GForm::Instance() {
    if(m_instance == 0) {
        m_instance = new GForm;
    }
    return m_instance;
}
//===============================================
QFrame* GForm::create(QString key) {
    if(key == "default") {return createDefault();}
    if(key == "key_value") {return createKeyValue();}
    return createDefault();
}
//===============================================
QFrame* GForm::createDefault() {
    QFrame* lWidget = new QFrame;
    lWidget->setObjectName("workspace");
    return lWidget;
}
//===============================================
QFrame* GForm::createKeyValue() {
    QFrame* lWidget = new QFrame;
    QFrame* lContent = new QFrame;
    
    QLabel* lTitle = new QLabel;
    lTitle->setText("Ajouter un titre");
    
    GWidget* lName = GWidget::Create("lineedit");
    lName->setContent("label", "Nom de la variable");
    lName->setObjectName("workspace");
    QFrame* lValue = createLineEdit();
    
    QVBoxLayout* lContentLayout = new QVBoxLayout;
    lContentLayout->addWidget(lTitle);
    lContentLayout->addWidget(lName);
    lContentLayout->addWidget(lValue);
    lContentLayout->setMargin(10);
    lContentLayout->setSpacing(10);
    
    lContent->setLayout(lContentLayout);    
    lContent->setMaximumWidth(400);    
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lContent);
    lMainLayout->setAlignment(Qt::AlignCenter);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    lWidget->setLayout(lMainLayout);    
    return lWidget;
}
//===============================================
QFrame* GForm::createLineEdit() {
    QFrame* lWidget = new QFrame;
    lWidget->setStyleSheet("\
    QFrame {\n\
        background-color: #503030;\n\
        border: 2px solid #503030;\n\
    }\n\
    QLabel {\n\
        min-width: 100px;\n\
        padding: 0px 10px;\n\
    }\n\
    QLineEdit {\n\
        padding: 2px 10px;\n\
    }\n\
    ");
    
    QLabel* lLabel = new QLabel;
    lLabel->setText("Label");
    
    QLineEdit* lLineEdit = new QLineEdit;
        
    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->addWidget(lLabel);
    lMainLayout->addWidget(lLineEdit);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    lWidget->setLayout(lMainLayout);    
    return lWidget;
}
//===============================================
