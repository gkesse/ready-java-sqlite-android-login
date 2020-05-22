//================================================
#ifndef _GWidgetLineEditCheck_
#define _GWidgetLineEditCheck_
//===============================================
#include "GWidget.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWidgetLineEditCheck : public GWidget {
public:
    GWidgetLineEditCheck(QWidget* parent = 0);
    ~GWidgetLineEditCheck();

public:
    void setLabel(QString label);
    QString getText();
    bool getCheck();

private:
    const char* __CLASSNAME__;
    QLabel* m_label;
    QLineEdit* m_lineEidt;
    QCheckBox* m_check;
};
//================================================
#endif
//================================================
#endif
//================================================
