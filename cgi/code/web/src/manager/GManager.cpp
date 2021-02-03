//===============================================
#include "GManager.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
// constructor
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
// console
//===============================================
void GManager::print(QString data) {
    const char* lData = data.toStdString().c_str();
    printf("%s\n", lData);
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
    // page_id
    mgr->app->query_string = getEnv("QUERY_STRING");
    mgr->app->query_map = splitMap(mgr->app->query_string, "&", "=");
    mgr->app->page_id = getValue(mgr->app->query_map, "pageId", "");
    mgr->app->page_id = removeLast(mgr->app->page_id, '/');
    // page_last
    mgr->app->cookie_string = getEnv("HTTP_COOKIE");
    mgr->app->cookie_map = splitMap(mgr->app->cookie_string, "&", "=");
    mgr->app->page_last = getValue(mgr->app->cookie_map, "page_last", "");
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
// map
//===============================================
QString GManager::getValue(QMap<QString, QString> mapId, QString key, QString defaultValue) {
    QString lData = defaultValue;
    if(mapId.count(key)) {lData = mapId[key];}
    return lData;
}
//===============================================
