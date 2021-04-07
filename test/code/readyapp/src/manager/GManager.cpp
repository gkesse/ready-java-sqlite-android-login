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
void GManager::showData(std::string data) {
    printf("[%s]\n", data.c_str());
}
//===============================================
void GManager::showData(std::vector<std::string> data) {
    for(int i = 0; i < data.size(); i++) {
        std::string lData = data.at(i);
        if(i == 0) {printf("[");}
        if(i != 0) {printf(" ; ");}
        printf("%s", lData.c_str());
        if(i + 1 == data.size()) {printf("]\n");}
    }
}
//===============================================
void GManager::showData(std::vector<std::vector<std::string>> data) {
    for(int i = 0; i < data.size(); i++) {
        std::vector<std::string> lRow = data.at(i);
        for(int j = 0; j < lRow.size(); j++) {
            std::string lData = lRow.at(j);
            if(j == 0) {printf("[");}
            if(j != 0) {printf(" ; ");}
            printf("%s", lData.c_str());
            if(j + 1 == lRow.size()) {printf("]\n");}
        }
    }
}
//===============================================
// env
//===============================================
std::string GManager::getEnv(std::string env, std::string defaultValue) {
    std::string lValue = defaultValue;
    char* lData = std::getenv(env.c_str());
    if(lData != 0) {lValue = lData;}
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
    std::vector<std::string> lWidthMap = split(widthMap, ';');
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
std::vector<std::string> GManager::split(std::string str, char sep) {
    std::vector<std::string> lDataMap;
    std::stringstream lStream(str);
    std::string lLine;
    while (std::getline(lStream, lLine, sep)) {
        lDataMap.push_back(lLine);
    }
    return lDataMap;
}
//===============================================
