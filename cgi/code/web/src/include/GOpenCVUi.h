//===============================================
#ifndef _GOpenCVUi_
#define _GOpenCVUi_
//===============================================
#include "GWidget.h"
//===============================================
class GOpenCVUi : public GWidget {
public:
    GOpenCVUi();
    ~GOpenCVUi();
    // method
    void print();
    void setCookies();
    void request();
    void addItem(QString key, QString text, QString icon);
    
private:
    GWidget* m_workspace;
    QString m_title;
};
//===============================================
#endif
//===============================================
