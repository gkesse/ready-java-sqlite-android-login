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
    void setCookie(QString key, QString value);
    
private:
    static GWeb* m_instance;
};
//===============================================
#endif
//===============================================
