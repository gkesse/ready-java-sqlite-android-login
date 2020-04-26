//===============================================
#include "GMuParserX.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_MUPARSERX_ON_)
//===============================================
GMuParserX* GMuParserX::m_instance = 0;
//===============================================
GMuParserX::GMuParserX() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GMuParserX::~GMuParserX() {

}
//===============================================
GMuParserX* GMuParserX::Instance() {
    if(m_instance == 0) {
        m_instance = new GMuParserX;
    }
    return m_instance;
}
//===============================================
void GMuParserX::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
	string lExprText = "(x + y)^2";

    mup::ParserX lParser(mup::pckALL_COMPLEX);
	lParser.EnableAutoCreateVar(true);
    lParser.SetExpr(lExprText);

    mup::Value x, y; string z = "";
    lParser.DefineVar("x", mup::Variable(&x));
    lParser.DefineVar("y", mup::Variable(&y));

    x = 3; y = 7;
    z = lParser.Eval().ToString();
    cout << z << "\n";
    x = 15; y = 5;
    z = lParser.Eval().ToString();
    cout << z << "\n";
}
//===============================================
#endif
//===============================================
