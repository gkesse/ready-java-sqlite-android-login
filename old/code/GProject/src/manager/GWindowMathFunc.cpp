//===============================================
#include "GWindowMathFunc.h"
#include "GWidget.h"
#include "GPicto.h"
#include "GShell.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWindowMathFunc::GWindowMathFunc(QWidget* parent) :
GWindow(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWindowMathFunc");
	m_tileBar = GWidget::Create("title_bar");

	m_expression = GWidget::Create("line_edit_run");
	m_expression->setLabel("Fonction");
	m_variable = GWidget::Create("line_edit");
	m_variable->setLabel("Variables");
	m_plot = GWidget::Create("plot");

	QVBoxLayout* lBodyLayout = new QVBoxLayout;
	lBodyLayout->setMargin(10);
	lBodyLayout->setSpacing(10);
	lBodyLayout->setAlignment(Qt::AlignTop);
	lBodyLayout->addWidget(m_expression);
	lBodyLayout->addWidget(m_variable);
	lBodyLayout->addWidget(m_plot, 1);

	QVBoxLayout* lMainLayout = new QVBoxLayout;
	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(m_tileBar);

	lMainLayout->addLayout(lBodyLayout, 1);

	setLayout(lMainLayout);

	connect(m_expression, SIGNAL(emitRun()), this, SLOT(slotRun()));

	initTileBar("MathFunc | ReadyDev", fa::snowflakeo, "orange");
}
//===============================================
GWindowMathFunc::~GWindowMathFunc() {

}
//===============================================
void GWindowMathFunc::closeEvent(QCloseEvent *event) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
void GWindowMathFunc::slotRun() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    QString lExpression = m_expression->getText();
    if(lExpression == "") return;

	double tMin = -5;
	double tMax = 5;
	int nMax = 101;

    QString lVariable = m_variable->getText();
	if(lVariable == "") return;
	QStringList lMap = lVariable.split(" ");
	tMin = lMap[0].toDouble();
	tMax = lMap[1].toDouble();
	nMax = lMap[2].toDouble();

	double dT = (tMax - tMin) / (nMax - 1);
	QVector<double> xT(nMax), yT(nMax);

	GExprTkLib lExprTk;
	double x, y, yMin, yMax;

    lExprTk.setExpr(lExpression.toStdString());
	lExprTk.addVariable("x", x);
    lExprTk.setConstants();
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

	m_plot->plot()->addGraph();
	m_plot->plot()->graph(0)->setData(xT, yT);
	m_plot->plot()->xAxis->setLabel("x");
	m_plot->plot()->yAxis->setLabel("y");
	m_plot->plot()->xAxis->setRange(tMin, tMax);
	m_plot->plot()->yAxis->setRange(yMin, yMax);
	m_plot->plot()->replot();
}
//================================================
#endif
//===============================================
