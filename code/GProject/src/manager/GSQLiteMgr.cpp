//===============================================
#include "GSQLiteMgr.h"
#include "GConfig.h"
#include "GManager.h"
//===============================================
GSQLiteMgr* GSQLiteMgr::m_instance = 0;
//===============================================
typedef int (*GSQLITE_EXEC)(void* params, int colCount, char** colValue, char** colName);
//===============================================
typedef struct _sGSQLiteParams sGSQLiteParams;
//===============================================
struct _sGSQLiteParams {
    int onShow;
    int onHeader;
    std::string widthMap;
    std::string widthDefault;
};
//===============================================
GSQLiteMgr::GSQLiteMgr() {
    GConfig::Instance()->setData("CPP_SQLITE_PATH", "C:\\Users\\Admin\\Downloads\\Programs\\ReadyBin\\win");
    GConfig::Instance()->setData("CPP_SQLITE_NAME", ".config.dat");
}
//===============================================
GSQLiteMgr::~GSQLiteMgr() {
    
}
//===============================================
GSQLiteMgr* GSQLiteMgr::Instance() {
    if(m_instance == 0) {
        m_instance = new GSQLiteMgr;
    }
    return m_instance;
}
//===============================================
void GSQLiteMgr::connect(std::string dbId, std::string dbPath) {
    if(dbId == "") {dbId = "_default_";}
    sqlite3* lDb;
    int lAns = sqlite3_open(dbPath.c_str(), &lDb);
    if(lAns) {
        printf("[GSQLiteMgr] erreur ouverture base de donnees: %s\n", sqlite3_errmsg(lDb));
        exit(0); 
    }
    m_dbMap[dbId] = lDb;
}
//===============================================
void GSQLiteMgr::close(std::string dbId) {
    if(dbId == "") {dbId = "_default_";}
    sqlite3* lDb = (sqlite3*)m_dbMap[dbId];
    sqlite3_close(lDb);
}
//===============================================
void GSQLiteMgr::exec(std::string dbId, std::string sql, void* onFunc, void* params) {
    if(dbId == "") {dbId = "_default_";}
    sqlite3* lDb = (sqlite3*)m_dbMap[dbId];
    char* lErreur;
    int lAns = sqlite3_exec(lDb, sql.c_str(), (GSQLITE_EXEC)onFunc, params, &lErreur);
    if(lAns != SQLITE_OK) {
        printf("[GSQLiteMgr] erreur execution requete: %s\n", sqlite3_errmsg(lDb));
        sqlite3_free(lErreur);
        exit(0); 
    }
}
//===============================================
void GSQLiteMgr::query(std::string sqlQuery, void* onFunc, void* params) {
    std::string lDbPath = "";
    lDbPath += GConfig::Instance()->getData("CPP_SQLITE_PATH");
    lDbPath += GManager::Instance()->separatorGet();
    lDbPath += GConfig::Instance()->getData("CPP_SQLITE_NAME");
    
    sqlite3* lDb;
    int lAns = sqlite3_open(lDbPath.c_str(), &lDb);
    if(lAns) {
        printf("[GSQLiteMgr] erreur ouverture base de donnees: %s\n", sqlite3_errmsg(lDb));
        exit(0); 
    }
    
    std::string lSql = ""
    "select * from CONFIG_DATA\n"
    "";
    
    char* lErreur;
    sGSQLiteParams lParams = {0, 1, "", "50"};   
    lAns = sqlite3_exec(lDb, lSql.c_str(), onCallback, &lParams, &lErreur);
    
    if(lAns != SQLITE_OK) {
        printf("[GSQLiteMgr] erreur execution requete: %s\n", sqlite3_errmsg(lDb));
        sqlite3_free(lErreur);
        exit(0); 
    }
}
//===============================================
int GSQLiteMgr::onCallback(void* params, int colCount, char** colValue, char** colName) {
    sGSQLiteParams* lParams = (sGSQLiteParams*)params;
    std::string lWidthMap = lParams->widthMap;
    std::string lWidthDefault = lParams->widthDefault;
    if(lParams->onHeader == 1) {
        lParams->onHeader = 0;
        for(int i = 0; i < colCount; i++) {
            int lWidth = std::stoi(GManager::Instance()->splitGet(lWidthMap, ';', i, lWidthDefault));
            char* lColName = colName[i];
            if(i != 0 && lParams->onShow == 1) {printf(" | ");}
            if(lParams->onShow == 1) printf("%-*s", lWidth, lColName);
        }
        if(lParams->onShow == 1) printf("\n");
        for(int i = 0; i < colCount; i++) {
            int lWidth = std::stoi(GManager::Instance()->splitGet(lWidthMap, ';', i, lWidthDefault));
            if(i != 0 && lParams->onShow == 1) {printf("-|-");}
            for(int i = 0; i < lWidth; i++) {if(lParams->onShow == 1) {printf("-");}}
        }
        if(lParams->onShow == 1) printf("\n");
    }
    for(int i = 0; i < colCount; i++) {
        int lWidth = std::stoi(GManager::Instance()->splitGet(lWidthMap, ';', i, lWidthDefault));
        const char* lCoValue = colValue[i] ? colValue[i] : "NULL";
        if(i != 0 && lParams->onShow == 1) {printf(" | ");}
        if(lParams->onShow == 1) printf("%-*s", lWidth, lCoValue);
    }
    if(lParams->onShow == 1) printf("\n");
    return 0;
}
//===============================================
