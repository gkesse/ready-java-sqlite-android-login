//================================================
#ifndef _GWidgetPushButton_
#define _GWidgetPushButton_
//===============================================
#include "GWidget.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWidgetPushButton : public GWidget {
public:
    GWidgetPushButton(QWidget* parent = 0);
    ~GWidgetPushButton();

private:
    const char* __CLASSNAME__;
};
//================================================
#endif
//================================================
#endif
//================================================
