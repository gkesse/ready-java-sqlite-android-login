//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGApp sGApp;
//===============================================
class GManager {
private:
    GManager();
    
public:
    virtual ~GManager();
    static GManager* Instance();
    // data
    sGManager* getData();
    // env
    std::string getEnv(std::string key);
    void loadEnv();
    // string
    std::vector<std::string> split(std::string str, char sep);
    std::map<std::string, std::string> splitMap(std::string str, char sepRow, char sepCol);
    std::string removeLast(std::string str, char remove) ;
    // map
    std::string getValue(std::map<std::string, std::string> mapId, std::string key, std::string defaultValue);
    
private:
    static GManager* m_instance;
    sGManager* mgr;
};
//===============================================
struct _sGManager {
    sGApp* app;
};
//===============================================
struct _sGApp {
    // app
    std::string app_name;
    std::string app_title;
    // logo
    std::string logo_path;
    // style
    std::string style_path;
    // font
    std::string font_path;
    // icon
    std::string icon_path;
    // page
    std::string page_id;
    std::string page_last;
    // query
    std::string query_string;
    std::map<std::string, std::string> query_map;
    // query
    std::string cookie_string;
    std::map<std::string, std::string> cookie_map;
};
//===============================================
#endif
//===============================================
