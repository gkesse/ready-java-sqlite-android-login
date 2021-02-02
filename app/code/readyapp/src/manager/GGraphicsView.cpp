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
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Enregistrer une image")->setData("save_image");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Zoomer en avant (+)")->setData("zoom_in");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Zoomer en arrière (-)")->setData("zoom_out");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Image suivante (+)")->setData("next_image");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Image précédente (-)")->setData("previous_image");
    lSettingMenu->setCursor(Qt::PointingHandCursor);
    
    QGraphicsScene* lScene = new QGraphicsScene(this);
    m_scene = lScene;
    
    QGraphicsView* lWorkspace = new QGraphicsView(lScene);
    m_workspace = lWorkspace;
    lWorkspace->setObjectName("workspace");
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addLayout(lHeaderLayout);
    lMainLayout->addWidget(lWorkspace);
    lMainLayout->setMargin(10);
    lMainLayout->setSpacing(10);

    setLayout(lMainLayout);

    m_state = "none";
    
    connect(lSetting, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lSettingMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotItemClick(QAction*)));
}
//===============================================
GGraphicsView::~GGraphicsView() {

}
//===============================================
// method
//===============================================
void GGraphicsView::showImage(QString filename) {
    if(filename == "") return;
    m_scene->clear();
    m_workspace->resetMatrix();
    QPixmap lImage(filename);
    m_pixmap = m_scene->addPixmap(lImage);
    m_scene->update();
    m_workspace->setSceneRect(lImage.rect());
    m_filename = filename;
    m_state = "open";
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
        showImage(lFilename);
    }
    else if(lApp->widget_id == "save_image") {
        if(m_state == "none") {return;}
        QString lFilename = GManager::Instance()->saveFile("Enregistrer une image", lApp->img_filter);
        m_pixmap->pixmap().save(lFilename);
    }
    else if(lApp->widget_id == "zoom_in") {
        if(m_state == "none") {return;}
        m_workspace->scale(1.2, 1.2);
    }
    else if(lApp->widget_id == "zoom_out") {
        if(m_state == "none") {return;}
        m_workspace->scale(1/1.2, 1/1.2);
    }
    else if(lApp->widget_id == "next_image") {
        if(m_state == "none") {return;}
        QString lFilename = GManager::Instance()->nextFile(
        m_filename, lApp->img_filters, "Cette image est la dernière");
        showImage(lFilename);
    }
    else if(lApp->widget_id == "previous_image") {
        if(m_state == "none") {return;}
        QString lFilename = GManager::Instance()->previousFile(
        m_filename, lApp->img_filters, "Cette image est la première");
        showImage(lFilename);
    }
}
//===============================================
