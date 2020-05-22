//===============================================
#include "GMySQL.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_MYSQL_ON_)
//===============================================
GMySQL* GMySQL::m_instance = 0;
//===============================================
GMySQL::GMySQL() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GMySQL::~GMySQL() {

}
//===============================================
GMySQL* GMySQL::Instance() {
	if(m_instance == 0) {
		m_instance = new GMySQL;
	}
	return m_instance;
}
//===============================================
void GMySQL::test(int argc, char** argv) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
#endif
//===============================================
