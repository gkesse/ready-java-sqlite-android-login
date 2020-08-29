//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
//===============================================
class GManager {
private:
    GManager();
    
public:
    ~GManager();
    static GManager* Instance();
    std::string separatorGet();
    std::vector<std::string> split(std::string strIn, char sepIn);
    int splitCount(std::string strIn, char sepIn);
    std::string splitGet(std::string strIn, char sepIn, int indexIn, std::string defaultIn);
    std::string dataPath();
    void shell(const char* command, char* output, int size, int shift);
    void system(const char* command);
    
public:
    static GManager* m_instance;
};
//===============================================
#endif
//===============================================
