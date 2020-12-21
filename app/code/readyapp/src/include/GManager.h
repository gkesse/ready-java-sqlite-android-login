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
typedef struct _sGImage sGImage;
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
    sGImage* img;
    sGJson* json;
    sGSQLite* sqlite;
};
//===============================================
struct _sGOpenCV {
    std::string app_name;
    std::string title;
    std::string state;
    int width;
    int height;
    cv::Scalar bg_color;
    cv::Mat img;
    int delay;
    int run_me;
#if defined(__unix)
    pthread_t thread_id;
#elif defined(__WIN32)
    DWORD thread_id;
#endif
};
//===============================================
struct _sGImage {
    std::string img_file;
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
