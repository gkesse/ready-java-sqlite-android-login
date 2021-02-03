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
    void addPage(QString address, QString key);
    void loadPage();
    void selectPage();
    void showPage();
    void redirect(QString newUrl);
    void setCookie(QString key, QString value);
    void getCookie(QString key, QString defaultValue);
    
private:
    static GWeb* m_instance;
    QMap<QString, QString> m_addressMap;
};
//===============================================
#endif
//===============================================
