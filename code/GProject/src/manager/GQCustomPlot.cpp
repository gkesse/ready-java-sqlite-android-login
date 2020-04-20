//===============================================
#include "GQCustomPlot.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QCUSTOMPLOT_ON_)
//===============================================
GQCustomPlot* GQCustomPlot::m_instance = 0;
//===============================================
GQCustomPlot::GQCustomPlot() {
    __CLASSNAME__ = __FUNCTION__;
    m_plot = 0;
}
//===============================================
GQCustomPlot::~GQCustomPlot() {

}
//===============================================
GQCustomPlot* GQCustomPlot::Instance() {
    if(m_instance == 0) {
        m_instance = new GQCustomPlot;
    }
    return m_instance;
}
//===============================================
void GQCustomPlot::test(int argc, char** argv) {
    QApplication lApp(argc, argv);
    m_plot = new QCustomPlot;
    m_plot->setWindowTitle("QCustomPlot | ReadyDev");
    m_plot->resize(640, 480);
    m_plot->show();
    lApp.exec();
}
//===============================================
#endif
//===============================================
