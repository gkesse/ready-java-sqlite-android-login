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
    void setData(std::string key, std::string value);
    std::string getData(std::string key);
    void saveData(std::string key, std::string value = "");
    void loadData(std::string key);
    int countData(std::string key);
    void insertData(std::string key, std::string value);
    void updateData(std::string key, std::string value);
    
public:
    static GConfig* m_instance;
    std::map<std::string, std::string> m_dataMap;
};
//===============================================
#endif
//===============================================
