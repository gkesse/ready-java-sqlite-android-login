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
    
    lListBox->addItem("home/login", "Connexion", fa::signin); lApp->login_home = qobject_cast<QPushButton*>(lApp->widget);
    lListBox->addItem("home/profil", "Profil", fa::user);
    lListBox->addItem("home/sqlite", "SQLite", fa::database);
    lListBox->addItem("home/pdf", "Pdf", fa::filepdfo);
    lListBox->addItem("home/timesheet", "Timesheet", fa::calendar);
    lListBox->addItem("home/opencv", "OpenCV", fa::camera);
    lListBox->addItem("home/debug", "Debug", fa::file-text-o);
    
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
