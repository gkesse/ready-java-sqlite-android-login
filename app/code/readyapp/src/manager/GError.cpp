//===============================================
#include "GError.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GError::GError(QWidget* parent) : GWidget(parent) {
    setObjectName("GError");

    QLabel* lLabel = new QLabel;
    lLabel->setText("Page non trouvée");
    lLabel->setAlignment(Qt::AlignCenter);
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lLabel);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GError::~GError() {
    
}
//===============================================
