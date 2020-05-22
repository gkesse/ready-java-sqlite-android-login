//================================================
#ifndef _GWindow_
#define _GWindow_
//================================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWindow : public QFrame {
    Q_OBJECT

public:
    GWindow(QWidget* parent = 0);
    virtual ~GWindow();
    static GWindow* Create(string key);
    virtual void initTileBar(QString title, int picto, const char* color);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

public slots:
    virtual void slotWindowPress(QPoint position);
    virtual void slotWindowMove(QPoint position);
    virtual void slotWindowMinimize();
    virtual void slotWindowMaximize();
    virtual void slotWindowFullScreen();
    virtual void slotRun();

signals:
    void emitWindowMaximize(int oldState, int newState);
    void emitWindowFullScreen(int oldState, int newState);

protected:
    const char* __CLASSNAME__;
    GWidget* m_tileBar;
    QPoint m_pressPosition;
    QSizeGrip* m_sizeGrip;
    QPixmap m_pixmapBg;
};
//================================================
#endif
//================================================
#endif
//================================================
