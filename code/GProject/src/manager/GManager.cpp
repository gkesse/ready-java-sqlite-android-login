//===============================================
#include "GManager.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
GManager::GManager() {
    
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
std::string GManager::separatorGet() {
    std::string lSep = "/";
#if defined(__WIN32)
    lSep = "\\";
#endif
    return lSep;
}
//===============================================
std::vector<std::string> GManager::split(std::string strIn, char sepIn) {
    std::stringstream lStream(strIn);
    std::string lItem;
    std::vector<std::string> lDataMap;
    while (std::getline(lStream, lItem, sepIn)) {
        lDataMap.push_back(lItem);
    }    
    return lDataMap;
}
//===============================================
int GManager::splitCount(std::string strIn, char sepIn) {
    std::stringstream lStream(strIn);
    std::string lItem;
    std::vector<std::string> lDataMap;
    while (std::getline(lStream, lItem, sepIn)) {
        lDataMap.push_back(lItem);
    }    
    return lDataMap.size();
}
//===============================================
std::string GManager::splitGet(std::string strIn, char sepIn, int indexIn, std::string defaultIn) {
    std::stringstream lStream(strIn);
    std::string lItem;
    std::vector<std::string> lDataMap;
    while (std::getline(lStream, lItem, sepIn)) {
        lDataMap.push_back(lItem);
    }   
    int lCount = lDataMap.size();
    std::string lData = defaultIn;
    if(indexIn < lCount) lData = lDataMap[indexIn];
    return lData;
}
//===============================================
std::string GManager::dataPath() {
    return std::string(getenv("GPATH"));
}
//===============================================
