//================================================
#ifndef _GWidgetLineEditRun_
#define _GWidgetLineEditRun_
//===============================================
#include "GWidget.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWidgetLineEditRun : public GWidget {
public:
    GWidgetLineEditRun(QWidget* parent = 0);
    ~GWidgetLineEditRun();

public:
    void setLabel(QString label);
    QString getText();

private:
    const char* __CLASSNAME__;
    QLabel* m_label;
    QLineEdit* m_lineEidt;
    QPushButton* m_run;
};
//================================================
#endif
//================================================
#endif
//================================================
