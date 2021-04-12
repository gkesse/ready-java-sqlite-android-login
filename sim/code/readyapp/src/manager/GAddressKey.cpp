//===============================================
#include "GAddressKey.h"
#include "GManager.h"
//===============================================
GAddressKey::GAddressKey(QWidget* parent) : GWidget(parent) {
    setObjectName("GAddressKey");
        
    QHBoxLayout* lMainLayout = new QHBoxLayout;
    m_mainLayout = lMainLayout;
    lMainLayout->setAlignment(Qt::AlignLeft);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);

    setLayout(lMainLayout);
}
//===============================================
GAddressKey::~GAddressKey() {
    
}
//===============================================
// method
//===============================================
void GAddressKey::setContent(QString text) {
    sGApp* lApp = GManager::Instance()->getData()->app;

    QStringList lMap = text.split("/");
    QString lKey = "";
    
    GManager::Instance()->clearLayout(m_mainLayout);

    for(int i = 0; i < lMap.size(); i++) {
        if(i != 0) {
            QPushButton* lSep = new QPushButton;
            lSep->setObjectName("sep");
            lSep->setIcon(GManager::Instance()->loadPicto(fa::chevronright, lApp->picto_color));
            m_mainLayout->addWidget(lSep);
        }
        
        if(i != 0) {lKey += "/";}
        lKey += lMap[i];
        
        QPushButton* lButton = new QPushButton;
        lButton->setObjectName("item");
        lButton->setText(lMap[i]);
        lButton->setCursor(Qt::PointingHandCursor);
        m_widgetId[lButton] = lKey;
        m_mainLayout->addWidget(lButton);
        connect(lButton, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    }
}
//===============================================
// slot
//===============================================
void GAddressKey::slotItemClick() {
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    GManager::Instance()->setPage(lWidgetId);
}
//===============================================
