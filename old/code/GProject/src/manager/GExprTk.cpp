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
void GExprTk::test(int argc, char** argv) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	string lExprText = ""
			"(x - 5)^2";

	GExprTkLib lExprTk;
	lExprTk.setExpr(lExprText);

	double x, y;

	lExprTk.addVariable("x", x);
	lExprTk.setSymbols();
	lExprTk.compile();
	for(x = 1; x < 10; x += 1) {
		y = lExprTk.eval(); cout << "x : " << x << " ; y: " << y << "\n";
	}
}
//===============================================
#endif
//===============================================
