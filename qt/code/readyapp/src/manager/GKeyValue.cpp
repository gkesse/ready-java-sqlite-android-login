//===============================================
#include "GKeyValue.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
GKeyValue::GKeyValue(QWidget* parent) : GWidget(parent) {
    setObjectName("GKeyValue");
    
    QFrame* lContent = new QFrame;
    
    QLabel* lTitle = new QLabel;
    lTitle->setText("Ajouter un titre");
    
    GWidget* lName = GWidget::Create("lineedit");
    lName->setObjectName("mode_label");
    lName->setLabel("Nom de la variable");
    lName->setLabelWidth(150);
    lName->setLabelIcon(fa::book);
    
    GWidget* lValue = GWidget::Create("lineedit");
    lValue->setObjectName("mode_label");
    lValue->setLabel("Valeur de la variable");
    lValue->setLabelWidth(150);
    lValue->setLabelIcon(fa::book);
    
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
    
    setLayout(lMainLayout);    
}
//===============================================
GKeyValue::~GKeyValue() {
    
}
//===============================================
