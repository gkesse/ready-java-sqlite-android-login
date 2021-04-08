//===============================================
#include "GMainWindow.h"
#include "GOpenCV.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GMainWindow::GMainWindow(QWidget* parent) : GWidget(parent) {
    setObjectName("GMainWindow");
    
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
    lSettingMenu->setCursor(Qt::PointingHandCursor);
        
    QMainWindow* lWorkspace = new QMainWindow;
    lWorkspace->setObjectName("workspace");
    
    QTextEdit* lTextEdit = new QTextEdit;
    lTextEdit->setObjectName("workspace");
    lWorkspace->setCentralWidget(lTextEdit);
    
    QTextCursor lTextCursor(lTextEdit->textCursor());
    lTextCursor.movePosition(QTextCursor::Start);
    QTextFrame* lTextFrame = lTextCursor.currentFrame();

    QTextTableFormat lTextTableFormatLeft;
    lTextTableFormatLeft.setBorder(0);
    lTextTableFormatLeft.setCellPadding(0);
    lTextTableFormatLeft.setAlignment(Qt::AlignLeft);
    
    QTextTableFormat lTextTableFormatRight;
    lTextTableFormatRight.setBorder(0);
    lTextTableFormatRight.setCellPadding(0);
    lTextTableFormatRight.setAlignment(Qt::AlignRight);
    
    QTextCharFormat lTextCharFormat;
    
    QTextCharFormat lTextCharFormatBold;
    lTextCharFormatBold.setFontWeight(QFont::Bold);
        
    lTextCursor.insertTable(1, 1, lTextTableFormatLeft);
    lTextCursor.insertText("Gerard KESSE", lTextCharFormatBold);
    lTextCursor.insertBlock();
    lTextCursor.insertText("25 Rue du Général Leclerc", lTextCharFormat);
    lTextCursor.insertBlock();
    lTextCursor.insertText("67000 Strasbourg", lTextCharFormat);
    
    lTextCursor.setPosition(lTextFrame->lastPosition());
    lTextCursor.insertTable(1, 1, lTextTableFormatRight);
    lTextCursor.insertText(QDate::currentDate().toString("dd MMMM yyyy"), lTextCharFormat);
   
    lTextCursor.setPosition(lTextFrame->lastPosition());
    lTextCursor.insertText("Monsieur le Directeur,", lTextCharFormat);

    for(int i = 0; i < 2; ++i) {lTextCursor.insertBlock();}
    lTextCursor.insertText("Je vous transmets ci-joint ma feuille de temps du mois d'avril 2021.", lTextCharFormat);
    for(int i = 0; i < 2; ++i) {lTextCursor.insertBlock();}
    
    lTextCursor.insertTable(1, 1, lTextTableFormatRight);
    lTextCursor.insertText("Cordialement,", lTextCharFormat);
    lTextCursor.insertBlock();
    lTextCursor.insertText("Gérard KESSE", lTextCharFormat);
    lTextCursor.insertBlock();
    lTextCursor.insertText("Architecte logiciel C/C++/Qt", lTextCharFormat);

    // on crée le qdockwidget (clients)
    QDockWidget* lDockWidget = new QDockWidget(tr("Clients"), lWorkspace);
    // on définit les positions du qdockwidget (gauche, droite)
    lDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    // on crée le contenu du qdockwidget
    QListWidget* lListWidget = new QListWidget;
    lListWidget->addItems(QStringList()
    << "Gerard KESSE, Sogetek, 75 Paris, France"
    << "Jane Doe, Memorabilia, 23 Watersedge, Beaton"
    << "Tammy Shea, Tiblanka, 38 Sea Views, Carlton"
    << "Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal"
    << "Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston"
    << "Sally Hobart, Tiroli Tea, 67 Long River, Fedula");
    lListWidget->setAlternatingRowColors(true);
    lListWidget->setCursor(Qt::PointingHandCursor);
    // on initialise le contenu du qdockwidget
    lDockWidget->setWidget(lListWidget);
    // on ajoute le qdockwidget dans le qmainwindow
    lWorkspace->addDockWidget(Qt::RightDockWidgetArea, lDockWidget);
    // on initialise l'action de déclenchement du qdockwidget dans le qmenu
    lSettingMenu->addAction(lDockWidget->toggleViewAction());
    
    // on crée le qdockwidget (messages)
    lDockWidget = new QDockWidget(tr("Messages"), lWorkspace);
    // on définit les positions du qdockwidget (gauche, droite)
    lDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    // on crée le contenu du qdockwidget
    lListWidget = new QListWidget;
    lListWidget->addItems(QStringList()
    << "Merci pour votre paiement que nous avons reçu aujourd'hui."
    << "Votre commande a été expédiée et devrait être avec vous"
    "dans les 28 jours."
    << "Nous avons expédié les articles qui étaient en stock. Le"
    "le reste de votre commande sera expédié une fois tous les"
    "les articles restants sont arrivés à notre entrepôt. Non"
    "des frais d'expédition supplémentaires seront facturés."
    << "Vous avez effectué un petit trop-payé (moins de 5 $) que nous"
    "conservera votre compte pour vous, ou reviendra à votre demande."
    << "Vous avez effectué un petit sous-paiement (moins de 1 $), mais nous l'avons"
    "a quand même envoyé votre commande. Nous ajouterons ce sous-paiement à"
    "votre prochaine facture."
    << "Malheureusement, vous n’avez pas envoyé suffisamment d’argent. Veuillez l’envoyer"
    "un $ supplémentaire. Votre commande sera expédiée dès que"
    "le montant complet a été reçu."
    << "Vous avez effectué un trop-payé (plus de 5 $). Souhaitez-vous"
    "acheter plus d'articles ou doit-on vous rendre l'excédent?");     lDockWidget->setWidget(lListWidget);
    lListWidget->setAlternatingRowColors(true);
    lListWidget->setCursor(Qt::PointingHandCursor);
    // on initialise le contenu du qdockwidget
    lDockWidget->setWidget(lListWidget);
    // on ajoute le qdockwidget dans le qmainwindow
    lWorkspace->addDockWidget(Qt::RightDockWidgetArea, lDockWidget);
    // on initialise l'action de déclenchement du qdockwidget dans le qmenu
    lSettingMenu->addAction(lDockWidget->toggleViewAction());
    
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
GMainWindow::~GMainWindow() {

}
//===============================================
// method
//===============================================
void GMainWindow::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    if(lApp->widget_id == "setting") {
        QPoint lPos = QCursor::pos();
        m_settingMenu->exec(lPos);
    }
}
//===============================================
void GMainWindow::slotItemClick(QAction* action) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    lApp->widget_id = action->data().toString();

    if(lApp->widget_id == "open_image") {

    }
}
//===============================================
