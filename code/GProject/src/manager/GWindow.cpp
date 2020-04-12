//===============================================
#include "GWindow.h"
#include "GWindowMath.h"
#include "GWindowString.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWindow::GWindow(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWindow");
	m_tileBar = 0;
	m_expression = 0;
	m_variable = 0;
	m_textEdit = 0;
	m_sizeGrip = 0;
	m_string = 0;
	m_regExp = 0;
	m_toUpper = 0;
}
//===============================================
GWindow::~GWindow() {

}
//===============================================
GWindow* GWindow::Create(string key) {
	//GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	if(key == "math") return new GWindowMath;
	if(key == "string") return new GWindowString;
	return new GWindowMath;
}
//===============================================
void GWindow::initTileBar(QString title, int picto, const char* color) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
	setWindowTitle(title);
	setWindowIcon(GPicto::Instance()->process("picto_c", picto, color));

	connect(m_tileBar, SIGNAL(emitWindowPress(QPoint)), this, SLOT(slotWindowPress(QPoint)));
	connect(m_tileBar, SIGNAL(emitWindowMove(QPoint)), this, SLOT(slotWindowMove(QPoint)));
	connect(m_tileBar, SIGNAL(emitWindowMinimize()), this, SLOT(slotWindowMinimize()));
	connect(m_tileBar, SIGNAL(emitWindowMaximize()), this, SLOT(slotWindowMaximize()));
	connect(m_tileBar, SIGNAL(emitWindowClose()), this, SLOT(close()));
	connect(m_tileBar, SIGNAL(emitWindowFullScreen()), this, SLOT(slotWindowFullScreen()));

	connect(this, SIGNAL(windowTitleChanged(QString)), m_tileBar, SLOT(slotWindowTitleChange(QString)));
	connect(this, SIGNAL(windowIconChanged(QIcon)), m_tileBar, SLOT(slotWindowIconChange(QIcon)));
	connect(this, SIGNAL(emitWindowMaximize(int, int)), m_tileBar, SLOT(slotWindowMaximize(int, int)));
	connect(this, SIGNAL(emitWindowFullScreen(int, int)), m_tileBar, SLOT(slotWindowFullScreen(int, int)));

	emit windowTitleChanged(windowTitle());
	emit windowIconChanged(windowIcon());

	m_sizeGrip = new QSizeGrip(this);
	//m_pixmapBg.load(":/img/vision.png");
}
//===============================================
void GWindow::paintEvent(QPaintEvent *event) {
	//GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	QPainter lPainter(this);
	lPainter.setPen(QPen(QBrush("teal"), 2));
	lPainter.setBrush(Qt::NoBrush);
	lPainter.drawRect(rect());
	if(m_pixmapBg.isNull()) return;
	int widWidth = width();
	int widHeight = height();
	m_pixmapBg = m_pixmapBg.scaled(widWidth, widHeight, Qt::KeepAspectRatioByExpanding);
	QPoint lCenterWidget = rect().center();
	QRect lRectPixmap = m_pixmapBg.rect();
	lRectPixmap.moveCenter(lCenterWidget);
	lPainter.drawPixmap(lRectPixmap.topLeft(), m_pixmapBg);
}
//===============================================
void GWindow::resizeEvent(QResizeEvent *event) {
	//GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	int lSizeGrip = 10;
	m_sizeGrip->setGeometry(width() - lSizeGrip, height() - lSizeGrip, lSizeGrip, lSizeGrip);
}
//===============================================
void GWindow::closeEvent(QCloseEvent *event) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
}
//===============================================
void GWindow::slotWindowPress(QPoint position) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	m_pressPosition = position - frameGeometry().topLeft();
}
//===============================================
void GWindow::slotWindowMove(QPoint position) {
	//GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	QPoint lMovePosition = position - m_pressPosition;
	move(lMovePosition);
}
//===============================================
void GWindow::slotWindowMinimize() {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	showMinimized();
}
//===============================================
void GWindow::slotWindowMaximize() {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	int lWindowState = windowState();
	if(lWindowState == Qt::WindowMaximized) {
		showNormal();
	}
	else if(lWindowState == Qt::WindowFullScreen) {
		showNormal();
	}
	else {
		showMaximized();
	}
	emit emitWindowMaximize(lWindowState, windowState());
}
//===============================================
void GWindow::slotWindowFullScreen() {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	int lWindowState = windowState();
	if(lWindowState == Qt::WindowFullScreen) {
		showNormal();
	}
	else {
		showFullScreen();
	}
	emit emitWindowFullScreen(lWindowState, windowState());
}
//===============================================
void GWindow::slotRun() {}
void GWindow::slotReplace() {}
void GWindow::slotRegExp() {}
void GWindow::slotToUpper() {}
//===============================================
#endif
//===============================================
