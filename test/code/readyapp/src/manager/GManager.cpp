//===============================================
#include "GManager.h"
//===============================================
#define GBUFFER_SIZE (1024)
//===============================================
GManager* GManager::m_instance = 0;
//=============================================== 
GManager::GManager() {
    // manager
    mgr = new sGManager;
    // app
    mgr->app = new sGApp;
    mgr->app->app_name = "ReadyApp";
    mgr->app->sqlite_db_path = getEnv("GSQLITE_DB_PATH");
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
std::string GManager::getEnv(std::string env) {
    std::string lValue = std::getenv(env.c_str());
    return lValue;
}
//===============================================
// string
//===============================================
std::string GManager::format(const char* format, ...) {
    char lBuffer[GBUFFER_SIZE+1];
    va_list lAgrs;
    va_start(lAgrs, format);
    vsprintf(lBuffer, format, lAgrs);
    va_end(lAgrs);
    return std::string(lBuffer);
}
//===============================================
int GManager::getWidth(std::string widthMap, int index, int defaultWidth) {
    std::vector<std::string> lWidthMap = split(widthMap, ";");
    int lLength = lWidthMap.size();
    if(index >= lLength) {return defaultWidth;}
    std::string lWidthId = lWidthMap.at(index);
    bool lOk = isNumber(lWidthId);
    if(lOk == false) {return defaultWidth;}
    int lWidth = std::stoi(lWidthId);
    return lWidth;
}
//===============================================
bool GManager::isNumber(const std::string& str) {
    std::string::const_iterator lIter = str.begin();
    while (lIter != str.end() && std::isdigit(*lIter)) ++lIter;
    return !str.empty() && lIter == str.end();
}
//===============================================
std::vector<std::string> GManager::split(std::string str, std::string sep) {
    std::vector<std::string> lDataMap;
    size_t lPos = 0;
    std::string lToken;
    while ((lPos = str.find(sep)) != std::string::npos) {
        lToken = str.substr(0, lPos);
        lDataMap.push_back(str);
        str.erase(0, lPos + sep.length());
    }
    lDataMap.push_back(str);
    return lDataMap;
}
//===============================================
