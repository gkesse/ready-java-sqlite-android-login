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
	QScriptEngine lScript;
	if(lExpression == "") return;

	QString expression= lExpression.remove(QRegExp("\\s"));
	QString exp1,exp2;

	expression.replace("pi","Math.PI");
	expression.replace("abs(","Math.abs{");
	expression.replace("sin(","Math.sin{");
	expression.replace("cos(","Math.cos{");
	expression.replace("tan(","Math.tan{");
	//.... and so on for trigonometrical functions)

	expression.replace("sqrt(","Math.sqrt{");
	expression.replace("(","[");
	expression.replace(")","]");
	expression.replace("^","POW");
	expression.replace("+","PLUS");
	expression.replace("-","MINUS");
	expression.replace("*","MULT");
	expression.replace("/","DIV");

	while (expression.contains("[")) //START SOLVING EXPRESSIONS BETWEEN BRACKETS
	{

		QRegularExpression rep("\\[([^\\]]+)\\]");
		QRegularExpressionMatch matchp = rep.match(expression);
		QString expp_w_brackets = matchp.captured(0); //original expression with brakets
		QString expp = matchp.captured(1);//expression without brakets

		while (expp.contains("POW")) //SOLVE POE EXPRESSION
		{
			QRegularExpression re1("(\\d+.\\d+POW)|(\\d+POW)");
			QRegularExpressionMatch match1 = re1.match(expp);

			QRegularExpression re2("(POW\\d+.\\d+)|(POW\\d+)");
			QRegularExpressionMatch match2 = re2.match(expp);

			if (match1.hasMatch())
			{
				exp1 = match1.captured(0);
				exp1.replace("POW","");
			}

			if (match2.hasMatch())
			{
				exp2 = match2.captured(0);
				exp2.replace("POW","");
			}

			expp.replace (""+exp1+"" "POW"""+exp2+"" , "Math.pow(" ""+exp1+"" ","  ""+exp2+""  ")");
		}


		expp.replace ("PLUS","+");
		expp.replace ("MINUS","-");
		expp.replace("MULT","*");
		expp.replace("DIV","/");

		QScriptEngine parsexpressionp;
		double resultp=parsexpressionp.evaluate(expp).toNumber();
		QString BraketResult=(QString::number(resultp));
		expression.replace(""+expp_w_brackets+"" ,""+BraketResult+"");
	}

	while (expression.contains("POW")) //SOLVE POE EXPRESSION
	{
		QRegularExpression re1("(\\d+.\\d+POW)|(\\d+POW)");
		QRegularExpressionMatch match1 = re1.match(expression);

		QRegularExpression re2("(POW\\d+.\\d+)|(POW\\d+)");
		QRegularExpressionMatch match2 = re2.match(expression);


		if (match1.hasMatch())
		{
			exp1 = match1.captured(0);
			exp1.replace("POW","");
		}

		if (match2.hasMatch())
		{
			exp2 = match2.captured(0);
			exp2.replace("POW","");
		}


		expression.replace (""+exp1+"" "POW"""+exp2+"" , "Math.pow(" ""+exp1+"" ","  ""+exp2+""  ")");
	}

	expression.replace("{","(");
	expression.replace("[","(");
	expression.replace("]",")");
	expression.replace ("PLUS","+");
	expression.replace ("MINUS","-");
	expression.replace("MULT","*");
	expression.replace("DIV","/");

	QScriptEngine parsexpression;
	double result=parsexpression.evaluate(expression).toNumber();

	m_textEdit->textEdit()->append(QString("> %1").arg(expression));
	m_textEdit->textEdit()->append(QString("= %1").arg(result));
	m_textEdit->textEdit()->append("");
}
//===============================================
