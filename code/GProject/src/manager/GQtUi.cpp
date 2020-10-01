//===============================================
#include "GQtUi.h"
#include "GProcess.h"
#include "GConfig.h"
#include "GManager.h"
#include "GQtMgr.h"
//===============================================
GQtUi* GQtUi::m_instance = 0;
//===============================================
GQtUi::GQtUi() {
    G_SYSTEM = "H_CLOSE";
}
//===============================================
GQtUi::~GQtUi() {
    G_SYSTEM = "H_CLOSE";
}
//===============================================
GQtUi* GQtUi::Instance() {
    if(m_instance == 0) {
        m_instance = new GQtUi;
    }
    return m_instance;
}
//===============================================
void GQtUi::run(int argc, char** argv) {
    G_STATE = "S_INIT";
    while(1) {
        if(G_STATE == "S_ADMIN") run_ADMIN(argc, argv);
        else if(G_STATE == "S_INIT") run_INIT(argc, argv);
        else if(G_STATE == "S_METHOD") run_METHOD(argc, argv);
        else if(G_STATE == "S_CHOICE") run_CHOICE(argc, argv);
        //
        else if(G_STATE == "S_SYSTEM_OPEN") run_SYSTEM_OPEN(argc, argv);
        else if(G_STATE == "S_SYSTEM_CLOSE") run_SYSTEM_CLOSE(argc, argv);
        //
        else if(G_STATE == "S_SAVE") run_SAVE(argc, argv);
        else if(G_STATE == "S_LOAD") run_LOAD(argc, argv);
        else if(G_STATE == "S_QUIT") run_QUIT(argc, argv);
        else break;
    }
}
//===============================================
void GQtUi::run_ADMIN(int argc, char** argv) {
    GProcess::Instance()->run(argc, argv);
    G_STATE = "S_END";
}
//===============================================
void GQtUi::run_INIT(int argc, char** argv) {
    printf("\n");
    printf("%s\n", "CPP_QT !!!");
    printf("\t%-2s : %s\n", "-q", "quitter l'application");
    printf("\t%-2s : %s\n", "-i", "reinitialiser l'application");
    printf("\t%-2s : %s\n", "-a", "redemarrer l'application");
    printf("\t%-2s : %s\n", "-v", "valider les configurations");
    printf("\n");
    G_STATE = "S_LOAD";
}
//===============================================
void GQtUi::run_METHOD(int argc, char** argv) {
    printf("%s\n", "CPP_QT :");
    printf("\t%-2s : %s\n", "1", "S_SYSTEM_OPEN");
    printf("\t%-2s : %s\n", "2", "S_SYSTEM_CLOSE");
    printf("\n");
    G_STATE = "S_CHOICE";
}
//===============================================
void GQtUi::run_CHOICE(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("CPP_QT_ID");
    printf("CPP_QT (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    //
    else if(lAnswer == "1") {G_STATE = "S_SYSTEM_OPEN"; GConfig::Instance()->setData("CPP_QT_ID", lAnswer);}
    else if(lAnswer == "2") {G_STATE = "S_SYSTEM_CLOSE"; GConfig::Instance()->setData("CPP_QT_ID", lAnswer);}
    //
}
//===============================================
void GQtUi::run_SYSTEM_OPEN(int argc, char** argv) {
    printf("\n");
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    if(lQt->state == "H_CLOSE") {
        printf("[info] ouverture du systeme\n");
        lQt->state = "H_OPEN";
        GQtMgr::Instance()->systemOpen(argc, argv);
    }
    else {
        printf("[attention] impossible d'ouvrir le systeme\n");
        printf("[attention] le systeme est deja ouvert\n");
    }
    G_STATE = "S_SAVE";
}
//===============================================
void GQtUi::run_SYSTEM_CLOSE(int argc, char** argv) {
    printf("\n");
    sGManager* lMgr = GManager::Instance()->dataGet();
    sGQt* lQt = lMgr->qt;
    if(lQt->state == "H_OPEN") {
        printf("[info] fermeture du systeme\n");
        lQt->state = "H_CLOSE";
        GQtMgr::Instance()->systemClose();
    }
    else {
        printf("[attention] impossible de fermer le systeme\n");
        printf("[attention] le systeme est deja ferme\n");
    }
    G_STATE = "S_SAVE";
}
//===============================================
void GQtUi::run_SAVE(int argc, char** argv) {
    GConfig::Instance()->saveData("CPP_QT_ID");
    G_STATE = "S_QUIT";
}
//===============================================
void GQtUi::run_LOAD(int argc, char** argv) {
    GConfig::Instance()->loadData("CPP_QT_ID");
    G_STATE = "S_METHOD";
}
//===============================================
void GQtUi::run_QUIT(int argc, char** argv) {
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
