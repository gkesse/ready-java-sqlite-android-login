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
    virtual void start();
    virtual void end();
    virtual void addItem(std::string text);
    virtual void addItem(std::string text, std::string link, std::string icon);
};
//===============================================
#endif
//===============================================
