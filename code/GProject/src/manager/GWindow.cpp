//===============================================
#include "GWindow.h"
#include "GManager.h"
//===============================================
GWindow::GWindow(QWidget* parent) : 
QFrame(parent) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    // button create
    QVBoxLayout* lMainL = new QVBoxLayout;
    QHBoxLayout* lAddressL = new QHBoxLayout;
    QHBoxLayout* lBodyL = new QHBoxLayout;
    
    lMainL->setAlignment(Qt::AlignTop);
    lAddressL->setAlignment(Qt::AlignLeft);
    lBodyL->setAlignment(Qt::AlignLeft);
    
    for(int i = 0; i < 5; i++) {
        QPushButton* lButton = new QPushButton;
        QString lButtonT = tr("Button %1").arg(i);
        lButton->setText(lButtonT);
        if(i == 0) {
            lAddressL->addWidget(lButton);
            continue;
        }
        lBodyL->addWidget(lButton);
    }
    
    lMainL->addLayout(lAddressL, 0);
    lMainL->addLayout(lBodyL, 1);
    setLayout(lMainL);
    // systeme config
    setWindowTitle(lQt->title);
    resize(lQt->width, lQt->height);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
}
//===============================================
GWindow::~GWindow() {
    
}
//===============================================
