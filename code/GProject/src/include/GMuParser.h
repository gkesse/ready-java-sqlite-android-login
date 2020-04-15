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
	void test();
    void add(const char* key, double value);
    double run(const char* expression);

private:
    const char* __CLASSNAME__;
	static GMuParser* m_instance;
	mu::Parser m_parser;
	map<string, double> m_map;
};
//================================================
#endif
//================================================
#endif
//================================================
