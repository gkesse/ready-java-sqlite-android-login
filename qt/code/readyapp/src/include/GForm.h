//===============================================
#ifndef _GForm_
#define _GForm_
//===============================================
#include "GInclude.h"
//===============================================
class GForm {
private:
    GForm();
    
public:
    ~GForm();
    static GForm* Instance();
    QFrame* create(QString key = "");

private:
    QFrame* createDefault();
    QFrame* createKeyValue();
    QFrame* createLineEdit();
    
public:
    static GForm* m_instance;
};
//===============================================
#endif
//===============================================
