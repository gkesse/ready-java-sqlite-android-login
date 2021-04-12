//===============================================
#ifndef _GData_
#define _GData_
//===============================================
#include "GInclude.h"
//===============================================
class GData {
private:
    GData();
    
public:
    ~GData();
    static GData* Instance();
    void save();
    void load();
    void saveData(QString key, QString value);
    int countData(QString key);
    void insertData(QString key, QString value);
    void updateData(QString key, QString value);
    QString loadData(QString key, QString defaultValue);

private:
    static GData* m_instance;
};
//===============================================
#endif
//===============================================