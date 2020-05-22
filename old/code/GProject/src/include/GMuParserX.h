//================================================
#ifndef _GMuParserX_
#define _GMuParserX_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_MUPARSERX_ON_)
//================================================
class GMuParserX {
private:
    GMuParserX();

public:
    ~GMuParserX();
    static GMuParserX* Instance();
    void test(int argc, char** argv);

private:
    const char* __CLASSNAME__;
    static GMuParserX* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
