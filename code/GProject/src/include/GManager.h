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
    std::string getSeparator();

public:
    static GManager* m_instance;
};
//===============================================
#endif
//===============================================
