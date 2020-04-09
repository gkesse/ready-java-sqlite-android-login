//===============================================
#include "GWidgetLineEditRun.h"
//===============================================
GWidgetLineEditRun::GWidgetLineEditRun(QWidget* parent) :
GWidget(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWidgetLineEditRun");
	m_label = new QLabel("Label");
	m_lineEidt = new QLineEdit;
	m_run = new QPushButton("Run");
	m_run->setCursor(Qt::PointingHandCursor);

	QHBoxLayout* lMainLayout = new QHBoxLayout;
	lMainLayout->setMargin(0);
	lMainLayout->addWidget(m_label);
	lMainLayout->addWidget(m_lineEidt);
	lMainLayout->addWidget(m_run);

	setLayout(lMainLayout);

	connect(m_run, SIGNAL(clicked()), this, SIGNAL(emitRun()));
}
//===============================================
GWidgetLineEditRun::~GWidgetLineEditRun() {

}
//===============================================
