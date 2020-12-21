//===============================================
#include "GSQLite.h"
#include "GManager.h"
//===============================================
GSQLite* GSQLite::m_instance = 0;
//===============================================
typedef struct _sGSQLiteShow sGSQLiteShow;
typedef struct _sGSQLiteValue sGSQLiteValue;
typedef struct _sGSQLiteCol sGSQLiteCol;
typedef struct _sGSQLiteRow sGSQLiteRow;
typedef struct _sGSQLiteMap sGSQLiteMap;
//===============================================
struct _sGSQLiteShow {
    int on_header;
    std::string width_map;
    std::string default_width;
    int on_sep;
    int col_count;
};
//===============================================
struct _sGSQLiteValue {
    std::string data;
    int row_count;
    int row;
    int col;
};
//===============================================
struct _sGSQLiteCol {
    std::vector<std::string> data;
    int col;
};
//===============================================
struct _sGSQLiteRow {
    std::vector<std::string> data;
    int row_count;
    int row;
};
//===============================================
struct _sGSQLiteMap {
    std::vector<std::vector<std::string>> data;
};
//===============================================
GSQLite::GSQLite() {

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
sqlite3* GSQLite::connect() {
    sGSQLite* lSqlite = GManager::Instance()->dataGet()->sqlite;
    sqlite3* lDb;
    int lAns = sqlite3_open(lSqlite->db_path.c_str(), &lDb);
    if(lAns != SQLITE_OK) {
        printf("[GSQLite] error connect() : %s\n", sqlite3_errmsg(lDb));
        printf("[GSQLite] %s\n", lSqlite->db_path.c_str());
        exit(0); 
    }
    return lDb;
}
//===============================================
void GSQLite::queryWrite(std::string sql) {
    sqlite3* lDb = connect();
    char* lError;
    int lAns = sqlite3_exec(lDb, sql.c_str(), 0, 0, &lError);
    if(lAns != SQLITE_OK) {
        printf("[GSQLite] error queryWrite() : %s\n", sqlite3_errmsg(lDb));
        sqlite3_free(lError);
        exit(0); 
    }
    sqlite3_close(lDb);
}
//===============================================
void GSQLite::queryShow(std::string sql, int onHeader, std::string widthMap, std::string defaultWidth) {
    sGSQLiteShow lParams = {onHeader, widthMap, defaultWidth, 1, 0};
    sqlite3* lDb = connect();
    char* lError;
    int lAns = sqlite3_exec(lDb, sql.c_str(), onShow, &lParams, &lError);
    if(lAns != SQLITE_OK) {
        printf("[GSQLite] error queryShow() : %s\n", sqlite3_errmsg(lDb));
        sqlite3_free(lError);
        exit(0); 
    }
    sqlite3_close(lDb);
    if(lParams.col_count != 0) {
        printf("+-");
        for(int i = 0; i < lParams.col_count; i++) {
            int lWidth = std::stoi(GManager::Instance()->splitGet(widthMap, ';', i, defaultWidth));
            if(i != 0 ) {printf("-+-");}
            for(int i = 0; i < lWidth; i++) {printf("-");}
        }
        printf("-+");
        printf("\n");
    }
}
//===============================================
std::string GSQLite::queryValue(std::string sql) {
    sGSQLiteValue lParams = {"", 0, 0, 0};
    sqlite3* lDb = connect();
    char* lError;
    int lAns = sqlite3_exec(lDb, sql.c_str(), onValue, &lParams, &lError);
    if(lAns != SQLITE_OK) {
        printf("[GSQLite] error queryValue() : %s\n", sqlite3_errmsg(lDb));
        sqlite3_free(lError);
        exit(0); 
    }
    sqlite3_close(lDb);
    return lParams.data;
}
//===============================================
std::vector<std::string> GSQLite::queryCol(std::string sql) {
    sGSQLiteCol lParams; lParams.col = 0;
    sqlite3* lDb = connect();
    char* lError;
    int lAns = sqlite3_exec(lDb, sql.c_str(), onCol, &lParams, &lError);
    if(lAns != SQLITE_OK) {
        printf("[GSQLite] error queryCol() : %s\n", sqlite3_errmsg(lDb));
        sqlite3_free(lError);
        exit(0); 
    }
    sqlite3_close(lDb);
    return lParams.data;
}
//===============================================
std::vector<std::string> GSQLite::queryRow(std::string sql) {
    sGSQLiteRow lParams; lParams.row_count = 0; lParams.row = 0;
    sqlite3* lDb = connect();
    char* lError;
    int lAns = sqlite3_exec(lDb, sql.c_str(), onRow, &lParams, &lError);
    if(lAns != SQLITE_OK) {
        printf("[GSQLite] error queryRow() : %s\n", sqlite3_errmsg(lDb));
        sqlite3_free(lError);
        exit(0); 
    }
    sqlite3_close(lDb);
    return lParams.data;
}
//===============================================
std::vector<std::vector<std::string>> GSQLite::queryMap(std::string sql) {
    sGSQLiteMap lParams;
    sqlite3* lDb = connect();
    char* lError;
    int lAns = sqlite3_exec(lDb, sql.c_str(), onMap, &lParams, &lError);
    if(lAns != SQLITE_OK) {
        printf("[GSQLite] error queryMap() : %s\n", sqlite3_errmsg(lDb));
        sqlite3_free(lError);
        exit(0); 
    }
    sqlite3_close(lDb);
    return lParams.data;
}
//===============================================
int GSQLite::onShow(void* params, int colCount, char** colValue, char** colName) {
    sGSQLiteShow* lParams = (sGSQLiteShow*)params;
    std::string lWidthMap = lParams->width_map;
    std::string lWidthDefault = lParams->default_width;
    if(lParams->on_header == 1) {
        printf("+-");
        for(int i = 0; i < colCount; i++) {
            int lWidth = std::stoi(GManager::Instance()->splitGet(lWidthMap, ';', i, lWidthDefault));
            if(i != 0 ) {printf("-+-");}
            for(int i = 0; i < lWidth; i++) {printf("-");}
        }
        printf("-+");
        printf("\n");
        printf("| ");
        for(int i = 0; i < colCount; i++) {
            int lWidth = std::stoi(GManager::Instance()->splitGet(lWidthMap, ';', i, lWidthDefault));
            char* lColName = colName[i];
            if(i != 0) {printf(" | ");}
            {printf("%-*s", lWidth, lColName);}
        }
        printf(" |");
        printf("\n");
    }
    if(lParams->on_sep == 1) {
        printf("+-");
        for(int i = 0; i < colCount; i++) {
            int lWidth = std::stoi(GManager::Instance()->splitGet(lWidthMap, ';', i, lWidthDefault));
            if(i != 0 ) {printf("-+-");}
            for(int i = 0; i < lWidth; i++) {printf("-");}
        }
        printf("-+");
        printf("\n");
        lParams->col_count = colCount;
    }
    printf("| ");
    for(int i = 0; i < colCount; i++) {
        int lWidth = std::stoi(GManager::Instance()->splitGet(lWidthMap, ';', i, lWidthDefault));
        const char* lCoValue = colValue[i] ? colValue[i] : "NULL";
        if(i != 0) {printf(" | ");}
        printf("%-*s", lWidth, lCoValue);
    }
    printf(" |");
    printf("\n");
    lParams->on_header = 0;
    lParams->on_sep = 0;
    return 0;
}
//===============================================
int GSQLite::onValue(void* params, int colCount, char** colValue, char** colName) {
    sGSQLiteValue* lParams = (sGSQLiteValue*)params;
    if(lParams->row_count == lParams->row) {
        for(int i = 0; i < colCount; i++) {
            if(i == lParams->col) {
                const char* lCoValue = colValue[i] ? colValue[i] : "NULL";
                lParams->data = lCoValue;
                break;
            }
        }
    }
    lParams->row_count++;
    return 0;
}
//===============================================
int GSQLite::onCol(void* params, int colCount, char** colValue, char** colName) {
    sGSQLiteCol* lParams = (sGSQLiteCol*)params;
    for(int i = 0; i < colCount; i++) {
        if(i == lParams->col) {
            const char* lCoValue = colValue[i] ? colValue[i] : "NULL";
            lParams->data.push_back(lCoValue);
            break;
        }
    }
    return 0;
}
//===============================================
int GSQLite::onRow(void* params, int colCount, char** colValue, char** colName) {
    sGSQLiteRow* lParams = (sGSQLiteRow*)params;
    if(lParams->row_count == lParams->row) {
        for(int i = 0; i < colCount; i++) {
            const char* lCoValue = colValue[i] ? colValue[i] : "NULL";
            lParams->data.push_back(lCoValue);
        }
    }
    lParams->row_count++;
    return 0;
}
//===============================================
int GSQLite::onMap(void* params, int colCount, char** colValue, char** colName) {
    sGSQLiteMap* lParams = (sGSQLiteMap*)params;
    std::vector<std::string> lData;
    for(int i = 0; i < colCount; i++) {
        const char* lCoValue = colValue[i] ? colValue[i] : "NULL";
        lData.push_back(lCoValue);
    }
    lParams->data.push_back(lData);
    return 0;
}
//===============================================
