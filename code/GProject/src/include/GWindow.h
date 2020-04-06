//================================================
#ifndef _GWindow_
#define _GWindow_
//================================================
#include "GInclude.h"
//================================================
class GWindow {
public:
	GWindow();
	virtual ~GWindow();
	static GWindow* Create(string key);

private:
    const char* __CLASSNAME__;
};
//================================================
#endif
//================================================
