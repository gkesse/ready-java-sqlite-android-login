//===============================================
#include "GSQLiteTables.h"
#include "GWidget.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GSQLiteTables::GSQLiteTables(QWidget* parent) : GWidget(parent) {
    setObjectName("GSQLiteTables");
    
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
GSQLiteTables::~GSQLiteTables() {
    
}
//===============================================
// method
//===============================================
int GSQLiteTables::loadPage() {
    if(!GManager::Instance()->isLogin()) return 0;
    fillContent();
    return 1;
}
//===============================================
void GSQLiteTables::fillContent() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    m_listBox->clearContent();
    QVector<QString> lTables = GManager::Instance()->getTables();
    
    for(int i = 0; i < lTables.size(); i++) {
        QString lTable = lTables[i];

        int lCount = GManager::Instance()->countTable(lTable);
        
        QPushButton* lTitle = new QPushButton;
        lTitle->setObjectName("title");
        lTitle->setText(lTable.toUpper());
        lTitle->setIcon(GManager::Instance()->loadPicto(fa::database, lApp->picto_color));
        lTitle->setCursor(Qt::PointingHandCursor);
        m_widgetId[lTitle] = QString("show/%1/%2").arg(lTable).arg(i);

        QPushButton* lShow = new QPushButton;
        m_showId[i] = lShow;
        lShow->setObjectName("show");
        lShow->setText(QString("%1").arg(lCount));
        lShow->setToolTip("Afficher");
        lShow->setCursor(Qt::PointingHandCursor);
        m_widgetId[lShow] = QString("show/%1/%2").arg(lTable).arg(i);

        QPushButton* lSchema = new QPushButton;
        lSchema->setObjectName("schema");
        lSchema->setIcon(GManager::Instance()->loadPicto(fa::cog, lApp->picto_color));
        lSchema->setToolTip("Schéma");
        lSchema->setCursor(Qt::PointingHandCursor);
        m_widgetId[lSchema] = QString("schema/%1/%2").arg(lTable).arg(i);
                
        QPushButton* lAdd = new QPushButton;
        lAdd->setObjectName("add");
        lAdd->setIcon(GManager::Instance()->loadPicto(fa::plus, lApp->picto_color));
        lAdd->setToolTip("Ajouter");
        lAdd->setCursor(Qt::PointingHandCursor);
        m_widgetId[lAdd] = QString("add/%1/%2").arg(lTable).arg(i);
        
        QPushButton* lDelete = new QPushButton;
        lDelete->setObjectName("delete");
        lDelete->setIcon(GManager::Instance()->loadPicto(fa::trash, lApp->picto_color));
        lDelete->setToolTip("Supprimer");
        lDelete->setCursor(Qt::PointingHandCursor);
        m_widgetId[lDelete] = QString("delete/%1/%2").arg(lTable).arg(i);
        
        QHBoxLayout* lRowLayout = new QHBoxLayout;
        lRowLayout->addWidget(lTitle, 1);
        lRowLayout->addWidget(lShow);
        lRowLayout->addWidget(lSchema);
        lRowLayout->addWidget(lAdd);
        lRowLayout->addWidget(lDelete);
        lRowLayout->setMargin(0);
        lRowLayout->setSpacing(10);
                
        m_listBox->addItem(lRowLayout);
        
        connect(lTitle, SIGNAL(clicked()), this, SLOT(slotItemClick()));
        connect(lShow, SIGNAL(clicked()), this, SLOT(slotItemClick()));
        connect(lSchema, SIGNAL(clicked()), this, SLOT(slotItemClick()));
        connect(lAdd, SIGNAL(clicked()), this, SLOT(slotItemClick()));
        connect(lDelete, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    }
}
//===============================================
// slot
//===============================================
void GSQLiteTables::slotItemClick() {
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];

    QStringList lMap = lWidgetId.split("/");
    QString lKey = lMap[0];
    QString lTable = lMap[1];

    if(lKey == "show") {
        QString lAddress = QString("home/sqlite/%1")
        .arg(lTable.toLower());
        GManager::Instance()->setPage(lAddress);
    }
    else if(lKey == "schema") {
        QString lAddress = QString("home/sqlite/%1/schema")
        .arg(lTable.toLower());
        GManager::Instance()->setPage(lAddress);
    }
    else if(lKey == "add") {
        QString lAddress = QString("home/sqlite/%1/add")
        .arg(lTable.toLower());
        GManager::Instance()->setPage(lAddress);
    }
    else if(lKey == "delete") {
        QString lMessage = QString("Voulez-vous supprimer la table\n%1 ?").
        arg(lTable.toUpper());
        int lOk = GManager::Instance()->showQuestion(lMessage);
        if(lOk == QMessageBox::Ok) {
            GManager::Instance()->deleteTable(lTable);
            fillContent();
        }
    }
}
//===============================================
