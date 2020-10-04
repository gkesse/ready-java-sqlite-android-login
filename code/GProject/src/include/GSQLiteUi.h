//===============================================
#ifndef _GSQLiteUi_
#define _GSQLiteUi_
//===============================================
#include "GInclude.h"
//===============================================
class GSQLiteUi {
private:
    GSQLiteUi();
    
public:
    ~GSQLiteUi();
    static GSQLiteUi* Instance();
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
    void run_TEST(int argc, char** argv);
    void run_TABLES_SHOW(int argc, char** argv);
    void run_CONFIG_CPP_CREATE(int argc, char** argv);
    void run_CONFIG_CPP_SHOW(int argc, char** argv);
    //
    void run_CONFIG_CPP_DELETE_CONFIG_KEY(int argc, char** argv);
    void run_CONFIG_CPP_DELETE(int argc, char** argv);
    //

public:
    static GSQLiteUi* m_instance;
    std::string G_STATE;
};
//===============================================
#endif
//===============================================
