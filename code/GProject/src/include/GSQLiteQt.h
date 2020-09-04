//===============================================
#ifndef _GSQLiteQt_
#define _GSQLiteQt_
//===============================================
#include "GInclude.h"
//===============================================
class GSQLiteQt : public QFrame { 
    Q_OBJECT
    
public:
    GSQLiteQt(QWidget* parent = 0);
    ~GSQLiteQt();
    
public slots:
    void slotMenuClick();
    
private:
    QString m_name;
};
//===============================================
#endif
//===============================================
