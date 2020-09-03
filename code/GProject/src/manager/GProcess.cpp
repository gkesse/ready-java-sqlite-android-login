//===============================================
#include "GProcess.h"
#include "GConfig.h"
#include "GSQLite.h"
#include "GOpenCV.h"
#include "GOpenCVSys.h"
#include "GQtUi.h"
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
        else if(G_STATE == "S_OPENCV_SYS") run_OPENCV_SYS(argc, argv);
        else if(G_STATE == "S_QT") run_QT(argc, argv);
        //
        else if(G_STATE == "S_SAVE") run_SAVE(argc, argv);
        else if(G_STATE == "S_LOAD") run_LOAD(argc, argv);
        else break;
    }
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
    printf("\t%-2s : %s\n", "3", "S_OPENCV_SYS");
    printf("\t%-2s : %s\n", "4", "S_QT");
    printf("\n");
    G_STATE = "S_CHOICE";
}
//===============================================
void GProcess::run_CHOICE(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("CPP_ADMIN_ID");
    printf("CPP_ADMIN (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    //
    else if(lAnswer == "1") {G_STATE = "S_SQLITE"; GConfig::Instance()->setData("CPP_ADMIN_ID", lAnswer);} 
    else if(lAnswer == "2") {G_STATE = "S_OPENCV"; GConfig::Instance()->setData("CPP_ADMIN_ID", lAnswer);}
    else if(lAnswer == "3") {G_STATE = "S_OPENCV_SYS"; GConfig::Instance()->setData("CPP_ADMIN_ID", lAnswer);}
    else if(lAnswer == "4") {G_STATE = "S_QT"; GConfig::Instance()->setData("CPP_ADMIN_ID", lAnswer);}
    //
}
//===============================================
void GProcess::run_QT(int argc, char** argv) {
    GQtUi::Instance()->run(argc, argv);
    G_STATE = "S_SAVE";
}
//===============================================
void GProcess::run_SQLITE(int argc, char** argv) {
    GSQLite::Instance()->run(argc, argv);
    G_STATE = "S_SAVE";
}
//===============================================
void GProcess::run_OPENCV(int argc, char** argv) {
    GOpenCV::Instance()->run(argc, argv);
    G_STATE = "S_SAVE";
}
//===============================================
void GProcess::run_OPENCV_SYS(int argc, char** argv) {
    GOpenCVSys::Instance()->run(argc, argv);
    G_STATE = "S_SAVE";
}
//===============================================
void GProcess::run_SAVE(int argc, char** argv) {
    GConfig::Instance()->saveData("CPP_ADMIN_ID");
    G_STATE = "S_END";
}
//===============================================
void GProcess::run_LOAD(int argc, char** argv) {
    GConfig::Instance()->loadData("CPP_ADMIN_ID");
    G_STATE = "S_METHOD";
}
//===============================================
