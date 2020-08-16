//===============================================
#ifndef _GSQLiteMgr_
#define _GSQLiteMgr_
//===============================================
#include "GInclude.h"
//===============================================
class GSQLiteMgr {
private:
    GSQLiteMgr();
    
public:
    ~GSQLiteMgr();
    static GSQLiteMgr* Instance();
    void connect(std::string dbId, std::string dbPath);
    void close(std::string dbId);
    void exec(std::string dbId, std::string sql, void* onFunc, void* params);
    void query(std::string sqlQuery = "", void* onFunc = 0, void* params = 0);

private:
    static int onCallback(void* params, int colCount, char** colValue, char** colName);

public:
    static GSQLiteMgr* m_instance;
    std::map<std::string, void*> m_dbMap;
};
//===============================================
#endif
//===============================================
