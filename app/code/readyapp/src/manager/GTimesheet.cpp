//===============================================
#include "GTimesheet.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GTimesheet::GTimesheet(QWidget* parent) : GWidget(parent) {
    setObjectName("GTimesheet");
    sGApp* lApp = GManager::Instance()->getData()->app;

    QPushButton* lSetting = new QPushButton;
    m_setting = lSetting;
    lSetting->setObjectName("item");
    lSetting->setIcon(GManager::Instance()->loadPicto(fa::cog, lApp->picto_color));
    lSetting->setText("Paramètres");
    lSetting->setCursor(Qt::PointingHandCursor);
    m_widgetId[lSetting] = "setting";
    
    QHBoxLayout* lHeaderLayout = new QHBoxLayout;
    lHeaderLayout->addWidget(lSetting);
    lHeaderLayout->setAlignment(Qt::AlignRight);
    lHeaderLayout->setMargin(0);
    lHeaderLayout->setSpacing(0);

    QMenu* lSettingMenu = new QMenu(this);
    m_settingMenu = lSettingMenu;
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Date Courante");
    
    QTextEdit* lDebug = new QTextEdit;
    m_debug = lDebug;
    lDebug->setObjectName("debug");
    lDebug->append("GTimesheet");
    lDebug->setReadOnly(true);
    m_widgetId[lDebug] = "debug";
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addLayout(lHeaderLayout);
    lMainLatout->addWidget(lDebug);
    lMainLatout->setMargin(10);
    lMainLatout->setSpacing(10);
    
    setLayout(lMainLatout);
    
    loadPage();
    
    connect(lSetting, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lSettingMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotItemClick(QAction*)));
}
//===============================================
GTimesheet::~GTimesheet() {
    
}
//===============================================
// method
//===============================================
int GTimesheet::loadPage() {
    
    return 1;
}
//===============================================
// slot
//===============================================
void GTimesheet::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    if(lApp->widget_id == "setting") {
        QPoint lPos = QCursor::pos();
        m_settingMenu->exec(lPos);
    }
}
//===============================================
void GTimesheet::slotItemClick(QAction* action) {
    
}
//===============================================
