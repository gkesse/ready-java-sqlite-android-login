//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGWindow sGWindow;
//===============================================
class GManager {
private:
    GManager();
    
public:
    ~GManager();
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
    
public:
    static GManager* m_instance;
    sGManager* m_mgr;
};
//===============================================
struct _sGManager {
    sGWindow* win;
};
//===============================================
struct _sGWindow {
    std::string title;
    double width;
    double height;
    pthread_t threadId;
    cv::Scalar bgColor;
    cv::Mat img;
    double delay;
    int runMe;
};
//===============================================
#endif
//===============================================
