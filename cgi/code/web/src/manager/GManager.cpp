//===============================================
#include "GManager.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
GManager::GManager() {
    // manager
    mgr = new sGManager;
    // app
    mgr->app = new sGApp;
    mgr->app->app_name = "ReadyApp";
    mgr->app->app_title = mgr->app->app_name;
    mgr->app->logo_path = "/data/img/logo.png";
    mgr->app->style_path = "/data/css/style.css";
    mgr->app->font_path = "/libs/font_awesome/css/font-awesome.min.css";
    mgr->app->icon_path = "/libs/google_fonts/1.0.0";
    mgr->app->page_last = "home";
    mgr->app->mime_type = "text/html";
}
//===============================================
GManager::~GManager() {
    
}
//===============================================
GManager* GManager::Instance() {
    if(m_instance == 0) {
        m_instance = new GManager;
    }
    return m_instance;
}
//===============================================
// data
//===============================================
sGManager* GManager::getData() {
    return mgr;
}
//===============================================
// env
//===============================================
QString GManager::getEnv(QString key) {
    char* lValue = getenv(key.toStdString().c_str());
    if(lValue == 0) return "";
    return lValue;
}
//===============================================
void GManager::loadEnv() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    // page_id
    lApp->query_string = getEnv("QUERY_STRING");
    lApp->query_map = splitMap(lApp->query_string, "&", "=");
    lApp->page_id = getQuery("page_id", "");
    lApp->page_id = removeLast(lApp->page_id, '/');
    // page_last
    lApp->cookie_string = getEnv("HTTP_COOKIE");
    lApp->cookie_map = splitMap(lApp->cookie_string, "&", "=");
    lApp->page_last = getCookie("page_last", "");
}
//===============================================
// string
//===============================================
QMap<QString, QString> GManager::splitMap(QString str, QString sepRow, QString sepCol) {
    QMap<QString, QString> lDataMap;
    if(str == "") {return lDataMap;}
    QStringList lDataRow = str.split(sepRow);
    for(int i = 0; i < lDataRow.size(); i++) {
        QString lData = lDataRow[i];
        QStringList lDataCol = lData.split(sepCol);
        QString lKey = lDataCol[0];
        QString lValue = lDataCol[1];
        lDataMap[lKey] = lValue;
    }
    return lDataMap;
}
//===============================================
QString GManager::removeLast(QString str, char remove) {
    QString lData = str;
    if(lData.back() == remove) lData.chop(1);
    return lData;
}
//===============================================
// query
//===============================================
QString GManager::getQuery(QString key, QString defaultValue) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    return lApp->query_map.value(key, defaultValue);
}
//===============================================
// cookie
//===============================================
QString GManager::getCookie(QString key, QString defaultValue) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    return lApp->cookie_map.value(key, defaultValue);
}
//===============================================
