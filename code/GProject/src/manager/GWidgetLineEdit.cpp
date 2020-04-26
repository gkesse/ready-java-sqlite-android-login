//===============================================
#include "GWidgetLineEdit.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWidgetLineEdit::GWidgetLineEdit(QWidget* parent) :
GWidget(parent) {
    __CLASSNAME__ = __FUNCTION__;
    setObjectName("GWidgetLineEdit");
    m_label = new QLabel("Label");
    m_label->setObjectName("GLabel");
    m_lineEidt = new QLineEdit;

    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->setMargin(0);
    lMainLayout->addWidget(m_label);
    lMainLayout->addWidget(m_lineEidt, 1);

    setLayout(lMainLayout);
}
//===============================================
GWidgetLineEdit::~GWidgetLineEdit() {

}
//===============================================
void GWidgetLineEdit::setLabel(QString label) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	m_label->setText(label);
}
//===============================================
QString GWidgetLineEdit::getText() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	return m_lineEidt->text();
}
//================================================
#endif
//===============================================
