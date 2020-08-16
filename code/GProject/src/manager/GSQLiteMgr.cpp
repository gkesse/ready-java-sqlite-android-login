//===============================================
#include "GSQLiteMgr.h"
#include "GConfig.h"
#include "GManager.h"
//===============================================
#if defined (__WIN32) 
#define CPP_SQLITE_PATH "C:\\Users\\Admin\\Downloads\\Programs\\ReadyBin\\win"
#elif defined (__WIN32) 
#define CPP_SQLITE_PATH "C:\\Users\\Admin\\Downloads\\Programs\\ReadyBin\\win"
#endif
//===============================================
GSQLiteMgr* GSQLiteMgr::m_instance = 0;
//===============================================
typedef int (*GSQLITE_EXEC)(void* paramsIn, int colCountIn, char** colValueIn, char** colNameIn);
//===============================================
typedef struct _sGSQLiteShow sGSQLiteShow;
typedef struct _sGSQLiteValue sGSQLiteValue;
typedef struct _sGSQLiteList sGSQLiteList;
//===============================================
struct _sGSQLiteShow {
    int onHeader;
    std::string widthMap;
    std::string widthDefault;
};
//===============================================
struct _sGSQLiteValue {
    int onFlag;
    std::string data;
};
//===============================================
struct _sGSQLiteList {
    std::vector<std::string> data;
};
//===============================================
GSQLiteMgr::GSQLiteMgr() {
    GConfig::Instance()->setData("CPP_SQLITE_PATH", CPP_SQLITE_PATH);
    GConfig::Instance()->setData("CPP_SQLITE_NAME", ".config.dat");
    std::string lDbPath = "";
    lDbPath += GConfig::Instance()->getData("CPP_SQLITE_PATH");
    lDbPath += GManager::Instance()->separatorGet();
    lDbPath += GConfig::Instance()->getData("CPP_SQLITE_NAME");
    dbPathSet("", lDbPath);
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
void GSQLiteMgr::dbPathSet(std::string dbId, std::string dbPathIn) {
    if(dbId == "") {dbId = "_default_";}
    m_dbPathMap[dbId] = dbPathIn;
}
//===============================================
void GSQLiteMgr::connect(std::string dbId) {
    if(dbId == "") {dbId = "_default_";}
    std::string lDbPath = m_dbPathMap[dbId];
    sqlite3* lDb;
    int lAns = sqlite3_open(lDbPath.c_str(), &lDb);
    if(lAns) {
        printf("[GSQLiteMgr] erreur ouverture base de donnees: %s\n", sqlite3_errmsg(lDb));
        printf("[GSQLiteMgr] %s\n", lDbPath.c_str());
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
void GSQLiteMgr::exec(std::string dbId, std::string sqlIn, void* onFuncIn, void* paramsIn) {
    if(dbId == "") {dbId = "_default_";}
    sqlite3* lDb = (sqlite3*)m_dbMap[dbId];
    char* lError;
    int lAns = sqlite3_exec(lDb, sqlIn.c_str(), (GSQLITE_EXEC)onFuncIn, paramsIn, &lError);
    if(lAns != SQLITE_OK) {
        printf("[GSQLiteMgr] erreur execution requete: %s\n", sqlite3_errmsg(lDb));
        sqlite3_free(lError);
        exit(0); 
    }
}
//===============================================
void GSQLiteMgr::queryWrite(std::string dbId, std::string sqlIn) {
    connect(dbId);
    exec(dbId, sqlIn, 0, 0);
    close(dbId);
}
//===============================================
void GSQLiteMgr::queryShow(std::string dbId, std::string sqlIn, int onHeaderIn, std::string widthMapIn, std::string widthDefaultIn) {
    connect(dbId);
    sGSQLiteShow lParams = {onHeaderIn, widthMapIn, widthDefaultIn};
    exec(dbId, sqlIn, (void*)onShow, &lParams);
    close(dbId);
}
//===============================================
std::string GSQLiteMgr::queryValue(std::string dbId, std::string sqlIn) {
    connect(dbId);
    sGSQLiteValue lParams = {1, ""};
    exec(dbId, sqlIn, (void*)onValue, &lParams);
    close(dbId);
    return lParams.data;
}
//===============================================
std::vector<std::string> GSQLiteMgr::queryColumn(std::string dbId, std::string sqlIn) {
    connect(dbId);
    sGSQLiteList lParams;
    exec(dbId, sqlIn, (void*)onColumn, &lParams);
    close(dbId);
    return lParams.data;
}
//===============================================
int GSQLiteMgr::onShow(void* paramsIn, int colCountIn, char** colValueIn, char** colNameIn) {
    sGSQLiteShow* lParams = (sGSQLiteShow*)paramsIn;
    std::string lWidthMap = lParams->widthMap;
    std::string lWidthDefault = lParams->widthDefault;
    if(lParams->onHeader == 1) {
        lParams->onHeader = 0;
        for(int i = 0; i < colCountIn; i++) {
            int lWidth = std::stoi(GManager::Instance()->splitGet(lWidthMap, ';', i, lWidthDefault));
            char* lColName = colNameIn[i];
            if(i != 0) {printf(" | ");}
            {printf("%-*s", lWidth, lColName);}
        }
        printf("\n");
        for(int i = 0; i < colCountIn; i++) {
            int lWidth = std::stoi(GManager::Instance()->splitGet(lWidthMap, ';', i, lWidthDefault));
            if(i != 0 ) {printf("-|-");}
            for(int i = 0; i < lWidth; i++) {printf("-");}
        }
        printf("\n");
    }
    for(int i = 0; i < colCountIn; i++) {
        int lWidth = std::stoi(GManager::Instance()->splitGet(lWidthMap, ';', i, lWidthDefault));
        const char* lCoValue = colValueIn[i] ? colValueIn[i] : "NULL";
        if(i != 0) {printf(" | ");}
        printf("%-*s", lWidth, lCoValue);
    }
    printf("\n");
    return 0;
}
//===============================================
int GSQLiteMgr::onValue(void* paramsIn, int colCountIn, char** colValueIn, char** colNameIn) {
    sGSQLiteValue* lParams = (sGSQLiteValue*)paramsIn;
    if(lParams->onFlag == 1) {
        lParams->onFlag = 0;
        const char* lCoValue = colValueIn[0] ? colValueIn[0] : "NULL";
        lParams->data = lCoValue;
    }
    return 0;
}
//===============================================
int GSQLiteMgr::onColumn(void* paramsIn, int colCountIn, char** colValueIn, char** colNameIn) {
    sGSQLiteList* lParams = (sGSQLiteList*)paramsIn;
    const char* lCoValue = colValueIn[0] ? colValueIn[0] : "NULL";
    lParams->data.push_back(lCoValue);
    return 0;
}
//===============================================
