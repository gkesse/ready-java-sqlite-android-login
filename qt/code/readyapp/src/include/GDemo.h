//===============================================
#ifndef _GDemo_
#define _GDemo_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GDemo : public GWidget {    
    Q_OBJECT

public:
    GDemo(QWidget* parent = 0);
    ~GDemo();
    
public slots:
    void slotItemClick();
};
//===============================================
#endif
//===============================================