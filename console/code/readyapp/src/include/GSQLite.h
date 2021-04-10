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
    void test(int argc, char** argv);
    //
    void* open();
    void exec(std::string sqlQuery, void* onExec, void* params);
    void queryShow(std::string sqlQuery, std::string widthMap = "", int defaultWidth = 20);
    void queryWrite(std::string sqlQuery);
    //
    std::string queryValue(std::string sqlQuery);
    std::vector<std::string> queryCol(std::string sqlQuery);
    std::vector<std::string> queryRow(std::string sqlQuery);
    std::vector<std::vector<std::string>> queryMap(std::string sqlQuery);
    //
    static int onQueryShow(void* params, int colCount, char** colValue, char** colName);
    static int onQueryValue(void* params, int colCount, char** colValue, char** colName);
    static int onQueryCol(void* params, int colCount, char** colValue, char** colName);
    static int onQueryRow(void* params, int colCount, char** colValue, char** colName);
    static int onQueryMap(void* params, int colCount, char** colValue, char** colName);

private:
    static GSQLite* m_instance;
};
//===============================================
#endif
//===============================================