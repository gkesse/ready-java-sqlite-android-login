//===============================================
#ifndef _GProcessUi_
#define _GProcessUi_
//===============================================
#include "GInclude.h"
//===============================================
class GProcessUi {
private:
    GProcessUi();
    
public:
    ~GProcessUi();
    static GProcessUi* Instance();
    void run(int argc, char** argv);
    
private:
    void run_INIT(int argc, char** argv);
    void run_METHOD(int argc, char** argv);
    void run_CHOICE(int argc, char** argv);
    void run_SAVE(int argc, char** argv);
    void run_LOAD(int argc, char** argv);
    
private:
    void run_SQLITE(int argc, char** argv);
    void run_OPENCV(int argc, char** argv);
    void run_QT(int argc, char** argv);

public:
    static GProcessUi* m_instance;
    std::string G_STATE;
};
//===============================================
#endif
//===============================================
