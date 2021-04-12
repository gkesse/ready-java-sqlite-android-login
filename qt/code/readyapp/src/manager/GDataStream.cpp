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
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Ajouter une variable")->setData("add_data");
    lSettingMenu->setCursor(Qt::PointingHandCursor);
        
    GWidget* lKeyValue = GWidget::Create("keyvalue");
    lKeyValue->setObjectName("workspace");
    lKeyValue->setTitle("Ajouter une variable");
    m_widgetId[lKeyValue] = "keyvalue";

    GWidget* lWorkspace = GWidget::Create("stackwidget");
    m_workspace = lWorkspace;
    lWorkspace->addPage("home", "", GWidget::Create("widget"));
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
    
    lApp->widget_id = lWidgetId;
}
//===============================================
