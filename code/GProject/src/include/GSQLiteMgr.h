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
    void dbPathSet(std::string dbId, std::string dbPathIn);
    void connect(std::string dbId);
    void close(std::string dbId);
    void exec(std::string dbId, std::string sqlIn, void* onFuncIn, void* paramsIn);
    void queryWrite(std::string dbId, std::string sqlIn);
    void queryShow(std::string dbId, std::string sqlIn, int onHeaderIn, std::string widthMapIn, std::string widthDefaultIn);
    std::string queryValue(std::string dbId, std::string sqlIn);
    std::vector<std::string> queryColumn(std::string dbId, std::string sqlIn);

private:
    static int onShow(void* paramsIn, int colCountIn, char** colValueIn, char** colNameIn);
    static int onValue(void* paramsIn, int colCountIn, char** colValueIn, char** colNameIn);
    static int onColumn(void* paramsIn, int colCountIn, char** colValueIn, char** colNameIn);

public:
    static GSQLiteMgr* m_instance;
    std::map<std::string, std::string> m_dbPathMap;
    std::map<std::string, void*> m_dbMap;
};
//===============================================
#endif
//===============================================
