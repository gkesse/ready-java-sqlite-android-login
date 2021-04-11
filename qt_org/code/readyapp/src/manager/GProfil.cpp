//===============================================
#include "GProfil.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GProfil::GProfil(QWidget* parent) : GWidget(parent) {
    setObjectName("GProfil");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lProfilLabel = new QPushButton;
    lProfilLabel->setObjectName("profil_label");
    lProfilLabel->setIcon(GManager::Instance()->loadPicto(fa::user, lApp->picto_color));
    lProfilLabel->setText("Profil");
    m_widgetId[lProfilLabel] = "profil_label";
    
    QPushButton* lProfilPhoto = new QPushButton;
    lProfilPhoto->setObjectName("profil_photo");
    lProfilPhoto->setIcon(GManager::Instance()->loadPicto(fa::user, lApp->picto_color));
    lProfilPhoto->setIconSize(QSize(lApp->profil_size, lApp->profil_size));
    m_widgetId[lProfilPhoto] = "profil_photo";
    
    GWidget* lUsername = GWidget::Create("lineedit");
    lUsername->setObjectName("username");
    lUsername->setContent("label", "Nom d'utilisateur");
    lUsername->setContent("label", fa::user, lApp->picto_color);
    lUsername->setOption("readonly", true);
    lUsername->setProperty("mode", "label");
    m_widgetId[lUsername] = "username";

    GWidget* lEmail = GWidget::Create("lineedit");
    lEmail->setObjectName("email");
    lEmail->setContent("label", "Email");
    lEmail->setContent("label", fa::envelopeo, lApp->picto_color);
    lEmail->setOption("readonly", true);
    lEmail->setProperty("mode", "label");
    m_widgetId[lEmail] = "email";

    GWidget* lLocation = GWidget::Create("lineedit");
    lLocation->setObjectName("location");
    lLocation->setContent("label", "Location");
    lLocation->setContent("label", fa::mapmarker, lApp->picto_color);
    lLocation->setOption("readonly", true);
    lLocation->setProperty("mode", "label");
    m_widgetId[lLocation] = "location";

    GWidget* lPhone = GWidget::Create("lineedit");
    lPhone->setObjectName("phone");
    lPhone->setContent("label", "Téléphone");
    lPhone->setContent("label", fa::mobile, lApp->picto_color);
    lPhone->setOption("readonly", true);
    lPhone->setProperty("mode", "label");
    m_widgetId[lPhone] = "phone";

    GWidget* lSiteweb = GWidget::Create("lineedit");
    lSiteweb->setObjectName("siteweb");
    lSiteweb->setContent("label", "Siteweb");
    lSiteweb->setContent("label", fa::globe, lApp->picto_color);
    lSiteweb->setOption("readonly", true);
    lSiteweb->setProperty("mode", "label");
    m_widgetId[lSiteweb] = "siteweb";

    QVBoxLayout* lInfoLayout = new QVBoxLayout;
    lInfoLayout->addWidget(lUsername);
    lInfoLayout->addWidget(lEmail);
    lInfoLayout->addWidget(lLocation);
    lInfoLayout->addWidget(lPhone);
    lInfoLayout->addWidget(lSiteweb);
    lInfoLayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    lInfoLayout->setContentsMargins(0, 20, 0, 0);
    lInfoLayout->setSpacing(10);
    
    QHBoxLayout* lProfilLayout = new QHBoxLayout;
    lProfilLayout->addWidget(lProfilPhoto);
    lProfilLayout->addLayout(lInfoLayout);
    lProfilLayout->setAlignment(Qt::AlignLeft);
    lProfilLayout->setMargin(0);
    lProfilLayout->setSpacing(20);
    
    QVBoxLayout* lContentLayout = new QVBoxLayout;
    lContentLayout->addWidget(lProfilLabel);
    lContentLayout->addLayout(lProfilLayout);
    lContentLayout->setAlignment(Qt::AlignTop);
    lContentLayout->setMargin(0);
    lContentLayout->setSpacing(10);

    QFrame* lContent = new QFrame;
    lContent->setObjectName("content");
    lContent->setLayout(lContentLayout);
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lContent);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);

    setLayout(lMainLayout);
    
    connect(lUsername, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
}
//===============================================
GProfil::~GProfil() {

}
//===============================================
// method
//===============================================
int GProfil::loadPage() {
    if(!GManager::Instance()->isLogin()) return 0;
    return 1;
}
//===============================================
// slot
//===============================================
void GProfil::slotItemClick() {
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
}
//===============================================
