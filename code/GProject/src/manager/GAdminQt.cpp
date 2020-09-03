//===============================================
#include "GAdminQt.h"
#include "GJson.h"
#include "GManager.h"
//===============================================
GAdminQt::GAdminQt(QWidget* parent) : 
QFrame(parent) {
    QVBoxLayout* lMainL = new QVBoxLayout;
    QLabel* lLabel = new QLabel;
    lLabel->setText("ADMIN");
    lLabel->setAlignment(Qt::AlignCenter);
    lMainL->addWidget(lLabel);
    setLayout(lMainL);
}
//===============================================
GAdminQt::~GAdminQt() {
    
}
//===============================================
