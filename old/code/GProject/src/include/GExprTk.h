//================================================
#ifndef _GExprTk_
#define _GExprTk_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_EXPRTK_ON_)
//================================================
class GExprTk {
private:
    GExprTk();

public:
    ~GExprTk();
    static GExprTk* Instance();
    void test(int argc, char** argv);

private:
    const char* __CLASSNAME__;
    static GExprTk* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
