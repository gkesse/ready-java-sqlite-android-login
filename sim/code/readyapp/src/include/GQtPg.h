//===============================================
#ifndef _GQtPg_
#define _GQtPg_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GQtPg : public GWidget {    
    Q_OBJECT

public:
    GQtPg(QWidget* parent = 0);
    ~GQtPg();
    
public slots:
    void slotItemClick();
};
//===============================================
#endif
//===============================================