//===============================================
#include "GSQLite.h"
#include "GProcess.h"
#include "GConfig.h"
#include "GSQLiteMgr.h"
//===============================================
GSQLite* GSQLite::m_instance = 0;
//===============================================
GSQLite::GSQLite() {
    
}
//===============================================
GSQLite::~GSQLite() {
    
}
//===============================================
GSQLite* GSQLite::Instance() {
    if(m_instance == 0) {
        m_instance = new GSQLite;
    }
    return m_instance;
}
//===============================================
void GSQLite::run(int argc, char** argv) {
    G_STATE = "S_INIT";
    while(1) {
        if(G_STATE == "S_ADMIN") run_ADMIN(argc, argv);
        else if(G_STATE == "S_INIT") run_INIT(argc, argv);
        else if(G_STATE == "S_METHOD") run_METHOD(argc, argv);
        else if(G_STATE == "S_CHOICE") run_CHOICE(argc, argv);
        //
        else if(G_STATE == "S_CONFIG_LOAD") run_CONFIG_LOAD(argc, argv);
        //
        else if(G_STATE == "S_SAVE") run_SAVE(argc, argv);
        else if(G_STATE == "S_LOAD") run_LOAD(argc, argv);
        else if(G_STATE == "S_QUIT") run_QUIT(argc, argv);
        else break;
    }
}
//===============================================
void GSQLite::run_ADMIN(int argc, char** argv) {
    GProcess::Instance()->run(argc, argv);
    G_STATE = "S_END";
}
//===============================================
void GSQLite::run_INIT(int argc, char** argv) {
    printf("\n");
    printf("%s\n", "CPP_SQLITE !!!");
    printf("\t%-2s : %s\n", "-q", "quitter l'application");
    printf("\t%-2s : %s\n", "-i", "reinitialiser l'application");
    printf("\t%-2s : %s\n", "-a", "redemarrer l'application");
    printf("\t%-2s : %s\n", "-v", "valider les configurations");
    printf("\n");
    G_STATE = "S_LOAD";
}
//===============================================
void GSQLite::run_METHOD(int argc, char** argv) {
    printf("%s\n", "CPP_SQLITE :");
    printf("\t%-2s : %s\n", "1", "S_CONFIG_LOAD");
    printf("\n");
    G_STATE = "S_CHOICE";
}
//===============================================
void GSQLite::run_CHOICE(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("CPP_SQLITE_ID");
    printf("CPP_SQLITE_ID (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    //
    else if(lAnswer == "1") {G_STATE = "S_CONFIG_LOAD"; GConfig::Instance()->setData("CPP_SQLITE_ID", lAnswer);}
}
//===============================================
void GSQLite::run_CONFIG_LOAD(int argc, char** argv) {
    printf("\n");
    GSQLiteMgr::Instance()->queryShow("", ""
    "select *\n"
    "from CONFIG_DATA\n"
    "order by CONFIG_KEY\n"
    "", 1, "20, 50", "20");
    printf("\n");
    G_STATE = "S_SAVE";
}
//===============================================
void GSQLite::run_SAVE(int argc, char** argv) {
    GConfig::Instance()->saveData("CPP_SQLITE_ID");
    G_STATE = "S_QUIT";
}
//===============================================
void GSQLite::run_LOAD(int argc, char** argv) {
    GConfig::Instance()->loadData("CPP_SQLITE_ID");
    G_STATE = "S_METHOD";
}
//===============================================
void GSQLite::run_QUIT(int argc, char** argv) {
    printf("CPP_QUIT (Oui/[N]on) ? : ");
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "o") G_STATE = "S_END";
    else if(lAnswer == "n") G_STATE = "S_INIT";
    else if(lAnswer == "") G_STATE = "S_INIT";
}
//===============================================
