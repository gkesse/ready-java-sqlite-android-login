//===============================================
#include "GConfig.h"
#include "GSQLite.h"
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
void GConfig::setData(QString key, QString value) {
    m_dataMap[key] = value;
}
//===============================================
QString GConfig::getData(QString key) {
    return m_dataMap[key];
}
//===============================================
void GConfig::saveData(QString key, QString value) {
    if(value == "") value = m_dataMap[key];
    if(countData(key) == 0) {insertData(key, value);}
    else {updateData(key, value);}
}
//===============================================
void GConfig::loadData(QString key) {
    QString lSql = QString("\
    select config_value\n\
    from config_data\n\
    where config_key='%1'\n\
    ").arg(key);
    QString lData = GSQLite::Instance()->queryValue(QString(lSql));
    m_dataMap[key] = lData;
}
//===============================================
int GConfig::countData(QString key) {
    QString lSql = QString("\
    select count(*) from config_data\n\
    where config_key='%1'\n\
    ").arg(key);
    QString lCount = GSQLite::Instance()->queryValue(lSql);
    return std::stoi(lCount.toStdString());
}
//===============================================
void GConfig::insertData(QString key, QString value) {
    QString lSql = QString("\
    insert into config_data(config_key, config_value)\n\
    values('%1', '%2')\n\
    ").arg(key).arg(value);
    GSQLite::Instance()->queryWrite(lSql);
}
//===============================================
void GConfig::updateData(QString key, QString value) {
    QString lSql = QString("\
    update config_data\n\
    set config_value='%2'\n\
    where config_key='%1'\n\
    ").arg(key).arg(value);
    GSQLite::Instance()->queryWrite(lSql);
}
//===============================================
