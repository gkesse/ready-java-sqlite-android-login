//===============================================
#include "GWindow.h"
#include "GJson.h"
#include "GManager.h"
//===============================================
GWindow::GWindow(QWidget* parent) : 
QFrame(parent) {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    // button create
    QVBoxLayout* lMainL = new QVBoxLayout;
    lMgr->qt->addrL = new QHBoxLayout;
    lMgr->qt->bodyL = new QHBoxLayout;
    
    lMainL->setAlignment(Qt::AlignTop);
    lMgr->qt->addrL->setAlignment(Qt::AlignLeft);
    lMgr->qt->bodyL->setAlignment(Qt::AlignLeft);
    
    QStringList lDataL = GJson::Instance()->dataCol("admin/name");
    
    for(int i = 0; i < lDataL.size(); i++) {
        QPushButton* lButton = new QPushButton;
        QString lButtonT = lDataL[i];
        lButton->setText(lButtonT);
        if(i == 0) {
            lMgr->qt->addrL->addWidget(lButton);
            continue;
        }
        lMgr->qt->bodyL->addWidget(lButton);
    }
    
    lMainL->addLayout(lMgr->qt->addrL, 0);
    lMainL->addLayout(lMgr->qt->bodyL, 1);
    setLayout(lMainL);
    // systeme config
    setWindowTitle(lQt->title.c_str());
    resize(lQt->width, lQt->height);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
}
//===============================================
GWindow::~GWindow() {
    
}
//===============================================
