//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
#include "GWindow.h"
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGOpenCV sGOpenCV;
typedef struct _sGQt sGQt;
typedef struct _sGJson sGJson;
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
    sGOpenCV* opencv;
    sGQt* qt;
    sGJson* json;
};
//===============================================
struct _sGOpenCV {
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
struct _sGQt {
    GWindow* win;
    QStackedWidget* page;
    QMap<QString, int> pageId;
    int pageC;
    pthread_t threadId;
    QString state;
    QString title;
    int width;
    int height;
    int argc;
    char** argv;
};
//===============================================
struct _sGJson {
    std::string file;
};
//===============================================
#endif
//===============================================
