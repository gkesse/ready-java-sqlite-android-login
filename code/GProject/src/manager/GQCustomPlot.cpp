//===============================================
#include "GQCustomPlot.h"
#include "GEnv.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QCUSTOMPLOT_ON_)
//===============================================
GQCustomPlot* GQCustomPlot::m_instance = 0;
//===============================================
GQCustomPlot::GQCustomPlot() {
	__CLASSNAME__ = __FUNCTION__;
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
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	QApplication lApp(argc, argv);
    GEnv::Instance()->setEnv();

	QCustomPlot* lPlot = new QCustomPlot;

	double tMin = -10;
	double tMax = 10;
	int nMax = 101;
	double dT = (tMax - tMin) / (nMax - 1);
	QVector<double> xT(nMax), yT(nMax);

	string lExprText = "x^2";
	GExprTkLib lExprTk;
	double x, y, yMin, yMax;

	lExprTk.setExpr(lExprText);
	lExprTk.addVariable("x", x);
	lExprTk.setSymbols();
	lExprTk.compile();

	for(int i = 0; i < nMax; i++) {
		x = tMin + i*dT;
		y = lExprTk.eval();
		xT[i] = x;
		yT[i] = y;
		if(i == 0) {yMin = y; yMax = y; continue;}
		if(yMin > y) yMin = y;
		if(yMax < y) yMax = y;
	}

	lPlot->addGraph();
	lPlot->graph(0)->setData(xT, yT);
	lPlot->xAxis->setLabel("x");
	lPlot->yAxis->setLabel("y");
	lPlot->xAxis->setRange(tMin, tMax);
	lPlot->yAxis->setRange(yMin, yMax);

	lPlot->setWindowTitle("QCustomPlot | ReadyDev");
	lPlot->resize(640, 480);
	lPlot->show();
	lApp.exec();
}
//===============================================
#endif
//===============================================
