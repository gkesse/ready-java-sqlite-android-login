//===============================================
#ifndef _GTutorial_
#define _GTutorial_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GTutorial : public GWidget {    
    Q_OBJECT

public:
    GTutorial(QWidget* parent = 0);
    ~GTutorial();
    
public slots:
    void slotItemClick();
};
//===============================================
#endif
//===============================================