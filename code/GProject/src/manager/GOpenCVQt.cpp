//===============================================
#include "GOpenCVQt.h"
#include "GJson.h"
#include "GManager.h"
//===============================================
GOpenCVQt::GOpenCVQt(QWidget* parent) : 
QFrame(parent) {
    QVBoxLayout* lMainL = new QVBoxLayout;
    QLabel* lLabel = new QLabel;
    lLabel->setText("OPENCV");
    lLabel->setAlignment(Qt::AlignCenter);
    lMainL->addWidget(lLabel);
    setLayout(lMainL);
}
//===============================================
GOpenCVQt::~GOpenCVQt() {
    
}
//===============================================
