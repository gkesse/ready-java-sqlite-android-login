//===============================================
#include "GSQLiteQt.h"
#include "GJson.h"
#include "GManager.h"
//===============================================
GSQLiteQt::GSQLiteQt(QWidget* parent) : 
QFrame(parent) {
    QVBoxLayout* lMainL = new QVBoxLayout;
    QLabel* lLabel = new QLabel;
    lLabel->setText("SQLITE");
    lLabel->setAlignment(Qt::AlignCenter);
    lMainL->addWidget(lLabel);
    setLayout(lMainL);
}
//===============================================
GSQLiteQt::~GSQLiteQt() {
    
}
//===============================================
