//===============================================
#include "GMuParser.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_MUPARSER_ON_)
//===============================================
GMuParser* GMuParser::m_instance = 0;
//===============================================
GMuParser::GMuParser() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GMuParser::~GMuParser() {

}
//===============================================
GMuParser* GMuParser::Instance() {
	if(m_instance == 0) {
		m_instance = new GMuParser;
	}
	return m_instance;
}
//===============================================
void GMuParser::add(const char* key, double* value) {
	m_parser.DefineVar(key, value);
}
//===============================================
double GMuParser::run(const char* expression) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	m_parser.SetExpr(expression);
	double lResult = m_parser.Eval();
	return lResult;
}
//===============================================
#endif
//===============================================
