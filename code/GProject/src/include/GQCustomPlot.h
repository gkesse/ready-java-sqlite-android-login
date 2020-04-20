//================================================
#ifndef _GQCustomPlot_
#define _GQCustomPlot_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_QCUSTOMPLOT_ON_)
//================================================
class GQCustomPlot {
private:
    GQCustomPlot();

public:
    ~GQCustomPlot();
    static GQCustomPlot* Instance();
    void test(int argc, char** argv);

private:
    const char* __CLASSNAME__;
    static GQCustomPlot* m_instance;
    QCustomPlot* m_plot;
};
//================================================
#endif
//================================================
#endif
//================================================
