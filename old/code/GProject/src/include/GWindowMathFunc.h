//================================================
#ifndef _GWindowMathFunc_
#define _GWindowMathFunc_
//================================================
#include "GWindow.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWindowMathFunc : public GWindow {
public:
    GWindowMathFunc(QWidget* parent = 0);
    ~GWindowMathFunc();

protected:
    void closeEvent(QCloseEvent *event);

public slots:
    void slotRun();

private:
    const char* __CLASSNAME__;
    GWidget* m_expression;
    GWidget* m_variable;
    GWidget* m_plot;
};
//================================================
#endif
//================================================
#endif
//================================================
