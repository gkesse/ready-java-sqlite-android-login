//===============================================
#ifndef _GWidget_
#define _GWidget_
//===============================================
#include "GInclude.h"
//===============================================
class GWidget {
public:
    GWidget();
    virtual ~GWidget();
    static GWidget* Create(std::string key);
    // method
    virtual void print();
};
//===============================================
#endif
//===============================================
