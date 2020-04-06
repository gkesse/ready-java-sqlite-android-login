//================================================
#ifndef _GWindow_
#define _GWindow_
//================================================
#include "GInclude.h"
//================================================
class GWindow : public QWidget {
public:
	GWindow(QWidget* parent = 0);
	virtual ~GWindow();
	static GWindow* Create(string key);

private:
    const char* __CLASSNAME__;
};
//================================================
#endif
//================================================
