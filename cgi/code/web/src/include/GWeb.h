//===============================================
#ifndef _GWeb_
#define _GWeb_
//===============================================
#include "GInclude.h"
//===============================================
class GWeb {
private:
    GWeb();
    
public:
    virtual ~GWeb();
    static GWeb* Instance();
    void run(int argc, char** argv);
    void addPage(std::string address, std::string key);
    void loadPage();
    void selectPage();
    void showPage();
    void redirect(std::string newUrl);
    void setCookie(std::string key, std::string value);
    void getCookie(std::string key, std::string defaultValue);
    
private:
    static GWeb* m_instance;
    std::map<std::string, std::string> m_addressMap;
};
//===============================================
#endif
//===============================================
