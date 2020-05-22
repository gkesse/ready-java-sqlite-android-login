//================================================
#ifndef _GMySQL_
#define _GMySQL_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_MYSQL_ON_)
//================================================
class GMySQL {
private:
    GMySQL();

public:
    ~GMySQL();
    static GMySQL* Instance();
    void test(int argc, char** argv);

private:
    const char* __CLASSNAME__;
    static GMySQL* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
