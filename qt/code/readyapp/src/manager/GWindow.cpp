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
    
    GWidget* lWorkspace = GWidget::Create("stackwidget");
    lApp->page_map = lWorkspace;

    // home
    lWorkspace->addPage("home", "Accueil", GWidget::Create("home"));
    lWorkspace->addPage("home/opencv", "OpenCV", GWidget::Create("opencv"));
    // qt
    lWorkspace->addPage("home/qt", "Qt", GWidget::Create("qt"), 1);
    lWorkspace->addPage("home/qt/qgraphicsview", "QGraphicsView", GWidget::Create("qgraphicsview"));
    lWorkspace->addPage("home/qt/qmainwindow", "QMainWindow", GWidget::Create("qmainwindow"));
    lWorkspace->addPage("home/qt/qdatastream", "QDataStream", GWidget::Create("qdatastream"), 1);
    // login
    lWorkspace->addPage("home/login", "Connexion", GWidget::Create("login"));
    lWorkspace->addPage("home/profil", "Profil", GWidget::Create("profil"));
    // sqlite
    lWorkspace->addPage("home/sqlite", "Tables", GWidget::Create("sqlitetables"));
    lWorkspace->addPage("home/sqlite/users", "Table USERS", GWidget::Create("usermap"));
    lWorkspace->addPage("home/sqlite/users/show", "Données d'un utilisateur", GWidget::Create("usershow"));
    lWorkspace->addPage("home/sqlite/users/schema", "Schéma de la table USER", GWidget::Create("schema"));
    lWorkspace->addPage("home/sqlite/users/add", "Ajouter un utilisateur", GWidget::Create("useradd"));
    lWorkspace->addPage("home/sqlite/config_data", "Table CONFIG_DATA", GWidget::Create("config_data"));
    lWorkspace->addPage("home/sqlite/config_data/schema", "Afficher le schéma", GWidget::Create("schema"));
    // pdf
    lWorkspace->addPage("home/pdf", "Pdf", GWidget::Create("pdfui"));
    // timesheet
    lWorkspace->addPage("home/timesheet", "Timesheet", GWidget::Create("timesheet"));
    // debug
    lWorkspace->addPage("home/debug", "Debug", GWidget::Create("debug"));
    // error
    lWorkspace->addPage("home/error", "Erreur", GWidget::Create("error"));

    QScrollArea* lScrollArea = new QScrollArea;
    lScrollArea->setObjectName("workspace");
    lScrollArea->setWidget(lWorkspace);
    lScrollArea->setWidgetResizable(true);
        
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lTitleBar);
    lMainLayout->addWidget(lAddressBar);
    lMainLayout->addWidget(lAddressKey);
    lMainLayout->addWidget(lScrollArea);
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
