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
	m_textEdit = GWidget::Create("text_edit");

	QVBoxLayout* lBodyLayout = new QVBoxLayout;
	lBodyLayout->setMargin(10);
	lBodyLayout->setSpacing(10);
	lBodyLayout->setAlignment(Qt::AlignTop);
	lBodyLayout->addWidget(m_expression);
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

	lExpressionIn.replace("pi","Math.PI");
	lExpressionIn.replace("abs(","Math.abs{");
	lExpressionIn.replace("sin(","Math.sin{");
	lExpressionIn.replace("cos(","Math.cos{");
	lExpressionIn.replace("tan(","Math.tan{");
	//.... and so on for trigonometrical functions)
	lExpressionIn.replace("sqrt(","Math.sqrt{");

	lExpressionIn.replace("(","[");
	lExpressionIn.replace(")","]");
	lExpressionIn.replace("^","POW");
	lExpressionIn.replace("+","PLUS");
	lExpressionIn.replace("-","MINUS");
	lExpressionIn.replace("*","MULT");
	lExpressionIn.replace("/","DIV");

	while (lExpressionIn.contains("[")) {
		QRegularExpression lRegExp("\\[([^\\]]+)\\]");
		QRegularExpressionMatch lMatchExp = lRegExp.match(lExpressionIn);
		QString lOrgExp = lMatchExp.captured(0);
		QString lFindExp = lMatchExp.captured(1);

		while (lFindExp.contains("POW")) {
			QRegularExpression lRegExp1("(\\d+.\\d+POW)|(\\d+POW)");
			QRegularExpressionMatch lMatchExp1 = lRegExp1.match(lFindExp);

			QRegularExpression lRegExp2("(POW\\d+.\\d+)|(POW\\d+)");
			QRegularExpressionMatch lMathcExp2 = lRegExp2.match(lFindExp);

			if(lMatchExp1.hasMatch()) {
				lExp1 = lMatchExp1.captured(0);
				lExp1.replace("POW","");
			}

			if(lMathcExp2.hasMatch()) {
				lExp2 = lMathcExp2.captured(0);
				lExp2.replace("POW","");
			}

			lFindExp.replace (""+lExp1+"" "POW"""+lExp2+"" , "Math.pow(" ""+lExp1+"" ","  ""+lExp2+""  ")");
		}


		lFindExp.replace ("PLUS","+");
		lFindExp.replace ("MINUS","-");
		lFindExp.replace("MULT","*");
		lFindExp.replace("DIV","/");

		QScriptEngine parslExpressionInp;
		double resultp=parslExpressionInp.evaluate(lFindExp).toNumber();
		QString BraketResult=(QString::number(resultp));
		lExpressionIn.replace(""+lOrgExp+"" ,""+BraketResult+"");
	}

	while(lExpressionIn.contains("POW")) {
		QRegularExpression lRegExp1("(\\d+.\\d+POW)|(\\d+POW)");
		QRegularExpressionMatch lMatchExp1 = lRegExp1.match(lExpressionIn);

		QRegularExpression lRegExp2("(POW\\d+.\\d+)|(POW\\d+)");
		QRegularExpressionMatch lMatchExp2 = lRegExp2.match(lExpressionIn);


		if(lMatchExp1.hasMatch()) {
			lExp1 = lMatchExp1.captured(0);
			lExp1.replace("POW","");
		}

		if(lMatchExp2.hasMatch()) {
			lExp2 = lMatchExp2.captured(0);
			lExp2.replace("POW","");
		}

		lExpressionIn.replace (""+lExp1+"" "POW"""+lExp2+"" , "Math.pow(" ""+lExp1+"" ","  ""+lExp2+""  ")");
	}

	lExpressionIn.replace("{","(");
	lExpressionIn.replace("[","(");
	lExpressionIn.replace("]",")");
	lExpressionIn.replace ("PLUS","+");
	lExpressionIn.replace ("MINUS","-");
	lExpressionIn.replace("MULT","*");
	lExpressionIn.replace("DIV","/");

	QScriptEngine lScript;
	double lResult = lScript.evaluate(lExpressionIn).toNumber();

	m_textEdit->textEdit()->append(QString("> %1").arg(lExpression));
	m_textEdit->textEdit()->append(QString("= %1").arg(lResult));
	m_textEdit->textEdit()->append("");
}
//===============================================
