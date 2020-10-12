//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGOpenCV sGOpenCV;
typedef struct _sGJson sGJson;
typedef struct _sGSQLite sGSQLite;
//===============================================
class GManager {
protected:
    GManager();
    
public:
    virtual ~GManager();
    static GManager* Instance();
    sGManager* dataGet();
    void dataClear();
    std::string separatorGet();
    std::vector<std::string> split(std::string strIn, char sepIn);
    int splitCount(std::string strIn, char sepIn);
    std::string splitGet(std::string strIn, char sepIn, int indexIn, std::string defaultIn);
    std::string dataPath();
    void shell(const char* command, char* output, int size, int shift);
    void system(const char* command);
    void dataShow(std::string data);
    void dataShow(std::vector<std::string> data);
    void dataShow(std::vector<std::vector<std::string>> data);
    
protected:
    sGManager* m_mgr;
};
//===============================================
struct _sGManager {
    sGOpenCV* opencv;
    sGJson* json;
    sGSQLite* sqlite;
};
//===============================================
struct _sGOpenCV {
    std::string app_name;
    std::string title;
    std::string state;
    double width;
    double height;
    cv::Scalar bg_color;
    cv::Mat img;
    double delay;
    int run_me;
#if defined(__unix)
    pthread_t thread_id;
#elif defined(__WIN32)
    DWORD thread_id;
#endif
};
//===============================================
struct _sGJson {
    std::string file;
};
//===============================================
struct _sGSQLite {
    std::string db_path;
};
//===============================================
#endif
//===============================================
