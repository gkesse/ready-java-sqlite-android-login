//===============================================
#include "GExprTk.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_EXPRTK_ON_)
//===============================================
GExprTk* GExprTk::m_instance = 0;
//===============================================
GExprTk::GExprTk() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GExprTk::~GExprTk() {

}
//===============================================
GExprTk* GExprTk::Instance() {
	if(m_instance == 0) {
		m_instance = new GExprTk;
	}
	return m_instance;
}
//===============================================
void GExprTk::test() {
	double lResult = run("2^8");
	cout << lResult << "\n";
}
//===============================================
void GExprTk::add(const char* symbol, double value) {
	m_symbol.add_variable(symbol, value);
}
//===============================================
double GExprTk::run(const char* expression) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	string lExpressionIn = expression;
	exprtk::expression<double> lExpression;
	lExpression.register_symbol_table(m_symbol);
	exprtk::parser<double> lParser;
	lParser.compile(lExpressionIn, lExpression);
	double lResult = lExpression.value();
	return lResult;
}
//===============================================
#endif
//===============================================
