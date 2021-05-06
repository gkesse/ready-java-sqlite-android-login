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
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Ouvrir une image...")->setData("open_image");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Zoomer en avant l'image (+)")->setData("zoom_in_image");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Zoomer en arrière l'image (-)")->setData("zoom_out_image");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Zoomer en normal l'image (0)")->setData("zoom_normal_image");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Aller à l'image suivante (+)")->setData("next_image");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Aller à l'image précédente (-)")->setData("previous_image");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Enresistrer l'image sous...")->setData("save_as_image");
    lSettingMenu->addSeparator();
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Flouter l'image")->setData("blur_image");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Appliquer une transformation affine à l'image")->setData("affine_transform");
    lSettingMenu->setCursor(Qt::PointingHandCursor);

    QGraphicsScene* lScene = new QGraphicsScene;
    m_scene = lScene;
    
    QGraphicsView* lView = new QGraphicsView(lScene);
    m_view = lView;
    lView->setObjectName("workspace");

    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addLayout(lHeaderLayout);
    lMainLayout->addWidget(lView);
    lMainLayout->setMargin(10);
    lMainLayout->setSpacing(10);

    setLayout(lMainLayout);

    m_state = "none";

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
        showImage(lFilename);
        m_state = "open";
    }
    else if(lApp->widget_id == "zoom_in_image") {
        if(m_state == "none") {return;}
        m_view->scale(1.2, 1.2);
    }
    else if(lApp->widget_id == "zoom_out_image") {
        if(m_state == "none") {return;}
        m_view->scale(1/1.2, 1/1.2);
    }
    else if(lApp->widget_id == "zoom_normal_image") {
        if(m_state == "none") {return;}
        m_view->resetMatrix();
    }
    else if(lApp->widget_id == "next_image") {
        if(m_state == "none") {return;}
        QString lFilename = GManager::Instance()->nextFile(
        m_filename, lApp->img_filters, "Cette image est la dernière");
        if(lFilename == "") {return;}
        showImage(lFilename);
    }
    else if(lApp->widget_id == "previous_image") {
        if(m_state == "none") {return;}
        QString lFilename = GManager::Instance()->previousFile(
        m_filename, lApp->img_filters, "Cette image est la première");
        if(lFilename == "") {return;}
        showImage(lFilename);
    }
    else if(lApp->widget_id == "save_as_image") {
        if(m_state == "none") {return;}
        QString lFilename = GManager::Instance()->saveFile("Enregistrer une image", lApp->img_filter);
        if(lFilename == "") {return;}
        m_currentImage->pixmap().save(lFilename);
    }
}
//===============================================
void GOpenCVQt::showImage(QString filename) {
    m_scene->clear();
    m_view->resetMatrix();
    QPixmap lImage(filename);
    m_currentImage = m_scene->addPixmap(lImage);
    m_scene->update();
    m_view->setSceneRect(lImage.rect());
    m_filename = filename;
}
//===============================================
