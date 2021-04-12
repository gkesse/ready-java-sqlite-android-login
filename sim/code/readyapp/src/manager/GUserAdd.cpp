//===============================================
#include "GUserAdd.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GUserAdd::GUserAdd(QWidget* parent) : GWidget(parent) {
    setObjectName("GUserAdd");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lProfil = new QPushButton;
    lProfil->setObjectName("profil");
    lProfil->setIcon(GManager::Instance()->loadPicto(fa::user, lApp->picto_color));
    lProfil->setIconSize(QSize(lApp->profil_size, lApp->profil_size));
    lProfil->setToolTip("Profil");
    lProfil->setCursor(Qt::PointingHandCursor);
    m_widgetId[lProfil] = "profil";
    
    QLabel* lMessage = new QLabel;
    m_message = lMessage;
    lMessage->setObjectName("message");
    lMessage->setAlignment(Qt::AlignCenter);
    m_widgetId[lMessage] = "message";
    
    GWidget* lUsername = GWidget::Create("lineedit");
    m_username = lUsername;
    lUsername->setObjectName("username");
    lUsername->setContent("icon", fa::user, lApp->picto_color);
    lUsername->setToolTip("Nom d'utilisateur");
    m_widgetId[lUsername] = "username";
    
    GWidget* lPassword = GWidget::Create("lineedit");
    m_password = lPassword;
    lPassword->setObjectName("password");
    lPassword->setContent("icon", fa::key, lApp->picto_color);
    lPassword->setOption("echomode", QLineEdit::Password);
    lPassword->setToolTip("Mot de passe");
    m_widgetId[lPassword] = "password";
        
    GWidget* lConfirm = GWidget::Create("lineedit");
    m_confirm = lConfirm;
    lConfirm->setObjectName("confirm");
    lConfirm->setContent("icon", fa::key, lApp->picto_color);
    lConfirm->setOption("echomode", QLineEdit::Password);
    lConfirm->setToolTip("Confirmer le mot de passe");
    m_widgetId[lConfirm] = "confirm";
        
    QPushButton* lCancel = new QPushButton;
    lCancel->setObjectName("cancel");
    lCancel->setText("Annuler");
    lCancel->setCursor(Qt::PointingHandCursor);
    m_widgetId[lCancel] = "cancel";
        
    QPushButton* lAdd = new QPushButton;
    lAdd->setObjectName("add");
    lAdd->setText("Ajouter");
    lAdd->setCursor(Qt::PointingHandCursor);
    m_widgetId[lAdd] = "add";
        
    QHBoxLayout* lButtonLayout = new QHBoxLayout;
    lButtonLayout->addWidget(lAdd);
    lButtonLayout->addWidget(lCancel);
    lButtonLayout->setAlignment(Qt::AlignRight);
    lButtonLayout->setMargin(0);
    lButtonLayout->setSpacing(10);

    QHBoxLayout* lProfilLayout = new QHBoxLayout;
    lProfilLayout->addWidget(lProfil);
    lProfilLayout->setAlignment(Qt::AlignCenter);
    lProfilLayout->setMargin(0);
    lProfilLayout->setSpacing(0);

    QVBoxLayout* lContentLayout = new QVBoxLayout;
    lContentLayout->addLayout(lProfilLayout);
    lContentLayout->addWidget(lMessage);
    lContentLayout->addWidget(lUsername);
    lContentLayout->addWidget(lPassword);
    lContentLayout->addWidget(lConfirm);
    lContentLayout->addLayout(lButtonLayout);
    lContentLayout->setAlignment(Qt::AlignCenter);
    lContentLayout->setMargin(0);
    lContentLayout->setSpacing(10);

    QFrame* lContent = new QFrame;
    lContent->setObjectName("content");
    lContent->setLayout(lContentLayout);
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lContent);
    lMainLayout->setAlignment(Qt::AlignCenter);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);

    setLayout(lMainLayout);
    
    connect(lProfil, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lUsername, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
    connect(lPassword, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
    connect(lConfirm, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
    connect(lAdd, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lCancel, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GUserAdd::~GUserAdd() {

}
//===============================================
// method
//===============================================
void GUserAdd::resetContent() {
    m_message->setText("");
    m_username->setContent("goto", false);
    m_password->setContent("goto", false);
    m_confirm->setContent("goto", false);
}
//===============================================
// slot
//===============================================
void GUserAdd::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    
    if(lWidgetId == "cancel") {
        GManager::Instance()->setPage("home/sqlite");
        return;
    }
    
    if(lWidgetId == "profil") {
        return;
    }
    
    if(lWidgetId == "username") {if(lApp->widget_id == "icon") {return;}}
    if(lWidgetId == "password") {if(lApp->widget_id == "icon") {return;}}
    if(lWidgetId == "confirm") {if(lApp->widget_id == "icon") {return;}}
    if(lWidgetId == "username") {if(lApp->widget_id == "goto") {m_username->setContent("edit", "");}}
    if(lWidgetId == "password") {if(lApp->widget_id == "goto") {return;}}
    if(lWidgetId == "confirm") {if(lApp->widget_id == "goto") {m_confirm->setContent("edit", "");}}

    resetContent();
    
    QString lUsername; m_username->getData("edit", lUsername);
    QString lPassword; m_password->getData("edit", lPassword);
    QString lConfirm; m_confirm->getData("edit", lConfirm);
    
    if(lUsername == "") {
        m_message->setText("Le nom d'utilisateur est obligatoire");
        m_username->setContent("goto", fa::times, "red");
        return;
    }
    if(lPassword == "") {
        m_message->setText("Le mot de passe est obligatoire");
        m_password->setContent("goto", fa::times, "red");
        return;
    }
    if(lConfirm == "") {
        m_message->setText("La confirmation du mot de passe est obligatoire");
        m_confirm->setContent("goto", fa::times, "red");
        return;
    }

    int lCount = GManager::Instance()->countUser(lUsername);
    if(lCount > 0) {
        m_message->setText("Cet utilisateur existe déjà");
        m_username->setContent("goto", fa::times, "red");
        return;
    }

    if(lPassword != lConfirm) {
        m_message->setText("Les mots de passe sont incorrects");
        m_confirm->setContent("goto", fa::times, "red");
        return;
    }
        
    GManager::Instance()->addUser(lUsername, lPassword);
    m_message->setText("L'utilisateur a été ajouté avec succès");
    
    GManager::Instance()->setPage("home/sqlite");
}
//===============================================
