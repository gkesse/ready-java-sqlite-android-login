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
    double x = 3;
    double y = 7;
    add("x", x);
    add("y", y);
    double lResult = run("x^2 + 2*x*y + y^2");
    cout << lResult << "\n";
}
//===============================================
void GMuParser::add(const char* key, double value) {
    m_map[key] = value;
    m_parser.DefineVar(key, &m_map[key]);
}
//===============================================
double GMuParser::run(const char* expression) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", 0);
    m_parser.SetExpr(expression);
    double lResult = m_parser.Eval();
    return lResult;
}
//===============================================
#endif
//===============================================
