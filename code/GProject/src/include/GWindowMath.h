//================================================
#ifndef _GWindowMath_
#define _GWindowMath_
//================================================
#include "GWindow.h"
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
