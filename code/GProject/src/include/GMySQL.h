//================================================
#ifndef _GMySQL_
#define _GMySQL_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_MYSQL_ON_)
//================================================
class GMySQL {
private:
    GMySQL();

public:
    ~GMySQL();
    static GMySQL* Instance();
    void test(int argc, char** argv);
    void createConnection(std::string connId);
    void connect(std::string connId);
    void connect(std::string connId, std::string db, std::string server, std::string user, std::string pass, int port);
    void showVersion(std::string connId);
    void deleteConnection(std::string connId);

private:
    const char* __CLASSNAME__;
    static GMySQL* m_instance;
    std::map<std::string, mysqlpp::Connection*> m_connMap;
};
//================================================
#endif
//================================================
#endif
//================================================
