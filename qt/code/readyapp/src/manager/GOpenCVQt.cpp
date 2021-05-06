//===============================================
#include "GOpenCVQt.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GOpenCVQt::GOpenCVQt(QWidget* parent) : GWidget(parent) {
    setObjectName("none");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lSetting = new QPushButton;
    m_setting = lSetting;
    lSetting->setObjectName("button2");
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
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Ouvrir une image")->setData("open_image");
    lSettingMenu->setCursor(Qt::PointingHandCursor);

    QGraphicsScene* lScene = new QGraphicsScene;
    m_scene = lScene;
    
    QGraphicsView* lView = new QGraphicsView(lScene);
    m_view = lView;
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addLayout(lHeaderLayout);
    lMainLayout->addWidget(lView);
    lMainLayout->setMargin(10);
    lMainLayout->setSpacing(10);

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
        QString lFilename = GManager::Instance()->openFile("Ouvrir une image", lApp->img_filter);
        if(lFilename == "") {return;}
        m_scene->clear();
        m_view->resetMatrix();
        QPixmap lImage(lFilename);
        m_scene->addPixmap(lImage);
        m_scene->update();
        m_view->setSceneRect(lImage.rect());
    }
}
//===============================================
