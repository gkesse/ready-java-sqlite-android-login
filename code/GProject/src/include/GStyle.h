//================================================
#ifndef _GStyle_
#define _GStyle_
//================================================
#include "GInclude.h"
//================================================
class GStyle {
private:
	GStyle();

public:
	~GStyle();
	static GStyle* Instance();
    void process(const char* key, ...);

private:
    void load(QString filename);

private:
    const char* __CLASSNAME__;
	static GStyle* m_instance;
};
//================================================
#endif
//================================================
