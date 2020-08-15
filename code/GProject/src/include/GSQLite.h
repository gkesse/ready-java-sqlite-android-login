//===============================================
#ifndef _GSQLite_
#define _GSQLite_
//===============================================
#include "GInclude.h"
//===============================================
class GSQLite {
private:
    GSQLite();
    
public:
    ~GSQLite();
    static GSQLite* Instance();
    void run(int argc, char** argv);
    
private:
    void run_ADMIN(int argc, char** argv);
    void run_INIT(int argc, char** argv);
    void run_METHOD(int argc, char** argv);
    void run_CHOICE(int argc, char** argv);
    void run_SAVE(int argc, char** argv);
    void run_LOAD(int argc, char** argv);
    void run_QUIT(int argc, char** argv);
    
private:
    void run_CONFIG_LOAD(int argc, char** argv);

public:
    static GSQLite* m_instance;
    std::string G_STATE;
};
//===============================================
#endif
//===============================================
