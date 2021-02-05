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
    void request();
    void addItem(QString key, QString text, QString icon);
};
//===============================================
#endif
//===============================================
