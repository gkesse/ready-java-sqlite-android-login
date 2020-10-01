//===============================================
#include "GSQLiteQt.h"
#include "GJson.h"
#include "GManager.h"
//===============================================
GSQLiteQt::GSQLiteQt(QWidget* parent) : 
QFrame(parent) {
    m_name = "ADMIN.SQLITE";
    
    QVBoxLayout* lMainL = new QVBoxLayout;
    QHBoxLayout* lAddrL = new QHBoxLayout;
    QHBoxLayout* lBodyL = new QHBoxLayout;
    
    lMainL->setAlignment(Qt::AlignTop);
    lAddrL->setAlignment(Qt::AlignLeft);
    lBodyL->setAlignment(Qt::AlignLeft);
    
    QStringList lMenu = GJson::Instance()->dataCol("ADMIN.SQLITE/name");
    
    for(int i = 0; i < lMenu.size(); i++) {
        QString lMenuT = lMenu[i];
        QPushButton* lMenuB = 0;
        
        if(i == 0) {
            QStringList lMenuAL = lMenuT.split(".");
            QString lMenuAC = "";
            for(int j = 0; j < lMenuAL.size(); j++) {
                QString lMenuAT = lMenuAL[j];
                if(j != 0) lMenuAC += ".";
                lMenuAC += lMenuAT;
                m_addressK[lMenuAT] = lMenuAC;
                lMenuB = new QPushButton;
                lMenuB->setText(lMenuAT);
                connect(lMenuB, SIGNAL(clicked()), this, SLOT(slotAdressClick()));
                lAddrL->addWidget(lMenuB);
            }
            
            continue;
        }
        
        lMenuB = new QPushButton;
        lMenuB->setText(lMenuT);
        connect(lMenuB, SIGNAL(clicked()), this, SLOT(slotMenuClick()));
        lBodyL->addWidget(lMenuB);
    }

    lMainL->addLayout(lAddrL, 0);
    lMainL->addLayout(lBodyL, 1);
    setLayout(lMainL);
}
//===============================================
GSQLiteQt::~GSQLiteQt() {

}
//===============================================
void GSQLiteQt::slotAdressClick() {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    QPushButton* lMenuB = qobject_cast<QPushButton*>(sender());
    QString lMenuT = lMenuB->text().toUpper();
    QString lPageK = m_addressK[lMenuT];
    if(!lQt->pageId.contains(lPageK)) return;
    int lPageId = lQt->pageId[lPageK];
    if(lPageId == lQt->page->currentIndex()) return;
    lQt->page->setCurrentIndex(lPageId);
}
//===============================================
void GSQLiteQt::slotMenuClick() {
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    QPushButton* lMenuB = qobject_cast<QPushButton*>(sender());
    QString lMenuT = lMenuB->text().toUpper();
    QString lPageK = QString("%1.%2").arg(m_name).arg(lMenuT);
    if(!lQt->pageId.contains(lPageK)) return;
    int lPageId = lQt->pageId[lPageK];
    if(lPageId == lQt->page->currentIndex()) return;
    lQt->page->setCurrentIndex(lPageId);
}
//===============================================
