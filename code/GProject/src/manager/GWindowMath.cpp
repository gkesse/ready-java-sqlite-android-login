//===============================================
#include "GWindowMath.h"
#include "GWidget.h"
#include "GPicto.h"
#include "GShell.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWindowMath::GWindowMath(QWidget* parent) :
GWindow(parent) {
    __CLASSNAME__ = __FUNCTION__;
    setObjectName("GWindowMath");
    m_tileBar = GWidget::Create("title_bar");
    m_expression = GWidget::Create("line_edit_run");
    m_expression->setLabel("Expression");
    m_variable = GWidget::Create("line_edit_check");
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
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    QString lExpression = m_expression->getText();
    if(lExpression == "") return;

    GExprTkLib lExprTk;
    lExprTk.setExpr(lExpression.toStdString());

    QString lVariable = "";

    if(m_variable->getCheck() == true) {
        lVariable = m_variable->getText();
        QStringList lMap = lVariable.split(" ");
        for(int i = 0; i < lMap.size();) {
        	string lKey = lMap[i++].toStdString();
        	double lValue = lMap[i++].toDouble();
        	lExprTk.addConstant(lKey, lValue);
        }
    }

    lExprTk.setConstants();
    lExprTk.setSymbols();
    lExprTk.compile();

    double lResult = lExprTk.eval();

    m_textEdit->textEdit()->append(QString("> %1").arg(lExpression));
    if(lVariable != "") m_textEdit->textEdit()->append(QString("> %1").arg(lVariable));
    m_textEdit->textEdit()->append(QString("= %1").arg(lResult));
    m_textEdit->textEdit()->append("");
}
//================================================
#endif
//===============================================
