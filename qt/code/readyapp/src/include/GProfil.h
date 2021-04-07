//===============================================
#ifndef _GProfil_
#define _GProfil_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GProfil : public GWidget {    
    Q_OBJECT

public:
    GProfil(QWidget* parent = 0);
    ~GProfil();
    
public:
    int loadPage();
    
public slots:
    void slotItemClick();

private:
    QMap<QWidget*, QString> m_widgetId;
};
//===============================================
#endif
//===============================================