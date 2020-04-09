//===============================================
#include "GWidgetLineEdit.h"
//===============================================
GWidgetLineEdit::GWidgetLineEdit(QWidget* parent) :
GWidget(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWidgetLineEdit");
	m_label = new QLabel;
	m_lineEidt = new QLineEdit;

	QHBoxLayout* lMainLayout = new QHBoxLayout;
	lMainLayout->addWidget(m_label);
	lMainLayout->addWidget(m_lineEidt);

	setLayout(lMainLayout);
}
//===============================================
GWidgetLineEdit::~GWidgetLineEdit() {

}
//===============================================
