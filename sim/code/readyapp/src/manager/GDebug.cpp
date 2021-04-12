//===============================================
#include "GDebug.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GDebug::GDebug(QWidget* parent) : GWidget(parent) {
    setObjectName("GDebug");
    
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
    lHeaderLayout->setAlignment(Qt::AlignRight);
    lHeaderLayout->setMargin(0);
    lHeaderLayout->setSpacing(10);

    QMenu* lSettingMenu = new QMenu(this);
    m_settingMenu = lSettingMenu;
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::trasho, lApp->picto_color), "Nettoyer le débogueur")->setData("clear");
    lSettingMenu->setCursor(Qt::PointingHandCursor);

    QTextEdit* lWorkspace = new QTextEdit;
    lApp->debug = lWorkspace;
    lWorkspace->setObjectName("workspace");
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addLayout(lHeaderLayout);
    lMainLayout->addWidget(lWorkspace);
    lMainLayout->setMargin(10);
    lMainLayout->setSpacing(10);

    setLayout(lMainLayout);

    connect(lSetting, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lSettingMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotItemClick(QAction*)));
}
//===============================================
GDebug::~GDebug() {

}
//===============================================
// slot
//===============================================
void GDebug::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    if(lApp->widget_id == "setting") {
        QPoint lPos = QCursor::pos();
        m_settingMenu->exec(lPos);
    }
}
//===============================================
void GDebug::slotItemClick(QAction* action) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    lApp->widget_id = action->data().toString();

    if(lApp->widget_id == "clear") {
        lApp->debug->clear();
    }
}
//===============================================
