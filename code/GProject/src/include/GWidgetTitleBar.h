//================================================
#ifndef _GWidgetTitleBar_
#define _GWidgetTitleBar_
//===============================================
#include "GWidget.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWidgetTitleBar : public GWidget {
public:
    GWidgetTitleBar(QWidget* parent = 0);
    ~GWidgetTitleBar();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    const char* __CLASSNAME__;
};
//================================================
#endif
//================================================
#endif
//================================================
