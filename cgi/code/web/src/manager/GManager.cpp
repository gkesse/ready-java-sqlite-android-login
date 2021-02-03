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
    mgr->app->logo_path = "./data/img/logo.png";
    mgr->app->style_path = "./data/css/style.css";
    mgr->app->font_path = "./libs/font_awesome/4.7.0/css/font-awesome.min.css";
    mgr->app->icon_path = "./libs/google_fonts/1.0.0";
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
// env
//===============================================
std::string GManager::getEnv(std::string key) {
    char* lValue = getenv(key.c_str());
    if(lValue == 0) return "";
    return lValue;
}
//===============================================
void GManager::loadEnv() {
    // page_id
    mgr->app->query_string = getEnv("QUERY_STRING");
    mgr->app->query_map = splitMap(mgr->app->query_string, '&', '=');
    mgr->app->page_id = getValue(mgr->app->query_map, "pageId", "");
    mgr->app->page_id = removeLast(mgr->app->page_id, '/');
    // page_last
    mgr->app->cookie_string = getEnv("HTTP_COOKIE");
    mgr->app->cookie_map = splitMap(mgr->app->cookie_string, ';', '=');
    mgr->app->page_last = getValue(mgr->app->cookie_map, "page_last", "");
}
//===============================================
// string
//===============================================
std::vector<std::string> GManager::split(std::string str, char sep) {
    std::vector<std::string> lDataMap;
    std::istringstream lStream(str);
    std::string lData;    
    while (std::getline(lStream, lData, sep)) {
        lDataMap.push_back(lData);
    }
    return lDataMap;
}
//===============================================
std::map<std::string, std::string> GManager::splitMap(std::string str, char sepRow, char sepCol) {
    std::vector<std::string> lDataRow = split(str, sepRow);
    std::map<std::string, std::string> lDataMap;
    for(int i = 0; i < lDataRow.size(); i++) {
        std::string lData = lDataRow[i];
        std::vector<std::string> lDataCol = split(lData, sepCol);
        std::string lKey = lDataCol[0];
        std::string lValue = lDataCol[1];
        lDataMap[lKey] = lValue;
    }
    return lDataMap;
}
//===============================================
std::string GManager::removeLast(std::string str, char remove) {
    std::string lData = str;
    if(lData.back() == remove) lData.pop_back();
    return lData;
}
//===============================================
// map
//===============================================
std::string GManager::getValue(std::map<std::string, std::string> mapId, std::string key, std::string defaultValue) {
    std::string lData = defaultValue;
    if(mapId.count(key)) {lData = mapId[key];}
    return lData;
}
//===============================================
