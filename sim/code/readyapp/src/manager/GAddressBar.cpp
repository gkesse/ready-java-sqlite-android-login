//===============================================
#include "GAddressBar.h"
#include "GManager.h"
//===============================================
GAddressBar::GAddressBar(QWidget* parent) : GWidget(parent) {
    setObjectName("GAddressBar");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lHome = new QPushButton;
    lHome->setObjectName("home");
    lHome->setIcon(GManager::Instance()->loadPicto(fa::home, lApp->picto_color));
    lHome->setCursor(Qt::PointingHandCursor);
    m_widgetId[lHome] = "home";
    
    QLineEdit* lAddress = new QLineEdit;
    lApp->address = lAddress;
    lAddress->setObjectName("address");
    m_widgetId[lAddress] = "address";
    
    QPushButton* lGoTo = new QPushButton;
    lGoTo->setObjectName("goto");
    lGoTo->setIcon(GManager::Instance()->loadPicto(fa::paperplaneo, lApp->picto_color));
    lGoTo->setCursor(Qt::PointingHandCursor);
    m_widgetId[lGoTo] = "goto";
    
    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->addWidget(lHome);
    lMainLayout->addWidget(lAddress, 1);
    lMainLayout->addWidget(lGoTo);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(5);

    setLayout(lMainLayout);

    connect(lHome, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lAddress, SIGNAL(returnPressed()), this, SLOT(slotItemClick()));
    connect(lGoTo, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GAddressBar::~GAddressBar() {
    
}
//===============================================
// slot
//===============================================
void GAddressBar::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    if(lWidgetId == "home") {
        GManager::Instance()->setPage("home");
    }
    else if(lWidgetId == "address") {
        GManager::Instance()->setPage(lApp->address->text());
    }
    else if(lWidgetId == "goto") {
        GManager::Instance()->setPage(lApp->address->text());
    }
}
//===============================================
