//===============================================
#include "GError.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GError::GError(QWidget* parent) : GWidget(parent) {
    setObjectName("GError");

    QLabel* lLabel = new QLabel;
    lLabel->setObjectName("workspace");
    lLabel->setText("Page non trouvée");
    lLabel->setAlignment(Qt::AlignCenter);
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lLabel);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);
}
//===============================================
GError::~GError() {
    
}
//===============================================
