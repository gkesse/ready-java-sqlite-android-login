//===============================================
#include "GHome.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GHome::GHome(QWidget* parent) : GWidget(parent) {
    setObjectName("GHome");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    GWidget* lListBox = GWidget::Create("listbox");
    
    lListBox->addItem("home/login", "Connexion", fa::book); lApp->login_home = qobject_cast<QPushButton*>(lApp->widget);
    lListBox->addItem("home/profil", "Profil", fa::book);
    lListBox->addItem("home/sqlite", "SQLite", fa::book);
    lListBox->addItem("home/pdf", "Pdf", fa::book);
    lListBox->addItem("home/builder", "Builder", fa::book);
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lListBox);
    lMainLayout->setAlignment(Qt::AlignTop);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);
    
    connect(lListBox, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
}
//===============================================
GHome::~GHome() {
    
}
//===============================================
// method
//===============================================
int GHome::loadPage() {
    return 1;
}
//===============================================
// slot
//===============================================
void GHome::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->widget_id == "home/login") {
        if(lApp->login_on == "on") {
            QString lMessage = QString("Voulez-vous vous déconnecter ?");
            int lOk = GManager::Instance()->showQuestion(lMessage);
            if(lOk == QMessageBox::Ok) {
                lApp->login_on = "off";
                lApp->login_titlebar->setText("Se Connecter");
                lApp->login_home->setText("Connexion");
            }
        }
    }
    GManager::Instance()->setPage(lApp->widget_id);
}
//===============================================
