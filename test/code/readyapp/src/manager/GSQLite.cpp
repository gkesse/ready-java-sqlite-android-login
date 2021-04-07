//===============================================
#include "GSQLite.h"
#include "GManager.h"
//===============================================
GSQLite* GSQLite::m_instance = 0;
//===============================================
typedef struct _sGSQLiteShow sGSQLiteShow;
typedef struct _sGSQLiteData sGSQLiteData;
typedef struct _sGSQLiteList sGSQLiteList;
typedef struct _sGSQLiteMap sGSQLiteMap;
//===============================================
typedef int (*GSQLITE_CALLBACK)(void* params, int colCount, char** colValue, char** colName);
//===============================================
struct _sGSQLiteShow {
    int onHeader;
    int onGrid;
    std::string widthMap;
    int defaultWidth;
    int colCount;
};
//===============================================
struct _sGSQLiteData {
    std::string data;
    int count;
};
//===============================================
struct _sGSQLiteList {
    std::vector<std::string> data;
    int count;
};
//===============================================
struct _sGSQLiteMap {
    std::vector<std::vector<std::string>> data;
    int count;
};
//===============================================
GSQLite::GSQLite() {
    // config_data
    queryWrite(GManager::Instance()->format("\
    create table if not exists config_data (\n\
    config_key text,\n\
    config_value text\n\
    )"));
}
//===============================================
GSQLite::~GSQLite() {
    
}
//===============================================
GSQLite* GSQLite::Instance() {
    if(m_instance == 0) {
        m_instance = new GSQLite;
    }
    return m_instance;
}
//===============================================
void GSQLite::test(int argc, char** argv) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    //
    queryShow(GManager::Instance()->format("\
    select type, name, tbl_name, rootpage\n\
    from sqlite_master\n\
    where type='table'\n\
    "), "5;20;15;10");
    printf("\n");
    //
    std::string lData = queryValue(GManager::Instance()->format("\
    select name\n\
    from sqlite_master\n\
    where type='table'\n\
    "));
    GManager::Instance()->showData(lData);
    printf("\n");
    //
    std::vector<std::string> lCol = queryCol(GManager::Instance()->format("\
    select name\n\
    from sqlite_master\n\
    where type='table'\n\
    "));
    GManager::Instance()->showData(lCol);
    printf("\n");
    //
    std::vector<std::string> lRow = queryRow(GManager::Instance()->format("\
    select type, name, tbl_name, rootpage\n\
    from sqlite_master\n\
    where type='table'\n\
    "));
    GManager::Instance()->showData(lRow);
    printf("\n");
    //
    std::vector<std::vector<std::string>> lMap = queryMap(GManager::Instance()->format("\
    select type, name, tbl_name, rootpage\n\
    from sqlite_master\n\
    where type='table'\n\
    "));
    GManager::Instance()->showData(lMap);
}
//===============================================
void* GSQLite::open() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    sqlite3* lDb;
	int lOk = sqlite3_open(lApp->sqlite_db_path.c_str(), &lDb);
	if(lOk != SQLITE_OK) {printf("[error] GSQLite::open() : %s\n", lApp->sqlite_db_path.c_str());}
    return lDb; 
}
//===============================================
void GSQLite::exec(std::string sqlQuery, void* onExec, void* params) {
	sqlite3* lDb = (sqlite3*)open();
    char* lError;
	int lOk = sqlite3_exec(lDb, sqlQuery.c_str(), (GSQLITE_CALLBACK)onExec, params, &lError);
	if(lOk != SQLITE_OK) {printf("[error] GSQLite::exec() : %s\n", lError);}
    sqlite3_close(lDb);
}
//===============================================
void GSQLite::queryShow(std::string sqlQuery, std::string widthMap, int defaultWidth) {
    sGSQLiteShow lParams = {1, 1, widthMap, defaultWidth, 0};
    exec(sqlQuery, (void*)onQueryShow, &lParams);
    
    if(lParams.colCount > 0) printf("+-");
    for(int i = 0; i < lParams.colCount; i++) {
        if(i != 0) printf("-+-");
        int lWidth = GManager::Instance()->getWidth(widthMap, i, defaultWidth);
        for(int j = 0; j < lWidth; j++) {
            printf("-");
        }
    }
    if(lParams.colCount > 0) printf("-+");
    if(lParams.colCount > 0) printf("\n");
}
//===============================================
void GSQLite::queryWrite(std::string sqlQuery) {
    exec(sqlQuery.c_str(), 0, 0);
}
//===============================================
std::string GSQLite::queryValue(std::string sqlQuery) {
    sGSQLiteData lParams = {"", 0};
    exec(sqlQuery.c_str(), (void*)onQueryValue, &lParams);
    return lParams.data;
}
//===============================================
std::vector<std::string> GSQLite::queryCol(std::string sqlQuery) {
    sGSQLiteList lParams;
    lParams.count = 0;
    exec(sqlQuery.c_str(), (void*)onQueryCol, &lParams);
    return lParams.data;
}
//===============================================
std::vector<std::string> GSQLite::queryRow(std::string sqlQuery) {
    sGSQLiteList lParams;
    lParams.count = 0;
    exec(sqlQuery.c_str(), (void*)onQueryRow, &lParams);
    return lParams.data;
}
//===============================================
std::vector<std::vector<std::string>> GSQLite::queryMap(std::string sqlQuery) {
    sGSQLiteMap lParams;
    lParams.count = 0;
    exec(sqlQuery.c_str(), (void*)onQueryMap, &lParams);
    return lParams.data;
}
//===============================================
int GSQLite::onQueryShow(void* params, int colCount, char** colValue, char** colName) {
	sGSQLiteShow* lParams = (sGSQLiteShow*)params;
    if(lParams->onHeader == 1) {
        printf("+-");
        for(int i = 0; i < colCount; i++) {
            if(i != 0) printf("-+-");
            int lWidth = GManager::Instance()->getWidth(lParams->widthMap, i, lParams->defaultWidth);
            for(int j = 0; j < lWidth; j++) {
                printf("-");
            }
        }
        printf("-+");
        printf("\n");
    }
    if(lParams->onHeader == 1) {
        printf("| ");
        for(int i = 0; i < colCount; i++) {
            if(i != 0) printf(" | ");
            int lWidth = GManager::Instance()->getWidth(lParams->widthMap, i, lParams->defaultWidth);
            printf("%-*s", lWidth, colName[i]);
        }
        printf(" |");
        printf("\n");
    }
    if(lParams->onGrid == 1) {
        printf("+-");
        for(int i = 0; i < colCount; i++) {
            if(i != 0) printf("-+-");
            int lWidth = GManager::Instance()->getWidth(lParams->widthMap, i, lParams->defaultWidth);
            for(int j = 0; j < lWidth; j++) {
                printf("-");
            }
        }
        printf("-+");
        printf("\n");
    } 
    printf("| ");
	for(int i = 0; i < colCount; i++) {
        const char* lColValue = colValue[i] ? colValue[i] : "NULL";
        if(i != 0) printf(" | ");
        int lWidth = GManager::Instance()->getWidth(lParams->widthMap, i, lParams->defaultWidth);
        printf("%-*s", lWidth, lColValue);
    }
    printf(" |");
    printf("\n");
    lParams->onHeader = 0;
    lParams->onGrid = 0;
    lParams->colCount = colCount;
	return 0; 
}
//===============================================
int GSQLite::onQueryValue(void* params, int colCount, char** colValue, char** colName) {
    sGSQLiteData* lParams = (sGSQLiteData*)params;
    if(lParams->count == 0) {
        lParams->data = std::string(colValue[0]);
    }
    lParams->count++;
    return 0;
}
//===============================================
int GSQLite::onQueryCol(void* params, int colCount, char** colValue, char** colName) {
    sGSQLiteList* lParams = (sGSQLiteList*)params;
    const char* lColValue = colValue[0] ? colValue[0] : "NULL";
    lParams->data.push_back(lColValue);
    lParams->count++;
    return 0;
}
//===============================================
int GSQLite::onQueryRow(void* params, int colCount, char** colValue, char** colName) {
    sGSQLiteList* lParams = (sGSQLiteList*)params;
    if(lParams->count == 0) {
        for(int i = 0; i < colCount; i++) {
            const char* lColValue = colValue[i] ? colValue[i] : "NULL";
            lParams->data.push_back(lColValue);
        }
    }
    lParams->count++;
    return 0;
}
//===============================================
int GSQLite::onQueryMap(void* params, int colCount, char** colValue, char** colName) {
    sGSQLiteMap* lParams = (sGSQLiteMap*)params;
    std::vector<std::string> lRow;
    for(int i = 0; i < colCount; i++) {
        const char* lColValue = colValue[i] ? colValue[i] : "NULL";
        lRow.push_back(lColValue);
    }
    lParams->data.push_back(lRow);
    lParams->count++;
    return 0;
}
//===============================================
