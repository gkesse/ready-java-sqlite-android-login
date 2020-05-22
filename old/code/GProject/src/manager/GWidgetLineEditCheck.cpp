//===============================================
#include "GWidgetLineEditCheck.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWidgetLineEditCheck::GWidgetLineEditCheck(QWidget* parent) :
GWidget(parent) {
    __CLASSNAME__ = __FUNCTION__;
    setObjectName("GWidgetLineEditCheck");
    m_label = new QLabel("Label");
    m_label->setObjectName("GLabel");
    m_lineEidt = new QLineEdit;
    m_check = new QCheckBox;
    m_check->setCursor(Qt::PointingHandCursor);

    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->setMargin(0);
    lMainLayout->addWidget(m_label);
    lMainLayout->addWidget(m_lineEidt, 1);
    lMainLayout->addWidget(m_check);

    setLayout(lMainLayout);

    connect(m_check, SIGNAL(clicked(bool)), this, SLOT(slotCheck(bool)));

    slotCheck(false);
}
//===============================================
GWidgetLineEditCheck::~GWidgetLineEditCheck() {

}
//===============================================
void GWidgetLineEditCheck::setLabel(QString label) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	m_label->setText(label);
}
//===============================================
QString GWidgetLineEditCheck::getText() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	return m_lineEidt->text();
}
//===============================================
bool GWidgetLineEditCheck::getCheck() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	return m_check->isChecked();
}
//================================================
#endif
//===============================================
