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
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Imprimer...")->setData("print_data");
    lSettingMenu->setCursor(Qt::PointingHandCursor);
        
    GWidget* lWorkspace = GWidget::Create("keyvalue");
    lWorkspace->setObjectName("workspace");
    lWorkspace->setTitle("Ajouter une variable");
    m_widgetId[lWorkspace] = "workspace";
        
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addLayout(lHeaderLayout);
    lMainLayout->addWidget(lWorkspace);
    lMainLayout->setMargin(10);
    lMainLayout->setSpacing(10);

    setLayout(lMainLayout);
    
    connect(lSetting, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lSettingMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotItemClick(QAction*)));
    connect(lWorkspace, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
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

    qDebug() << m_widgetId[lWidget];
    qDebug() << lApp->widget_id;
    lApp->widget_id = m_widgetId[lWidget];
}
//===============================================
void GDataStream::slotItemClick(QAction* action) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    lApp->widget_id = action->data().toString();

    if(lApp->widget_id == "print_data") {

    }
}
//===============================================
