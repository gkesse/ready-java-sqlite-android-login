//===============================================
#include "GAdminQt.h"
#include "GJson.h"
#include "GManager.h"
//===============================================
GAdminQt::GAdminQt(QWidget* parent) : 
QFrame(parent) {
    m_name = "ADMIN";

    QVBoxLayout* lMainL = new QVBoxLayout;
    QHBoxLayout* lAddrL = new QHBoxLayout;
    QHBoxLayout* lBodyL = new QHBoxLayout;   
    
    lMainL->setAlignment(Qt::AlignTop);
    lAddrL->setAlignment(Qt::AlignLeft);
    lBodyL->setAlignment(Qt::AlignLeft);
    
    QString lNameK = m_name + QString("/name");
    QStringList lMenu = GJson::Instance()->dataCol(lNameK);
    
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
GAdminQt::~GAdminQt() {
    
}
//===============================================
void GAdminQt::slotMenuClick() {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    QPushButton* lMenuB = qobject_cast<QPushButton*>(sender());
    QString lMenuT = lMenuB->text().toUpper();
    QString lPageK = m_name + lMenuT;
    if(!lQt->pageId.contains(lPageK)) return;
    int lPageId = lQt->pageId[lPageK];
    lQt->page->setCurrentIndex(lPageId);
}
//===============================================
