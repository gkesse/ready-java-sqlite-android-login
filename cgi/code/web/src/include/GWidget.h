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
    static GWidget* Create(QString key);
    // method
    virtual void print();
    virtual void start();
    virtual void end();
    virtual void addItem(QString text);
    virtual void addItem(QString text, QString link, QString icon);
    virtual void addPage(QString key, QString page);
    virtual void showPage(QString key);
};
//===============================================
#endif
//===============================================
