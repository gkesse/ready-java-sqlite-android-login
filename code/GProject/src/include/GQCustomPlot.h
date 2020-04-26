//================================================
#ifndef _GQCustomPlot_
#define _GQCustomPlot_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_QCUSTOMPLOT_ON_)
//================================================
class GQCustomPlot : public QObject {
	Q_OBJECT

private:
    GQCustomPlot();

public:
    ~GQCustomPlot();
    static GQCustomPlot* Instance();
    void test(int argc, char** argv);

private:
    void help(int argc, char** argv);
    void testDefault(int argc, char** argv);
    void testQuadratic(int argc, char** argv);
    void testSimple(int argc, char** argv);
    void testSincScatter(int argc, char** argv);
    void testScatterStyle(int argc, char** argv);
    void testLineStyle(int argc, char** argv);
    void testScatterPixmap(int argc, char** argv);
    void testDate(int argc, char** argv);
    void testTextureBrush(int argc, char** argv);
    void testMultiAxis(int argc, char** argv);
    void testLogarithmic(int argc, char** argv);
    void testRealtimeData(int argc, char** argv);
    void testParametricCurve(int argc, char** argv);
    void testBarChart(int argc, char** argv);
    void testStatistical(int argc, char** argv);
    void testSimpleItem(int argc, char** argv);
    void testItem(int argc, char** argv);
    void testStyled(int argc, char** argv);
    void testAdvancedAxes(int argc, char** argv);
    void testColorMap(int argc, char** argv);
    void testFinancial(int argc, char** argv);

public slots:
	void slotRealtimeData();
	void slotBracketData();

private:
    const char* __CLASSNAME__;
    static GQCustomPlot* m_instance;
    QCustomPlot* m_customPlot;
    QCPItemTracer *itemDemoPhaseTracer;

};
//================================================
#endif
//================================================
#endif
//================================================
