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
    void showData(std::string data);
    void showData(std::vector<std::string> data);
    void showData(std::vector<std::vector<std::string>> data);
    // env
    std::string getEnv(std::string env, std::string defaultValue = "");
    // string
    std::string format(const char* format, ...);
    int getWidth(std::string widthMap, int index, int defaultWidth);
    bool isNumber(const std::string& str);
    std::vector<std::string> split(std::string str, char sep);
    // img
    void loadImage();

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
    // img
    std::string img_path;
    std::map<std::string, std::string> img_paths;
};
//===============================================
#endif
//===============================================