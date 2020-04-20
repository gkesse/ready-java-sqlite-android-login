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

public slots:
    void slotRun();

private:
    const char* __CLASSNAME__;
};
//================================================
#endif
//================================================
#endif
//================================================
