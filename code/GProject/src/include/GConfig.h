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
    void setData(std::string keyIn, std::string valueIn);
    std::string getData(std::string keyIn);

public:
    static GConfig* m_instance;
    std::map<std::string, std::string> m_dataMap;
};
//===============================================
#endif
//===============================================
