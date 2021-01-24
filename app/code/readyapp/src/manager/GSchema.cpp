//===============================================
#include "GSchema.h"
#include "GWidget.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GSchema::GSchema(QWidget* parent) : GWidget(parent) {
    setObjectName("GSchema");

    QTextEdit* lTextEdit = new QTextEdit;
    m_textEdit = lTextEdit;
    lTextEdit->setObjectName("text");
    lTextEdit->setReadOnly(true);
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lTextEdit);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);
}
//===============================================
GSchema::~GSchema() {
    
}
//===============================================
// method
//===============================================
int GSchema::loadPage() {
    if(!GManager::Instance()->isLogin()) return 0;

    sGApp* lApp = GManager::Instance()->getData()->app;

    QStringList lMap = lApp->address_new.split("/");
    QString lTable = lMap[2];
    
    QString lQuery = QString("\
    select sql from sqlite_master \
    where name='%1';\
    ").arg(lTable);
    
    QString lSchema = GSQLite::Instance()->queryValue(lQuery);
    
    m_textEdit->setText(lSchema);
    return 1;
}
//===============================================
