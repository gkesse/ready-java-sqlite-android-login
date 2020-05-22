//================================================
#ifndef _GSoap_
#define _GSoap_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_GSOAP_ON_)
//================================================
class GSoap {
private:
    GSoap();

public:
    ~GSoap();
    static GSoap* Instance();
    void test(int argc, char** argv);

private:
    const char* __CLASSNAME__;
    static GSoap* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
