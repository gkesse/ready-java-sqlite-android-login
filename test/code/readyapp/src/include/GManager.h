//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGApp sGApp;
//===============================================
// manager
//===============================================
class GManager {    
private:
    GManager();
    
public:
    ~GManager();
    static GManager* Instance();
    // data
    sGManager* getData();
    // env
    std::string getEnv(std::string env);
    // string
    std::string format(const char* format, ...);
    int getWidth(std::string widthMap, int index, int defaultWidth);
    bool isNumber(const std::string& str);
    std::vector<std::string> split(std::string str, std::string sep);

private:
    static GManager* m_instance;
    sGManager* mgr;
};
//===============================================
// struct
//===============================================
struct _sGManager {
    sGApp* app;
};
//===============================================
struct _sGApp {
    // app
    std::string app_name;
    // sqlite
    std::string sqlite_db_path;
};
//===============================================
#endif
//===============================================