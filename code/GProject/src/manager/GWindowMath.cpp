//===============================================
#include "GWindowMath.h"
#include "GWidget.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
GWindowMath::GWindowMath(QWidget* parent) :
GWindow(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWindowMath");
	m_tileBar = GWidget::Create("title_bar");
	m_expression = GWidget::Create("line_edit_run");
	m_expression->setLabel("Expression");
	m_variable = GWidget::Create("line_edit");
	m_variable->setLabel("Variables");
	m_textEdit = GWidget::Create("text_edit");

	QVBoxLayout* lBodyLayout = new QVBoxLayout;
	lBodyLayout->setMargin(10);
	lBodyLayout->setSpacing(10);
	lBodyLayout->setAlignment(Qt::AlignTop);
	lBodyLayout->addWidget(m_expression);
	lBodyLayout->addWidget(m_variable);
	lBodyLayout->addWidget(m_textEdit, 1);

	QVBoxLayout* lMainLayout = new QVBoxLayout;
	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(m_tileBar);
	lMainLayout->addLayout(lBodyLayout, 1);

	setLayout(lMainLayout);

	connect(m_expression, SIGNAL(emitRun()), this, SLOT(slotRun()));

	initTileBar("Math | ReadyDev", fa::snowflakeo, "orange");
}
//===============================================
GWindowMath::~GWindowMath() {

}
//===============================================
void GWindowMath::slotRun() {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	QString lExpression = m_expression->getText();
	if(lExpression == "") return;

	QString lExpressionIn;
	QString lExp1, lExp2;

	lExpressionIn = lExpression.remove(QRegExp("\\s"));

	// constantes
	lExpressionIn.replace("E","Math.E");
	lExpressionIn.replace("LN2","Math.LN2");
	lExpressionIn.replace("LN10","Math.LN10");
	lExpressionIn.replace("LOG2E","Math.LOG2E");
	lExpressionIn.replace("PI","Math.PI");
	lExpressionIn.replace("SQRT1_2","Math.SQRT1_2");
	lExpressionIn.replace("SQRT2","Math.SQRT2");
	// fonctions
	lExpressionIn.replace("abs(","Math.abs(");
	lExpressionIn.replace("acos(","Math.acos(");
	lExpressionIn.replace("acosh(","Math.acosh(");
	lExpressionIn.replace("asin(","Math.asin(");
	lExpressionIn.replace("asinh(","Math.abs(");
	lExpressionIn.replace("atan(","Math.atan(");
	lExpressionIn.replace("atanh(","Math.atanh(");
	lExpressionIn.replace("cos(","Math.cos(");
	lExpressionIn.replace("cosh(","Math.cosh(");
	lExpressionIn.replace("exp(","Math.exp(");
	lExpressionIn.replace("log(","Math.log(");
	lExpressionIn.replace("log10(","Math.log10(");
	lExpressionIn.replace("log2(","Math.log2(");
	lExpressionIn.replace("pow(","Math.pow(");
	lExpressionIn.replace("sin(","Math.sin(");
	lExpressionIn.replace("sinh(","Math.sinh(");
	lExpressionIn.replace("sqrt(","Math.sqrt(");
	lExpressionIn.replace("tan(","Math.tan(");
	lExpressionIn.replace("tanh(","Math.tanh(");

	QScriptEngine lScript;
	double lResult = lScript.evaluate(lExpressionIn).toNumber();

	m_textEdit->textEdit()->append(QString("> %1").arg(lExpressionIn));
	m_textEdit->textEdit()->append(QString("= %1").arg(lResult));
	m_textEdit->textEdit()->append("");
}
//===============================================
