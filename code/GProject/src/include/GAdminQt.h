//===============================================
#ifndef _GAdminQt_
#define _GAdminQt_
//===============================================
#include "GInclude.h"
//===============================================
class GAdminQt : public QFrame { 
    Q_OBJECT
    
public:
    GAdminQt(QWidget* parent = 0);
    ~GAdminQt();
    
public slots:
    void slotMenuClick();
    
private:
    QString m_name;
};
//===============================================
#endif
//===============================================
