//===============================================
#ifndef _GConfig_
#define _GConfig_
//===============================================
#include "GInclude.h"
//===============================================
class GConfig {
private:
    GConfig();
    
public:
    ~GConfig();
    static GConfig* Instance();
    void setData(QString key, QString value);
    QString getData(QString key);
    void saveData(QString key, QString value = "");
    void loadData(QString key);
    int countData(QString key);
    void insertData(QString key, QString value);
    void updateData(QString key, QString value);
    
public:
    static GConfig* m_instance;
    std::map<QString, QString> m_dataMap;
};
//===============================================
#endif
//===============================================
