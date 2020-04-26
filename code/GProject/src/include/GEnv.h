//================================================
#ifndef _GEnv_
#define _GEnv_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_GSL_ON_)
//================================================
class GEnv {
private:
    GEnv();

public:
    ~GEnv();
    static GEnv* Instance();
    void test(int argc, char** argv);
    void setEnv();

private:
    const char* __CLASSNAME__;
    static GEnv* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
