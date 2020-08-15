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
    std::string lMySQL = "lMySQL";
    GMySQL::Instance()->createConnection(lMySQL);
    GMySQL::Instance()->connect(lMySQL);
    GMySQL::Instance()->showVersion(lMySQL);
    GMySQL::Instance()->deleteConnection(lMySQL);
}
//===============================================
void GMySQL::createConnection(std::string connId) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    mysqlpp::Connection* lConn = new mysqlpp::Connection(false);
    m_connMap[connId] = lConn;
} 
//===============================================
void GMySQL::connect(std::string connId) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    mysqlpp::Connection* lConn = m_connMap[connId];
    lConn->connect(0, 0, 0, 0, 0);
    if(lConn->connected() == false) {std::cout << "erreur connexion mysql\n"; exit(0);}
}
//===============================================
void GMySQL::connect(std::string connId, std::string db, std::string server, std::string user, std::string pass, int port) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    mysqlpp::Connection* lConn = m_connMap[connId];
    lConn->connect(db.c_str(), server.c_str(), user.c_str(), pass.c_str(), port);
    if(lConn->connected() == false) {std::cout << "erreur connexion mysql\n"; exit(0);}
}
//===============================================
void GMySQL::showVersion(std::string connId) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    mysqlpp::Connection* lConn = m_connMap[connId];
    std::cout << lConn->server_version() << "\n";
}
//===============================================
void GMySQL::deleteConnection(std::string connId) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    mysqlpp::Connection* lConn = m_connMap[connId];
    lConn->shutdown();
    delete lConn;
    m_connMap[connId] = 0;
}
//===============================================
#endif
//===============================================
