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
    int dataCount(const char* key, ...);
    QStringList dataCol(const char* key, ...);
    QStringList dataRow(const char* key, ...);
    
public:
    static GJson* m_instance;
};
//===============================================
#endif
//===============================================
