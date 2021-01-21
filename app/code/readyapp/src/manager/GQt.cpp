//===============================================
#include "GQt.h"
#include "GWidget.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
GQt* GQt::m_instance = 0;
//===============================================
GQt::GQt() {

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
void GQt::run(int argc, char** argv) {
    QApplication lApp(argc, argv);
    GSQLite::Instance();
    GManager::Instance()->initData();
    qDebug() << "debug 1";
    GManager::Instance()->loadFont();
    qDebug() << "debug 2";
    GManager::Instance()->loadImg();
    GManager::Instance()->loadStyle();
    GWidget* lWindow = GWidget::Create("window");
    lWindow->show();
    lApp.exec();
}
//===============================================
