//================================================
#ifndef _GConfig_
#define _GConfig_
//================================================
#include "GInclude.h"
//================================================
class GConfig {
private:
    GConfig();

public:
    ~GConfig();
    static GConfig* Instance();
    void test(int argc, char** argv);
    void setData(std::string key, std::string value);
    std::string getData(std::string key);
    int size();
    void removeData(std::string key);
    void clear();
    void showData();

private:
    const char* __CLASSNAME__;
    static GConfig* m_instance;
    std::map<std::string, std::string> m_dataMap;
};
//================================================
#endif
//================================================
