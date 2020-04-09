//===============================================
#include "GWidgetTextEdit.h"
//===============================================
GWidgetTextEdit::GWidgetTextEdit(QWidget* parent) :
GWidget(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWidgetTextEdit");
	m_clear = new QPushButton("Clear");
	m_clear->setCursor(Qt::PointingHandCursor);
	m_textEdit = new QTextEdit;
	m_textEdit->setReadOnly(true);

	QHBoxLayout* lTopLayout = new QHBoxLayout;
	lTopLayout->setAlignment(Qt::AlignLeft);
	lTopLayout->setMargin(0);
	lTopLayout->setMargin(0);
	lTopLayout->addWidget(m_clear);

	QVBoxLayout* lMainLayout = new QVBoxLayout;
	lMainLayout->setMargin(0);
	lMainLayout->addLayout(lTopLayout);
	lMainLayout->addWidget(m_textEdit);

	setLayout(lMainLayout);

	connect(m_clear, SIGNAL(clicked()), m_textEdit, SLOT(clear()));
}
//===============================================
GWidgetTextEdit::~GWidgetTextEdit() {

}
//===============================================
