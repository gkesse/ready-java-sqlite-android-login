//===============================================
#include "GOpenCVQt.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GOpenCVQt::GOpenCVQt(QWidget* parent) : GWidget(parent) {
    setObjectName("GOpenCVQt");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lSetting = new QPushButton;
    m_setting = lSetting;
    lSetting->setObjectName("item");
    lSetting->setIcon(GManager::Instance()->loadPicto(fa::cog, lApp->picto_color));
    lSetting->setText("Paramètres");
    lSetting->setCursor(Qt::PointingHandCursor);
    m_widgetId[lSetting] = "setting";
        
    QMenu* lSettingMenu = new QMenu(this);
    m_settingMenu = lSettingMenu;
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Ouvrir une image")->setData("open_image");
    lSettingMenu->setCursor(Qt::PointingHandCursor);

    QHBoxLayout* lHeaderLayout = new QHBoxLayout;
    lHeaderLayout->addWidget(lSetting);
    lHeaderLayout->setAlignment(Qt::AlignRight);
    lHeaderLayout->setMargin(0);
    lHeaderLayout->setSpacing(0);

    QLabel* lWorkspace = new QLabel;
    lWorkspace->setObjectName("workspace");
    lWorkspace->setText("GOpenCVQt");
    lWorkspace->setAlignment(Qt::AlignCenter);
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addLayout(lHeaderLayout);
    lMainLayout->addWidget(lWorkspace);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);

    setLayout(lMainLayout);

    connect(lSetting, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lSettingMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotItemClick(QAction*)));
}
//===============================================
GOpenCVQt::~GOpenCVQt() {

}
//===============================================
// slot
//===============================================
void GOpenCVQt::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    if(lApp->widget_id == "setting") {
        QPoint lPos = QCursor::pos();
        m_settingMenu->exec(lPos);
    }
}
//===============================================
void GOpenCVQt::slotItemClick(QAction* action) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    lApp->widget_id = action->data().toString();
    if(lApp->widget_id == "open_image") {
        
    }
}
//===============================================
