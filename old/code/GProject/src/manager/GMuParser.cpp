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
void GMuParser::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    string lExprText = "(x + y)^2";

    mu::Parser lParser;
    lParser.SetExpr(lExprText);

    double x, y, z;
    lParser.DefineVar("x", &x);
    lParser.DefineVar("y", &y);

    x = 3; y = 7;
    z = lParser.Eval();
    cout << z << "\n";
    x = 15; y = 5;
    z = lParser.Eval();
    cout << z << "\n";
}
//===============================================
#endif
//===============================================
