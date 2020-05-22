//================================================
#ifndef _GWidgetPlot_
#define _GWidgetPlot_
//===============================================
#include "GWidget.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWidgetPlot : public GWidget {
public:
    GWidgetPlot(QWidget* parent = 0);
    ~GWidgetPlot();

public:
    QCustomPlot* plot();

private:
    const char* __CLASSNAME__;
    QPushButton* m_clear;
    QCustomPlot* m_customPlot;
};
//================================================
#endif
//================================================
#endif
//================================================
