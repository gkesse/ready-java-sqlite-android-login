//===============================================
#include "GTitleBar.h"
#include "GManager.h"
//===============================================
GTitleBar::GTitleBar(QWidget* parent) : GWidget(parent) {
    setObjectName("GTitleBar");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lLogo = new QPushButton;
    lLogo->setObjectName("logo");
    lLogo->setIcon(QIcon(lApp->img_map["logo"]));
    lLogo->setCursor(Qt::PointingHandCursor);
    m_widgetId[lLogo] = "logo";
    
    QLabel* lAppName = new QLabel;
    lAppName->setObjectName("app_name");
    lAppName->setText(lApp->app_name);
    
    QLabel* lTitle = new QLabel;
    lApp->title = lTitle;
    lTitle->setObjectName("title");
    lTitle->setText("Acceuil");
    lTitle->setAlignment(Qt::AlignCenter);
    
    QPushButton* lLogin = new QPushButton;
    m_login = lLogin;
    lApp->login_titlebar = lLogin;
    lLogin->setObjectName("login");
    lLogin->setText("Se Connecter");
    lLogin->setIcon(GManager::Instance()->loadPicto(fa::user, lApp->picto_color));
    lLogin->setCursor(Qt::PointingHandCursor);
    m_widgetId[lLogin] = "login";

    QPushButton* lFullscreen = new QPushButton;
    m_fullscreen = lFullscreen;
    lFullscreen->setObjectName("fullscreen");
    lFullscreen->setIcon(QIcon(lApp->img_map["fullscreen"]));
    lFullscreen->setCursor(Qt::PointingHandCursor);
    m_widgetId[lFullscreen] = "fullscreen";

    QPushButton* lMinimize = new QPushButton;
    lMinimize->setObjectName("minimize");
    lMinimize->setIcon(GManager::Instance()->loadPicto(fa::windowminimize, lApp->picto_color));
    lMinimize->setCursor(Qt::PointingHandCursor);
    m_widgetId[lMinimize] = "minimize";

    QPushButton* lMaximize = new QPushButton;
    m_maximize = lMaximize;
    lMaximize->setObjectName("maximize");
    lMaximize->setIcon(GManager::Instance()->loadPicto(fa::windowmaximize, lApp->picto_color));
    lMaximize->setCursor(Qt::PointingHandCursor);
    m_widgetId[lMaximize] = "maximize";
    
    QPushButton* lClose = new QPushButton;
    lClose->setObjectName("close");
    lClose->setIcon(GManager::Instance()->loadPicto(fa::times, lApp->picto_color));
    lClose->setCursor(Qt::PointingHandCursor);
    m_widgetId[lClose] = "close";
    
    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->addWidget(lLogo);
    lMainLayout->addWidget(lAppName);
    lMainLayout->addWidget(lTitle, 1);
    lMainLayout->addWidget(lLogin);
    lMainLayout->addWidget(lFullscreen);
    lMainLayout->addWidget(lMinimize);
    lMainLayout->addWidget(lMaximize);
    lMainLayout->addWidget(lClose);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(2);

    setLayout(lMainLayout);
    
    connect(lLogo, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lLogin, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lFullscreen, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lMinimize, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lMaximize, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lClose, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GTitleBar::~GTitleBar() {
    
}
//===============================================
// slot
//===============================================
void GTitleBar::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    if(lWidgetId == "fullscreen") {
        if(lApp->win->windowState() != Qt::WindowFullScreen) {
            if(lApp->win->windowState() == Qt::WindowMaximized) {
                m_maximize->setIcon(GManager::Instance()->loadPicto(fa::windowmaximize, lApp->picto_color));
            }
            lApp->win->showFullScreen();
            m_fullscreen->setIcon(QIcon(lApp->img_map["fullscreen_exit"]));
        }
        else {
            lApp->win->showNormal();
            m_fullscreen->setIcon(QIcon(lApp->img_map["fullscreen"]));
            m_maximize->setIcon(GManager::Instance()->loadPicto(fa::windowmaximize, lApp->picto_color));
        }
    }
    else if(lWidgetId == "minimize") {
        lApp->win->showMinimized();
    }
    else if(lWidgetId == "maximize") {
        if(lApp->win->windowState() != Qt::WindowMaximized) {
            if(lApp->win->windowState() == Qt::WindowFullScreen) {
                m_fullscreen->setIcon(QIcon(lApp->img_map["fullscreen"]));
            }
            lApp->win->showMaximized();
            m_maximize->setIcon(GManager::Instance()->loadPicto(fa::windowrestore, lApp->picto_color));
        }
        else {
            lApp->win->showNormal();
            m_maximize->setIcon(GManager::Instance()->loadPicto(fa::windowmaximize, lApp->picto_color));
            m_fullscreen->setIcon(QIcon(lApp->img_map["fullscreen"]));
        }
    }
    else if(lWidgetId == "close") {
        lApp->win->close();
    }
    else if(lWidgetId == "login") {
        if(lApp->login_on == "off") {GManager::Instance()->setPage("home/login");}
        else if(lApp->login_on == "on") {GManager::Instance()->setPage("home/profil");}
    }
}
//===============================================
void GTitleBar::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        setCursor(QCursor(Qt::SizeAllCursor));
        m_pressPos = event->pos();
        m_pressFlag = true;
    }
}
//===============================================
void GTitleBar::mouseReleaseEvent(QMouseEvent *event) {
    setCursor(QCursor(Qt::ArrowCursor));
    m_pressFlag = false;
}
//===============================================
void GTitleBar::mouseMoveEvent(QMouseEvent *event) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(m_pressFlag == true) {
        QPoint lGlobalPos = event->globalPos();
        QPoint lDiffPos = lGlobalPos - m_pressPos;
        lApp->win->move(lDiffPos);
    }    
}
//===============================================
