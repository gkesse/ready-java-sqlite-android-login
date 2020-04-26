//===============================================
#include "GWindow.h"
#include "GWindowMath.h"
#include "GWindowMathFunc.h"
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
    m_sizeGrip = 0;
}
//===============================================
GWindow::~GWindow() {

}
//===============================================
GWindow* GWindow::Create(string key) {
    GDebug::Instance()->write("GWindow", "::", __FUNCTION__, "()", _EOA_);
    if(key == "math") return new GWindowMath;
    if(key == "math_func") return new GWindowMathFunc;
    return new GWindowMath;
}
//===============================================
void GWindow::initTileBar(QString title, int picto, const char* color) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    setWindowTitle(title);
    GPicto::Instance()->setColor(color);
    setWindowIcon(GPicto::Instance()->getPicto(picto));
    resize(640, 480);

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
    //GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
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
    //GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    int lSizeGrip = 10;
    m_sizeGrip->setGeometry(width() - lSizeGrip, height() - lSizeGrip, lSizeGrip, lSizeGrip);
}
//===============================================
void GWindow::slotWindowPress(QPoint position) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    m_pressPosition = position - frameGeometry().topLeft();
}
//===============================================
void GWindow::slotWindowMove(QPoint position) {
    //GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    QPoint lMovePosition = position - m_pressPosition;
    move(lMovePosition);
}
//===============================================
void GWindow::slotWindowMinimize() {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    showMinimized();
}
//===============================================
void GWindow::slotWindowMaximize() {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
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
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
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
//===============================================
#endif
//===============================================
