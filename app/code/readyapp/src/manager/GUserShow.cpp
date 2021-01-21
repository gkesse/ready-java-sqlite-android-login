//===============================================
#include "GUserShow.h"
#include "GWidget.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GUserShow::GUserShow(QWidget* parent) : GWidget(parent) {
    setObjectName("GUserShow");
    
    sGApp* lApp = GManager::Instance()->getData()->app;

    GWidget* lListBox = GWidget::Create("listbox");
    m_listBox = lListBox;
    m_widgetId[lListBox] = "listbox";
        
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
        lDelete->setCursor(Qt::PointingHandCursor);
        m_widgetId[lDelete] = QString("delete/%1/%2").arg(lDataRow[0]).arg(i);

        QHBoxLayout* lRowLayout = new QHBoxLayout;
        lRowLayout->addWidget(lTitle, 1);
        lRowLayout->addWidget(lDelete);
        lRowLayout->setMargin(0);
        lRowLayout->setSpacing(0);

        lListBox->addItem(lRowLayout);
        
        connect(lTitle, SIGNAL(clicked()), this, SLOT(slotItemClick()));
        connect(lDelete, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    }

    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lListBox);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GUserShow::~GUserShow() {
    
}
//===============================================
// method
//===============================================
int GUserShow::loadPage() {
    return 1;
}
//===============================================
// slot
//===============================================
void GUserShow::slotItemClick() {
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];

    QStringList lMap = lWidgetId.split("/");
    QString lKey = lMap[0];
    QString lUsername = lMap[1];
    int lIndex = lMap[2].toInt();

    if(lKey == "delete") {
        QString lMessage;
        if(lUsername == "root") {
            lMessage = QString("L'utilisateur root ne peut pas être supprimé !");
            GManager::Instance()->showInfo(lMessage);
            return;
        }
        lMessage = QString("Voulez-vous supprimer l'utilisateur\n%1 ?").
        arg(lUsername);
        int lOk = GManager::Instance()->showQuestion(lMessage);
        if(lOk == QMessageBox::Ok) {
            GManager::Instance()->deleteUser(lUsername);
            m_listBox->removeItem(lIndex);
        }
    }
}
//===============================================
