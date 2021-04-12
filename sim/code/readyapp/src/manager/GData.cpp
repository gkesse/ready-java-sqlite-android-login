//===============================================
#include "GData.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
GData* GData::m_instance = 0;
//===============================================
GData::GData() {

}
//===============================================
GData::~GData() {
    
}
//===============================================
GData* GData::Instance() {
    if(m_instance == 0) {
        m_instance = new GData;
    }
    return m_instance;
}
//===============================================
void GData::save() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    saveData("dir_path", lApp->dir_path);
}
//===============================================
void GData::load() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    lApp->dir_path = loadData("dir_path", lApp->dir_path);
}
//===============================================
void GData::saveData(QString key, QString value) {
    int lCount = countData(key);
    if(lCount == 0) {insertData(key, value);}
    else {updateData(key, value);}
}
//===============================================
int GData::countData(QString key) {
    QString lSql = QString("\
    select count(*) from qt_data\n\
    where config_key='%1'\n\
    ").arg(key);
    QString lCount = GSQLite::Instance()->queryValue(lSql);
    return std::stoi(lCount.toStdString());
}
//===============================================
void GData::insertData(QString key, QString value) {
    QString lSql = QString("\
    insert into qt_data(config_key, config_value)\n\
    values('%1', '%2')\n\
    ").arg(key).arg(value);
    GSQLite::Instance()->queryWrite(lSql);
}
//===============================================
void GData::updateData(QString key, QString value) {
    QString lSql = QString("\
    update qt_data\n\
    set config_value='%2'\n\
    where config_key='%1'\n\
    ").arg(key).arg(value);
    GSQLite::Instance()->queryWrite(lSql);
}
//===============================================
QString GData::loadData(QString key, QString defaultValue) {
    int lCount = countData(key);
    if(lCount == 0) {return defaultValue;}
    QString lSql = QString("\
    select config_value from qt_data\n\
    where config_key='%1'\n\
    ").arg(key);
    QString lData = GSQLite::Instance()->queryValue(lSql);
    return lData;
}
//===============================================
