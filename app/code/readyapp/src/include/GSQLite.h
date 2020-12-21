//===============================================
#ifndef _GSQLite_
#define _GSQLite_
//===============================================
#include "GInclude.h"
//===============================================
class GSQLite {
private:
    GSQLite();
    
public:
    ~GSQLite();
    static GSQLite* Instance();
    sqlite3* connect();
    void queryWrite(std::string sql);
    void queryShow(std::string sql, int onHeader, std::string widthMap, std::string widthDefault);
    std::string queryValue(std::string sql);
    std::vector<std::string> queryCol(std::string sql);
    std::vector<std::string> queryRow(std::string sql);
    std::vector<std::vector<std::string>> queryMap(std::string sql);

private:
    static int onShow(void* params, int colCount, char** colValue, char** colNameIn);
    static int onValue(void* params, int colCount, char** colValue, char** colNameIn);
    static int onCol(void* params, int colCount, char** colValue, char** colNameIn);
    static int onRow(void* params, int colCount, char** colValue, char** colNameIn);
    static int onMap(void* params, int colCount, char** colValue, char** colNameIn);

public:
    static GSQLite* m_instance;
};
//===============================================
#endif
//===============================================
