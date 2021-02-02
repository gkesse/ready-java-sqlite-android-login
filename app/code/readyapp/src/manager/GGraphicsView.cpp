//===============================================
#include "GGraphicsView.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GGraphicsView::GGraphicsView(QWidget* parent) : GWidget(parent) {
    setObjectName("GGraphicsView");
    
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
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Ouvrir une image")->setData("open_image");
    lSettingMenu->setCursor(Qt::PointingHandCursor);
    
    QGraphicsScene* lScene = new QGraphicsScene(this);
    m_scene = lScene;
    
    QGraphicsView* lWorkspace = new QGraphicsView(lScene);
    m_workspace = lWorkspace;
    lWorkspace->setBackgroundBrush(QBrush(Qt::red, Qt::SolidPattern));
    
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
GGraphicsView::~GGraphicsView() {

}
//===============================================
// slot
//===============================================
void GGraphicsView::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    if(lApp->widget_id == "setting") {
        QPoint lPos = QCursor::pos();
        m_settingMenu->exec(lPos);
    }
}
//===============================================
void GGraphicsView::slotItemClick(QAction* action) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    lApp->widget_id = action->data().toString();

    if(lApp->widget_id == "open_image") {
        QString lFilename = GManager::Instance()->openFile("Ouvrir une image", lApp->img_filter);
        m_scene->clear();
        m_workspace->resetMatrix();
        QPixmap lImage(lFilename);
        m_scene->addPixmap(lImage);
        m_scene->update();
        m_workspace->setSceneRect(lImage.rect());
    }
}
//===============================================
