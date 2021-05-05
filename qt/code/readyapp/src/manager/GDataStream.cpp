//===============================================
#include "GDataStream.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GDataStream::GDataStream(QWidget* parent) : GWidget(parent) {
    setObjectName("GDataStream");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lSetting = new QPushButton;
    m_setting = lSetting;
    lSetting->setObjectName("GButton");
    lSetting->setIcon(GManager::Instance()->loadPicto(fa::cog, lApp->picto_color));
    lSetting->setText("Paramètres");
    lSetting->setCursor(Qt::PointingHandCursor);
    m_widgetId[lSetting] = "setting";
        
    QHBoxLayout* lHeaderLayout = new QHBoxLayout;
    lHeaderLayout->addWidget(lSetting);
    lHeaderLayout->setAlignment(Qt::AlignLeft);
    lHeaderLayout->setMargin(0);
    lHeaderLayout->setSpacing(10);

    QMenu* lSettingMenu = new QMenu(this);
    m_settingMenu = lSettingMenu;
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::plus, lApp->picto_color), "Ajouter une variable")->setData("add_data");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::save, lApp->picto_color), "Enregistrer les données")->setData("save_data");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::refresh, lApp->picto_color), "Charger les données")->setData("load_data");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::trash, lApp->picto_color), "Nettoyer les données")->setData("clear_data");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::eye, lApp->picto_color), "Afficher les données")->setData("show_data");
    lSettingMenu->setCursor(Qt::PointingHandCursor);
        
    GWidget* lHome = GWidget::Create("textedit");
    m_home = lHome;
    m_widgetId[lHome] = "home";

    GWidget* lKeyValue = GWidget::Create("keyvalue");
    m_keyValue = lKeyValue;
    lKeyValue->setObjectName("workspace");
    lKeyValue->setClear(true);
    lKeyValue->setTitle("Ajouter une ville");
    lKeyValue->setNameLabel("Nom");
    lKeyValue->setValueLabel("Code postal");
    m_widgetId[lKeyValue] = "keyvalue";

    GWidget* lWorkspace = GWidget::Create("stackwidget");
    m_workspace = lWorkspace;
    lWorkspace->addPage("home", "", lHome);
    lWorkspace->addPage("add_data", "", lKeyValue);
        
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addLayout(lHeaderLayout);
    lMainLayout->addWidget(lWorkspace);
    lMainLayout->setMargin(10);
    lMainLayout->setSpacing(10);

    setLayout(lMainLayout);
    
    connect(lSetting, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lSettingMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotItemClick(QAction*)));
    connect(lKeyValue, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
}
//===============================================
GDataStream::~GDataStream() {

}
//===============================================
// method
//===============================================
void GDataStream::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    
    if(lWidgetId == "setting") {
        QPoint lPos = QCursor::pos();
        m_settingMenu->exec(lPos);
    }
    else if(lWidgetId == "keyvalue") {
        if(lApp->widget_id == "close") {
            m_workspace->setPage("home");
        }
        else if(lApp->widget_id == "cancel") {
            m_workspace->setPage("home");
        }
        else if(lApp->widget_id == "add") {
            if(m_keyValue->getName() == "") {return;}
            if(m_keyValue->getValue() == "") {return;}
            m_home->append(GManager::Instance()->format("%-20s : %s",
            m_keyValue->getName().toStdString().c_str(),
            m_keyValue->getValue().toStdString().c_str()));
            m_cityMap[m_keyValue->getName()] = m_keyValue->getValue();
            m_workspace->setPage("home");
        }
    }

    lApp->widget_id = m_widgetId[lWidget];
}
//===============================================
void GDataStream::slotItemClick(QAction* action) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QString lWidgetId = action->data().toString();

    if(lWidgetId == "add_data") {
        m_workspace->setPage("add_data");
    }
    else if(lWidgetId == "save_data") {
        // on ouvre un fichier en ecriture seule
        QFile file("city_map.dat");
        if (!file.open(QIODevice::WriteOnly)) {
            // on affiche un message en cas de probleme
            QMessageBox::information(this, tr("Impossible d'ouvrir le fichier"), file.errorString());
            return;
        }
        // on serialise les donnees
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << m_cityMap;
        m_workspace->setPage("home");
    }
    else if(lWidgetId == "load_data") {
        // on ouvre un fichier en lecture seule
        QFile file("city_map.dat");
        if (!file.open(QIODevice::ReadOnly)) {
            // on affiche un message en cas de probleme
            QMessageBox::information(this, tr("Impossible d'ouvrir le fichier"), file.errorString());
            return;
        }
        // on deserialise les donnees
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        in >> m_cityMap;
        
        m_home->setText("");
        
        QList<QString> lKeys = m_cityMap.keys();
        
        for(int i = 0; i < lKeys.size(); i++) {
            QString lKey = lKeys[i];
            QString lValue = m_cityMap[lKey];
            m_home->append(GManager::Instance()->format("%-20s : %s",
            lKey.toStdString().c_str(),
            lValue.toStdString().c_str()));
        }
        
        m_workspace->setPage("home");
    }
    else if(lWidgetId == "clear_data") {
        m_home->setText("");
    }
    else if(lWidgetId == "show_data") {
        m_home->setText("");
        
        QList<QString> lKeys = m_cityMap.keys();
        
        for(int i = 0; i < lKeys.size(); i++) {
            QString lKey = lKeys[i];
            QString lValue = m_cityMap[lKey];
            m_home->append(GManager::Instance()->format("%-20s : %s",
            lKey.toStdString().c_str(),
            lValue.toStdString().c_str()));
        }
    }
    
    lApp->widget_id = lWidgetId;
}
//===============================================
