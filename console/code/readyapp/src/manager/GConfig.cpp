//===============================================
#include "GConfig.h"
#include "GSQLite.h"
#include "GManager.h"
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
void GConfig::setData(std::string key, std::string value) {
    m_dataMap[key] = value;
}
//===============================================
std::string GConfig::getData(std::string key) {
    return m_dataMap[key];
}
//===============================================
void GConfig::saveData(std::string key, std::string value) {
    if(value == "") value = m_dataMap[key];
    if(countData(key) == 0) {insertData(key, value);}
    else {updateData(key, value);}
}
//===============================================
void GConfig::loadData(std::string key) {
    std::string lSql = GManager::Instance()->format("\
    select config_value\n\
    from config_data\n\
    where config_key='%s'\n\
    ", key.c_str());
    std::string lData = GSQLite::Instance()->queryValue(lSql);
    m_dataMap[key] = lData;
}
//===============================================
int GConfig::countData(std::string key) {
    std::string lSql = GManager::Instance()->format("\
    select count(*) from config_data\n\
    where config_key='%s'\n\
    ", key.c_str());
    std::string lCount = GSQLite::Instance()->queryValue(lSql);
    return std::stoi(lCount);
}
//===============================================
void GConfig::insertData(std::string key, std::string value) {
    std::string lSql = GManager::Instance()->format("\
    insert into config_data(config_key, config_value)\n\
    values('%s', '%s')\n\
    ", key.c_str(), value.c_str());
    GSQLite::Instance()->queryWrite(lSql);
}
//===============================================
void GConfig::updateData(std::string key, std::string value) {
    std::string lSql = GManager::Instance()->format("\
    update config_data\n\
    set config_value='%s'\n\
    where config_key='%s'\n\
    ", value.c_str(), key.c_str());
    GSQLite::Instance()->queryWrite(lSql);
}
//===============================================
