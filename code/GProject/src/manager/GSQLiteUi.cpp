//===============================================
#include "GSQLiteUi.h"
#include "GProcess.h"
#include "GConfig.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
#define B_QUERY (256)
//===============================================
GSQLiteUi* GSQLiteUi::m_instance = 0;
//===============================================
GSQLiteUi::GSQLiteUi() {
    
}
//===============================================
GSQLiteUi::~GSQLiteUi() {
    
}
//===============================================
GSQLiteUi* GSQLiteUi::Instance() {
    if(m_instance == 0) {
        m_instance = new GSQLiteUi;
    }
    return m_instance;
}
//===============================================
void GSQLiteUi::run(int argc, char** argv) {
    G_STATE = "S_INIT";
    while(1) {
        if(G_STATE == "S_ADMIN") run_ADMIN(argc, argv);
        else if(G_STATE == "S_INIT") run_INIT(argc, argv);
        else if(G_STATE == "S_METHOD") run_METHOD(argc, argv);
        else if(G_STATE == "S_CHOICE") run_CHOICE(argc, argv);
        //
        else if(G_STATE == "S_TEST") run_TEST(argc, argv);
        else if(G_STATE == "S_TABLES_SHOW") run_TABLES_SHOW(argc, argv);
        else if(G_STATE == "S_CONFIG_CPP_CREATE") run_CONFIG_CPP_CREATE(argc, argv);
        else if(G_STATE == "S_CONFIG_CPP_SHOW") run_CONFIG_CPP_SHOW(argc, argv);
        //
        else if(G_STATE == "S_CONFIG_CPP_DELETE_CONFIG_KEY") run_CONFIG_CPP_DELETE_CONFIG_KEY(argc, argv);
        else if(G_STATE == "S_CONFIG_CPP_DELETE") run_CONFIG_CPP_DELETE(argc, argv);
        //
        else if(G_STATE == "S_SAVE") run_SAVE(argc, argv);
        else if(G_STATE == "S_LOAD") run_LOAD(argc, argv);
        else if(G_STATE == "S_QUIT") run_QUIT(argc, argv);
        else break;
    }
}
//===============================================
void GSQLiteUi::run_ADMIN(int argc, char** argv) {
    GProcess::Instance()->run(argc, argv);
    G_STATE = "S_END";
}
//===============================================
void GSQLiteUi::run_INIT(int argc, char** argv) {
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
void GSQLiteUi::run_METHOD(int argc, char** argv) {
    printf("%s\n", "CPP_SQLITE :");
    printf("\t%-2s : %s\n", "0", "executer un test");
    printf("\t%-2s : %s\n", "1", "afficher les tables");
    printf("\t%-2s : %s\n", "2", "creer la table CONFIG_CPP");
    printf("\t%-2s : %s\n", "3", "afficher la table CONFIG_CPP");
    printf("\t%-2s : %s\n", "4", "supprimer une donnee CONFIG_CPP");
    printf("\n");
    G_STATE = "S_CHOICE";
}
//===============================================
void GSQLiteUi::run_CHOICE(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_SQLITE_ID");
    printf("CPP_SQLITE (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    //
    else if(lAnswer == "0") {G_STATE = "S_TEST"; GConfig::Instance()->setData("G_SQLITE_ID", lAnswer);}
    else if(lAnswer == "1") {G_STATE = "S_TABLES_SHOW"; GConfig::Instance()->setData("G_SQLITE_ID", lAnswer);}
    else if(lAnswer == "2") {G_STATE = "S_CONFIG_CPP_CREATE"; GConfig::Instance()->setData("G_SQLITE_ID", lAnswer);}
    else if(lAnswer == "3") {G_STATE = "S_CONFIG_CPP_SHOW"; GConfig::Instance()->setData("G_SQLITE_ID", lAnswer);}
    else if(lAnswer == "4") {G_STATE = "S_CONFIG_CPP_DELETE_CONFIG_KEY"; GConfig::Instance()->setData("G_SQLITE_ID", lAnswer);}
}
//===============================================
void GSQLiteUi::run_TEST(int argc, char** argv) {
    printf("\n");
    GSQLite::Instance()->queryWrite("\
    drop table CONFIG_CPP \
    ");
    G_STATE = "S_SAVE";
}
//===============================================
void GSQLiteUi::run_TABLES_SHOW(int argc, char** argv) {
    printf("\n");
    GSQLite::Instance()->queryShow("\
    select name from sqlite_master \
    WHERE type='table' \
    ", 1, "30", "20");
    G_STATE = "S_SAVE";
}
//===============================================
void GSQLiteUi::run_CONFIG_CPP_CREATE(int argc, char** argv) {
    printf("\n");
    GSQLite::Instance()->queryWrite("\
    create table CONFIG_CPP ( \
    CONFIG_KEY text unique not null, \
    CONFIG_VALUE text\
    )\
    ");
    G_STATE = "S_SAVE";
}
//===============================================
void GSQLiteUi::run_CONFIG_CPP_SHOW(int argc, char** argv) {
    printf("\n");
    GSQLite::Instance()->queryShow("\
    select * from CONFIG_CPP \
    order by CONFIG_KEY \
    ", 1, "20;30", "20");
    G_STATE = "S_SAVE";
}
//===============================================
void GSQLiteUi::run_CONFIG_CPP_DELETE_CONFIG_KEY(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_CONFIG_KEY");
    printf("G_CONFIG_KEY (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT"; 
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_CONFIG_CPP_DELETE";
    else if(lAnswer != "") {G_STATE = "S_CONFIG_CPP_DELETE"; GConfig::Instance()->setData("G_CONFIG_KEY", lAnswer);}
}
//===============================================
void GSQLiteUi::run_CONFIG_CPP_DELETE(int argc, char** argv) {
    char lQuery[B_QUERY+1];
    const char* lConfigKey = GConfig::Instance()->getData("G_CONFIG_KEY").c_str();
    
    sprintf(lQuery, "\
    delete from CONFIG_CPP \
    where CONFIG_KEY = '%s' \
    ", lConfigKey);

    GSQLite::Instance()->queryWrite(lQuery);
    G_STATE = "S_CONFIG_CPP_SHOW";
}
//===============================================
void GSQLiteUi::run_SAVE(int argc, char** argv) {
    GConfig::Instance()->saveData("G_SQLITE_ID");
    GConfig::Instance()->saveData("G_CONFIG_KEY");
    G_STATE = "S_QUIT";
}
//===============================================
void GSQLiteUi::run_LOAD(int argc, char** argv) {
    GConfig::Instance()->loadData("G_SQLITE_ID");
    GConfig::Instance()->loadData("G_CONFIG_KEY");
    G_STATE = "S_METHOD";
}
//===============================================
void GSQLiteUi::run_QUIT(int argc, char** argv) {
    printf("\n");
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
