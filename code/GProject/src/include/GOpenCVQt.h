//===============================================
#ifndef _GOpenCVQt_
#define _GOpenCVQt_
//===============================================
#include "GInclude.h"
//===============================================
class GOpenCVQt : public QFrame { 
    Q_OBJECT
    
public:
    GOpenCVQt(QWidget* parent = 0);
    ~GOpenCVQt();
    
public slots:
    void slotMenuClick();
    
private:
    QString m_name;
};
//===============================================
#endif
//===============================================
