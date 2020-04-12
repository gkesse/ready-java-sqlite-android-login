//================================================
#ifndef _GWindowString_
#define _GWindowString_
//===============================================
#include "GWindow.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWindowString : public GWindow {
public:
	GWindowString(QWidget* parent = 0);
	~GWindowString();

public slots:
	void slotReplace();
	void slotRegExp();
	void slotToUpper();

private:
    const char* __CLASSNAME__;
};
//================================================
#endif
//================================================
#endif
//================================================
