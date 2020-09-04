//===============================================
#include "GOpenCVQt.h"
#include "GJson.h"
#include "GManager.h"
//===============================================
GOpenCVQt::GOpenCVQt(QWidget* parent) : 
QFrame(parent) {
    QVBoxLayout* lMainL = new QVBoxLayout;
    QHBoxLayout* lAddrL = new QHBoxLayout;
    QHBoxLayout* lBodyL = new QHBoxLayout;
    
    lMainL->setAlignment(Qt::AlignTop);
    lAddrL->setAlignment(Qt::AlignLeft);
    lBodyL->setAlignment(Qt::AlignLeft);
    
    QStringList lMenu = GJson::Instance()->dataCol("ADMIN.OPENCV/name");
    
    for(int i = 0; i < lMenu.size(); i++) {
        QString lMenuT = lMenu[i];
        QPushButton* lMenuB = new QPushButton;
        connect(lMenuB, SIGNAL(clicked()), this, SLOT(slotMenuClick()));
        lMenuB->setText(lMenuT);
        
        if(i == 0) {
            lAddrL->addWidget(lMenuB);
            continue;
        }
        lBodyL->addWidget(lMenuB);
    }

    lMainL->addLayout(lAddrL, 0);
    lMainL->addLayout(lBodyL, 1);
    setLayout(lMainL);
}
//===============================================
GOpenCVQt::~GOpenCVQt() {
    
}
//===============================================
void GOpenCVQt::slotMenuClick() {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    QPushButton* lMenuB = qobject_cast<QPushButton*>(sender());
    QString lMenuT = lMenuB->text().toUpper();
    int lPageId = lQt->pageId[lMenuT];
    lQt->page->setCurrentIndex(lPageId);
}
//===============================================
