//================================================
#ifndef _GStyle_
#define _GStyle_
//===============================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GStyle {
private:
    GStyle();

public:
    ~GStyle();
    static GStyle* Instance();
    void load(QString filename);

private:
    const char* __CLASSNAME__;
    static GStyle* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
