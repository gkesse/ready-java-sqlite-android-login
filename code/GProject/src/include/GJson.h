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
    int dataCount(std::string key);
    QStringList dataCol(std::string key);
    QStringList dataRow(std::string key);
    
public:
    static GJson* m_instance;
};
//===============================================
#endif
//===============================================
