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

    QString lVariable = "";

    if(m_variable->getCheck() == true) {
        lVariable = m_variable->getText();

    }

    char lCommand[256];
    char lOutput[256];
    const char* lExpressionIn = lExpression.toStdString().c_str();
    const char* lVariableIn = lVariable.toStdString().c_str();
    sprintf(lCommand, "gp_muparser muparser \"%s\" %s", lExpressionIn, lVariableIn);
    GShell::Instance()->run(lCommand, lOutput, 255, 0);

    m_textEdit->textEdit()->append(QString("> %1").arg(lExpression));
    m_textEdit->textEdit()->append(QString("= %1").arg(lOutput));
    m_textEdit->textEdit()->append("");
}
//================================================
#endif
//===============================================
