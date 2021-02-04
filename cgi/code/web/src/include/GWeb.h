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
    void addPage(QString address, QString key, QString title);
    void loadPage();
    void selectPage();
    void showPage();
    void setCookie(QString key, QString value);
    void mimeType();
    
private:
    static GWeb* m_instance;
};
//===============================================
#endif
//===============================================
