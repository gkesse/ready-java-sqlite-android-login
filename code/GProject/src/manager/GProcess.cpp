//===============================================
#include "GProcess.h"
#include "GConfig.h"
#include "GSQLiteUi.h"
#include "GOpenCVUi.h"
#include "GManager.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess() {
    
}
//===============================================
GProcess::~GProcess() {
    
}
//===============================================
GProcess* GProcess::Instance() {
    if(m_instance == 0) {
        m_instance = new GProcess;
    }
    return m_instance;
}
//===============================================
void GProcess::run(int argc, char** argv) {
    G_STATE = "S_INIT";
    while(1) {
        if(G_STATE == "S_INIT") run_INIT(argc, argv);
        else if(G_STATE == "S_METHOD") run_METHOD(argc, argv);
        else if(G_STATE == "S_CHOICE") run_CHOICE(argc, argv);
        //
        else if(G_STATE == "S_SQLITE") run_SQLITE(argc, argv);
        else if(G_STATE == "S_OPENCV") run_OPENCV(argc, argv);
        //
        else if(G_STATE == "S_SAVE") run_SAVE(argc, argv);
        else if(G_STATE == "S_LOAD") run_LOAD(argc, argv);
        else break;
    }
<<<<<<< HEAD
    GManager::Instance()->qtClose();
=======
>>>>>>> 81daa55e0c0df146cdf3dbdfd8b4ee2e4cf327c5
}
//===============================================
void GProcess::run_INIT(int argc, char** argv) {
    printf("\n");
    printf("%s\n", "CPP_ADMIN !!!");
    printf("\t%-2s : %s\n", "-q", "quitter l'application");
    printf("\n");
    G_STATE = "S_LOAD";
}
//===============================================
void GProcess::run_METHOD(int argc, char** argv) {
    printf("%s\n", "CPP_ADMIN :");
    printf("\t%-2s : %s\n", "1", "S_SQLITE");
    printf("\t%-2s : %s\n", "2", "S_OPENCV");

    printf("\n");
    G_STATE = "S_CHOICE";
}
//===============================================
void GProcess::run_CHOICE(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_ADMIN_ID");
    printf("CPP_ADMIN (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    //
    else if(lAnswer == "1") {G_STATE = "S_SQLITE"; GConfig::Instance()->setData("G_ADMIN_ID", lAnswer);} 
    else if(lAnswer == "2") {G_STATE = "S_OPENCV"; GConfig::Instance()->setData("G_ADMIN_ID", lAnswer);}
    //
}
//===============================================
void GProcess::run_SQLITE(int argc, char** argv) {
    GSQLiteUi::Instance()->run(argc, argv);
    G_STATE = "S_SAVE";
}
//===============================================
void GProcess::run_OPENCV(int argc, char** argv) {
    GOpenCVUi::Instance()->run(argc, argv);
    G_STATE = "S_SAVE";
}
//===============================================
void GProcess::run_SAVE(int argc, char** argv) {
    GConfig::Instance()->saveData("G_ADMIN_ID");
    G_STATE = "S_END";
}
//===============================================
void GProcess::run_LOAD(int argc, char** argv) {
    GConfig::Instance()->loadData("G_ADMIN_ID");
    G_STATE = "S_METHOD";
}
//===============================================
