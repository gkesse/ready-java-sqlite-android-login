//===============================================
#include "GWindow.h"
#include "GWidget.h"
#include "GStackWidget.h"
#include "GData.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GWindow::GWindow(QWidget* parent) : GWidget(parent) {
    setObjectName("GWindow");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    lApp->win = this;

    GWidget* lTitleBar = GWidget::Create("titlebar");
    m_widgetId[lTitleBar] = "titlebar";
    
    GWidget* lAddressBar = GWidget::Create("addressbar");
    
    GWidget* lAddressKey = GWidget::Create("addresskey");
    lApp->address_key = lAddressKey;
    
    GStackWidget* lWorkspace = new GStackWidget;
    lApp->page_map = lWorkspace;

    QScrollArea* lScrollArea = new QScrollArea;
    lScrollArea->setObjectName("workspace");
    lScrollArea->setWidget(lWorkspace);
    lScrollArea->setWidgetResizable(true);

    // home
    addPage("home", "Accueil", GWidget::Create("home"), 1);
    addPage("home/opencv", "OpenCV", GWidget::Create("opencv"), 1);
    // qt
    addPage("home/qt/qgraphicsview", "QGraphicsView", GWidget::Create("qgraphicsview"), 1);
    // login
    addPage("home/login", "Connexion", GWidget::Create("login"));
    addPage("home/profil", "Profil", GWidget::Create("profil"));
    // sqlite
    addPage("home/sqlite", "Tables", GWidget::Create("sqlitetables"));
    addPage("home/sqlite/users", "Table USERS", GWidget::Create("usermap"));
    addPage("home/sqlite/users/show", "Données d'un utilisateur", GWidget::Create("usershow"));
    addPage("home/sqlite/users/schema", "Schéma de la table USER", GWidget::Create("schema"));
    addPage("home/sqlite/users/add", "Ajouter un utilisateur", GWidget::Create("useradd"));
    addPage("home/sqlite/config_data", "Table CONFIG_DATA", GWidget::Create("config_data"));
    addPage("home/sqlite/config_data/schema", "Afficher le schéma", GWidget::Create("schema"));
    // pdf
    addPage("home/pdf", "Pdf", GWidget::Create("pdfui"));
    // timesheet
    addPage("home/timesheet", "Timesheet", GWidget::Create("timesheet"));
    // debug
    addPage("home/debug", "Debug", GWidget::Create("debug"));
    // error
    addPage("home/error", "Erreur", GWidget::Create("error"));
        
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lTitleBar);
    lMainLayout->addWidget(lAddressBar);
    lMainLayout->addWidget(lAddressKey);
    lMainLayout->addWidget(lScrollArea, 1);
    lMainLayout->setMargin(10);
    lMainLayout->setSpacing(10);
    
    setLayout(lMainLayout);
    
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setWindowTitle(lApp->app_name);
    setWindowIcon(QIcon(lApp->img_map["logo"]));
    resize(lApp->win_width, lApp->win_height);

    m_sizeGrip = new QSizeGrip(this);
}
//===============================================
GWindow::~GWindow() {
    
}
//===============================================
// methods
//===============================================
void GWindow::addPage(QString key, QString title, QWidget* widget, bool isDefault) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    int lWidgetId = lApp->page_map->count();
    lApp->page_id[key] = lWidgetId;
    lApp->title_map[key] = title;
    lApp->page_map->addWidget(widget);
    if(isDefault == 1) {
        GManager::Instance()->setPage(key);
    }
}
//===============================================
// callback
//===============================================
void GWindow::resizeEvent(QResizeEvent *event) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    m_sizeGrip->move(width() - lApp->grip_size, height() - lApp->grip_size);
    m_sizeGrip->resize(lApp->grip_size, lApp->grip_size);
}
//===============================================
void GWindow::closeEvent(QCloseEvent *event) {
    GData::Instance()->save();
    event->accept();
}
//===============================================
