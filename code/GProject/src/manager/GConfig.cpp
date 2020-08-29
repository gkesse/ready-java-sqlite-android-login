//===============================================
#include "GConfig.h"
#include "GSQLiteMgr.h"
//===============================================
#define B_QUERY (256)
//===============================================
GConfig* GConfig::m_instance = 0;
//===============================================
GConfig::GConfig() {
    
}
//===============================================
GConfig::~GConfig() {
    
}
//===============================================
GConfig* GConfig::Instance() {
    if(m_instance == 0) {
        m_instance = new GConfig;
    }
    return m_instance;
}
//===============================================
void GConfig::setData(std::string keyIn, std::string valueIn) {
    m_dataMap[keyIn] = valueIn;
}
//===============================================
std::string GConfig::getData(std::string keyIn) {
    return m_dataMap[keyIn];
}
//===============================================
void GConfig::saveData(std::string keyIn, std::string valueIn) {
    if(valueIn == "") valueIn = m_dataMap[keyIn];
    if(checkData(keyIn) == 0) {insertData(keyIn, valueIn);}
    else {updateData(keyIn, valueIn);}
}
//===============================================
void GConfig::loadData(std::string keyIn) {
    char lSql[B_QUERY+1];
    sprintf(lSql, ""
    "select CONFIG_VALUE\n"
    "from CONFIG_DATA\n"
    "where CONFIG_KEY='%s'\n"
    "", keyIn.c_str());
    std::string lData = GSQLiteMgr::Instance()->queryValue("", lSql);
    m_dataMap[keyIn] = lData;
}
//===============================================
int GConfig::checkData(std::string keyIn) {
    char lSql[B_QUERY+1];
    sprintf(lSql, ""
    "select count(*)\n"
    "from CONFIG_DATA\n"
    "where CONFIG_KEY='%s'\n"
    "", keyIn.c_str());
    std::string lCount = GSQLiteMgr::Instance()->queryValue("", lSql);
    return std::stoi(lCount);
}
//===============================================
void GConfig::insertData(std::string keyIn, std::string valueIn) {
    char lSql[B_QUERY+1];
    sprintf(lSql, ""
    "insert into CONFIG_DATA(CONFIG_KEY, CONFIG_VALUE)\n"
    "values('%s', '%s')\n"
    "", keyIn.c_str(), valueIn.c_str());
    GSQLiteMgr::Instance()->queryWrite("", lSql);
}
//===============================================
void GConfig::updateData(std::string keyIn, std::string valueIn) {
    char lSql[B_QUERY+1];
    sprintf(lSql, ""
    "update CONFIG_DATA\n"
    "set CONFIG_VALUE='%s'\n"
    "where CONFIG_KEY='%s'\n"
    "", valueIn.c_str(), keyIn.c_str());
    GSQLiteMgr::Instance()->queryWrite("", lSql);
}
//===============================================
