//===============================================
#include "GQt.h"
#include "GEnv.h"
#include "GDebug.h"
//================================================
#if defined(_GUSE_QT_ON_)
//===============================================
GQt* GQt::m_instance = 0;
//===============================================
GQt::GQt() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GQt::~GQt() {

}
//===============================================
GQt* GQt::Instance() {
    if(m_instance == 0) {
        m_instance = new GQt;
    }
    return m_instance;
}
//===============================================
void GQt::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    bool lRunFlag = 0;
    for(int i = 2; i < argc;) {
    	string lKey = argv[i++];
    	if(lKey == "dbus") {
    		dbus(argc, argv); lRunFlag = 1; break;
    	}
    	break;
    }
    if(lRunFlag == 0) defaulTest(argc, argv);
}
//===============================================
void GQt::defaulTest(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GEnv::Instance()->setEnv();
    QApplication lApp(argc, argv);
    QWidget* lWidget = new QWidget;
    lWidget->setWindowTitle("Qt | ReadyDev");
    lWidget->resize(640, 480);
    lWidget->show();
    lApp.exec();
}
//===============================================
void GQt::dbus(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GEnv::Instance()->setEnv();
    bool lConnectFlag = QDBusConnection::sessionBus().isConnected();
    if (lConnectFlag == 0) {qDebug() << "erreur connexion dbus\n"; exit(0);}
    QDBusConnection::sessionBus().registerObject("/", this);
    QDBusConnection::sessionBus().connect(QString(), QString(), "org.example.chat", "message", this, SLOT(slotDBus(QString,QString)));
    qDebug() << "okooooooooooooooo\n";
}
//===============================================
void GQt::slotDBus(QString nickname, QString text) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
#endif
//===============================================
