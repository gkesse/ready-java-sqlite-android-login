//===============================================
#ifndef _GHome_
#define _GHome_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GHome : public GWidget {    
    Q_OBJECT

public:
    GHome(QWidget* parent = 0);
    ~GHome();

public:
    int loadPage();
    
public slots:
    void slotItemClick();
};
//===============================================
#endif
//===============================================