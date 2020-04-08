//===============================================
#include "GWindowMath.h"
#include "GWidget.h"
//===============================================
GWindowMath::GWindowMath(QWidget* parent) :
GWindow(parent) {
	__CLASSNAME__ = __FUNCTION__;
	m_expression = GWidget::Create("line_edit_run");
	m_expression->setLabel("Expression");
	m_textEdit = GWidget::Create("text_edit");

	QVBoxLayout* lMainLayout = new QVBoxLayout;
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(m_expression);
	lMainLayout->addWidget(m_textEdit);

	setLayout(lMainLayout);
	setWindowTitle("Math | ReadyDev");

	connect(m_expression, SIGNAL(emitRun()), this, SLOT(slotRun()));
}
//===============================================
GWindowMath::~GWindowMath() {

}
//===============================================
