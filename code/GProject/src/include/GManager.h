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
    
public:
    static GManager* m_instance;
};
//===============================================
#endif
//===============================================
