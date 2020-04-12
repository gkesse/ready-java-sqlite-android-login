//===============================================
#include "GWidgetTitleBar.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWidgetTitleBar::GWidgetTitleBar(QWidget* parent) :
GWidget(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWidgetTitleBar");
	m_icon = new QLabel("Icon");
	m_icon->setObjectName("GIcon");
	m_title = new QLabel("Title");
	m_title->setObjectName("GTitle");
	m_minimize = new QToolButton;
	m_maximize = new QToolButton;
	m_close = new QToolButton;

	GPicto::Instance()->process("color", "orange");
	m_minimize->setIcon(GPicto::Instance()->process("picto", fa::windowminimize));
	m_maximize->setIcon(GPicto::Instance()->process("picto", fa::windowmaximize));
	m_close->setIcon(GPicto::Instance()->process("picto", fa::close));

	m_minimize->setCursor(Qt::PointingHandCursor);
	m_maximize->setCursor(Qt::PointingHandCursor);
	m_close->setCursor(Qt::PointingHandCursor);

	m_minimize->setIconSize(QSize(18, 18));
	m_maximize->setIconSize(QSize(18, 18));
	m_close->setIconSize(QSize(18, 18));

	QHBoxLayout* lMainLayout = new QHBoxLayout;
	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(m_icon);
	lMainLayout->addWidget(m_title, 1);
	lMainLayout->addWidget(m_minimize);
	lMainLayout->addWidget(m_maximize);
	lMainLayout->addWidget(m_close);

	setLayout(lMainLayout);

	connect(m_minimize, SIGNAL(clicked()), this, SIGNAL(emitWindowMinimize()));
	connect(m_maximize, SIGNAL(clicked()), this, SIGNAL(emitWindowMaximize()));
	connect(m_close, SIGNAL(clicked()), this, SIGNAL(emitWindowClose()));
}
//===============================================
GWidgetTitleBar::~GWidgetTitleBar() {

}
//===============================================
void GWidgetTitleBar::mousePressEvent(QMouseEvent *event) {
	//GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	if(event->button() == Qt::LeftButton) {
		QPoint lPressPosition = event->globalPos();
		emit emitWindowPress(lPressPosition);
	}
	QWidget::mousePressEvent(event);
}
//===============================================
void GWidgetTitleBar::mouseMoveEvent(QMouseEvent *event) {
	//GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	if(event->buttons() & Qt::LeftButton) {
		QPoint lMovePosition = event->globalPos();
		emit emitWindowMove(lMovePosition);
	}
	QWidget::mouseMoveEvent(event);
}
//===============================================
void GWidgetTitleBar::mouseDoubleClickEvent(QMouseEvent *event) {
	//GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	if(event->button() == Qt::LeftButton) {
		emit emitWindowFullScreen();
	}
	QWidget::mouseDoubleClickEvent(event);
}
//================================================
#endif
//===============================================
