//================================================
#ifndef _GMuParser_
#define _GMuParser_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_MUPARSER_ON_)
//================================================
class GMuParser {
private:
    GMuParser();

public:
    ~GMuParser();
    static GMuParser* Instance();
    void test(int argc, char** argv);

private:
    const char* __CLASSNAME__;
    static GMuParser* m_instance;
};
//================================================
#endif
//================================================
#endif
//================================================
