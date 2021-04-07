//===============================================
#include "GQtPg.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GQtPg::GQtPg(QWidget* parent) : GWidget(parent) {
    setObjectName("GQtPg");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    GWidget* lListBox = GWidget::Create("listbox");
    
    lListBox->addItem("home/qt/qgraphicsview", "QGraphicsView", fa::book); lApp->login_home = qobject_cast<QPushButton*>(lApp->widget);
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lListBox);
    lMainLayout->setAlignment(Qt::AlignTop);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);
    
    connect(lListBox, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
}
//===============================================
GQtPg::~GQtPg() {
    
}
//===============================================
// slot
//===============================================
void GQtPg::slotItemClick() {
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
