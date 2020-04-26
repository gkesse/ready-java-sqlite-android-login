//================================================
#ifndef _GWindowMath_
#define _GWindowMath_
//================================================
#include "GWindow.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWindowMath : public GWindow {
public:
    GWindowMath(QWidget* parent = 0);
    ~GWindowMath();

protected:
    void closeEvent(QCloseEvent *event);

public slots:
    void slotRun();

private:
    const char* __CLASSNAME__;
    GWidget* m_expression;
    GWidget* m_variable;
    GWidget* m_textEdit;
};
//================================================
#endif
//================================================
#endif
//================================================
