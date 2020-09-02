//===============================================
#include "GOpenCVSys.h"
#include "GProcess.h"
#include "GConfig.h"
#include "GManager.h"
#include "GOpenCVSysMgr.h"
//===============================================
GOpenCVSys* GOpenCVSys::m_instance = 0;
//===============================================
GOpenCVSys::GOpenCVSys() {
    G_SYSTEM = "H_CLOSE";
}
//===============================================
GOpenCVSys::~GOpenCVSys() {
    G_SYSTEM = "H_CLOSE";
}
//===============================================
GOpenCVSys* GOpenCVSys::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCVSys;
    }
    return m_instance;
}
//===============================================
void GOpenCVSys::run(int argc, char** argv) {
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
        else if(G_STATE == "S_IMAGE_LOAD_IMAGE_PATH") run_IMAGE_LOAD_IMAGE_PATH(argc, argv);
        else if(G_STATE == "S_IMAGE_LOAD_IMAGE_NAME") run_IMAGE_LOAD_IMAGE_NAME(argc, argv);
        else if(G_STATE == "S_IMAGE_LOAD") run_IMAGE_LOAD(argc, argv);
        //
        else if(G_STATE == "S_SAVE") run_SAVE(argc, argv);
        else if(G_STATE == "S_LOAD") run_LOAD(argc, argv);
        else if(G_STATE == "S_QUIT") run_QUIT(argc, argv);
        else break;
    }
}
//===============================================
void GOpenCVSys::run_ADMIN(int argc, char** argv) {
    GProcess::Instance()->run(argc, argv);
    G_STATE = "S_END";
}
//===============================================
void GOpenCVSys::run_INIT(int argc, char** argv) {
    printf("\n");
    printf("%s\n", "CPP_OPENCV_SYS !!!");
    printf("\t%-2s : %s\n", "-q", "quitter l'application");
    printf("\t%-2s : %s\n", "-i", "reinitialiser l'application");
    printf("\t%-2s : %s\n", "-a", "redemarrer l'application");
    printf("\t%-2s : %s\n", "-v", "valider les configurations");
    printf("\n");
    G_STATE = "S_LOAD";
}
//===============================================
void GOpenCVSys::run_METHOD(int argc, char** argv) {
    printf("%s\n", "CPP_OPENCV_SYS :");
    printf("\t%-2s : %s\n", "1", "S_SYSTEM_OPEN");
    printf("\t%-2s : %s\n", "2", "S_SYSTEM_CLOSE");
    printf("\n");
    printf("\t%-2s : %s\n", "10", "S_IMAGE_LOAD");
    printf("\n");
    G_STATE = "S_CHOICE";
}
//===============================================
void GOpenCVSys::run_CHOICE(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("CPP_OPENCV_SYS_ID");
    printf("CPP_OPENCV_SYS (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    //
    else if(lAnswer == "1") {G_STATE = "S_SYSTEM_OPEN"; GConfig::Instance()->setData("CPP_OPENCV_SYS_ID", lAnswer);}
    else if(lAnswer == "2") {G_STATE = "S_SYSTEM_CLOSE"; GConfig::Instance()->setData("CPP_OPENCV_SYS_ID", lAnswer);}
    //
    else if(lAnswer == "10") {G_STATE = "S_IMAGE_LOAD_IMAGE_PATH"; GConfig::Instance()->setData("CPP_OPENCV_SYS_ID", lAnswer);}
    //
}
//===============================================
void GOpenCVSys::run_IMAGE_LOAD_IMAGE_PATH(int argc, char** argv) {
    if(G_SYSTEM == "H_CLOSE") {
        printf("\n");
        printf("[attention] impossible de charger une image\n");
        printf("[attention] le systeme est ferme\n");
        G_STATE = "S_SAVE"; 
        return;
    }
    std::string lLast = GConfig::Instance()->getData("CPP_IMAGE_PATH");
    printf("CPP_IMAGE_PATH (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_IMAGE_LOAD";
    else if(lAnswer != "") {G_STATE = "S_IMAGE_LOAD_IMAGE_NAME"; GConfig::Instance()->setData("CPP_IMAGE_PATH", lAnswer);}
}
//===============================================
void GOpenCVSys::run_IMAGE_LOAD_IMAGE_NAME(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("CPP_IMAGE_NAME");
    printf("CPP_IMAGE_NAME (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT"; 
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_IMAGE_LOAD";
    else if(lAnswer != "") {G_STATE = "S_IMAGE_LOAD"; GConfig::Instance()->setData("CPP_IMAGE_NAME", lAnswer);}
}
//===============================================
void GOpenCVSys::run_IMAGE_LOAD(int argc, char** argv) {
    printf("\n");
    std::string lImagePath = "";
    lImagePath += GConfig::Instance()->getData("CPP_IMAGE_PATH");
    lImagePath += GManager::Instance()->separatorGet();
    lImagePath += GConfig::Instance()->getData("CPP_IMAGE_NAME");
    printf("[info] chargement d'une image\n");
    printf("[info] %s\n", lImagePath.c_str());
    GOpenCVSysMgr::Instance()->imageLoad(lImagePath);
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVSys::run_SYSTEM_OPEN(int argc, char** argv) {
    printf("\n");
    if(G_SYSTEM == "H_CLOSE") {
        printf("[info] ouverture du systeme\n");
        GOpenCVSysMgr::Instance()->systemOpen();
        G_SYSTEM = "H_OPEN";
    }
    else {
        printf("[attention] impossible d'ouvrir le systeme\n");
        printf("[attention] le systeme est deja ouvert\n");
    }
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVSys::run_SYSTEM_CLOSE(int argc, char** argv) {
    printf("\n");
    if(G_SYSTEM == "H_OPEN") {
        printf("[info] fermeture du systeme\n");
        GOpenCVSysMgr::Instance()->systemClose();
        G_SYSTEM = "H_CLOSE";
    }
    else {
        printf("[attention] impossible de fermer le systeme\n");
        printf("[attention] le systeme est deja ferme\n");
    }
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVSys::run_SAVE(int argc, char** argv) {
    GConfig::Instance()->saveData("CPP_OPENCV_SYS_ID");
    GConfig::Instance()->saveData("CPP_IMAGE_PATH");
    GConfig::Instance()->saveData("CPP_IMAGE_NAME");
    GConfig::Instance()->saveData("CPP_VIDEO_PATH");
    GConfig::Instance()->saveData("CPP_VIDEO_NAME");
    G_STATE = "S_QUIT";
}
//===============================================
void GOpenCVSys::run_LOAD(int argc, char** argv) {
    GConfig::Instance()->loadData("CPP_OPENCV_SYS_ID");
    GConfig::Instance()->loadData("CPP_IMAGE_PATH");
    GConfig::Instance()->loadData("CPP_IMAGE_NAME");
    GConfig::Instance()->loadData("CPP_VIDEO_PATH");
    GConfig::Instance()->loadData("CPP_VIDEO_NAME");
    G_STATE = "S_METHOD";
}
//===============================================
void GOpenCVSys::run_QUIT(int argc, char** argv) {
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
