//===============================================
#ifndef _GJson_
#define _GJson_
//===============================================
#include "GInclude.h"
//===============================================
class GJson {
private:
    GJson();
    
public:
    ~GJson();
    static GJson* Instance();
    void test();
    QJsonValue open();
    int dataCount(QString key);
    QStringList dataCol(QString key);
    QStringList dataRow(QString key);
    
public:
    static GJson* m_instance;
};
//===============================================
#endif
//===============================================
