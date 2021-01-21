//===============================================
#include "GUserMap.h"
#include "GWidget.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GUserMap::GUserMap(QWidget* parent) : GWidget(parent) {
    setObjectName("GUserMap");
    
    GWidget* lListBox = GWidget::Create("listbox");
    m_listBox = lListBox;
    m_widgetId[lListBox] = "listbox";
    
    fillContent();
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lListBox);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GUserMap::~GUserMap() {
    
}
//===============================================
// method
//===============================================
int GUserMap::loadPage() {
    if(!GManager::Instance()->isLogin()) return 0;
    fillContent();
    return 1;
}
//===============================================
void GUserMap::fillContent() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    m_listBox->clearContent();
    QVector<QVector<QString>> lDataMap = GManager::Instance()->getUser();
        
    for(int i = 0; i < lDataMap.size(); i++) {
        QVector<QString> lDataRow = lDataMap[i];
        
        QString lData = QString("%1 - %2 - %3").arg(lDataRow[0])
        .arg(lDataRow[2]).arg(lDataRow[3]);
        
        QPushButton* lTitle = new QPushButton;
        lTitle->setObjectName("title");
        lTitle->setText(lData);
        lTitle->setIcon(GManager::Instance()->loadPicto(fa::user, lApp->picto_color));
        lTitle->setCursor(Qt::PointingHandCursor);
        m_widgetId[lTitle] = QString("show/%1/%2").arg(lDataRow[0]).arg(i);

        QPushButton* lDelete = new QPushButton;
        lDelete->setObjectName("delete");
        lDelete->setIcon(GManager::Instance()->loadPicto(fa::trash, lApp->picto_color));
        lDelete->setToolTip("Supprimer");
        lDelete->setCursor(Qt::PointingHandCursor);
        m_widgetId[lDelete] = QString("delete/%1/%2").arg(lDataRow[0]).arg(i);

        QHBoxLayout* lRowLayout = new QHBoxLayout;
        lRowLayout->addWidget(lTitle, 1);
        lRowLayout->addWidget(lDelete);
        lRowLayout->setMargin(0);
        lRowLayout->setSpacing(0);

        m_listBox->addItem(lRowLayout);
        
        connect(lTitle, SIGNAL(clicked()), this, SLOT(slotItemClick()));
        connect(lDelete, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    }
}
//===============================================
// slot
//===============================================
void GUserMap::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];

    QStringList lMap = lWidgetId.split("/");
    QString lKey = lMap[0];
    QString lUsername = lMap[1];

    if(lKey == "delete") {
        QString lMessage;
        if(lUsername == lApp->root_user) {
            lMessage = QString("L'utilisateur root ne peut pas être supprimé !");
            GManager::Instance()->showInfo(lMessage);
            return;
        }
        lMessage = QString("Voulez-vous supprimer l'utilisateur\n%1 ?").
        arg(lUsername);
        int lOk = GManager::Instance()->showQuestion(lMessage);
        if(lOk == QMessageBox::Ok) {
            GManager::Instance()->deleteUser(lUsername);
            fillContent();
        }
    }
}
//===============================================
