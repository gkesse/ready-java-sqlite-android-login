//===============================================
#include "GOpenCV.h"
#include "GProcess.h"
#include "GConfig.h"
#include "GManager.h"
//===============================================
GOpenCV* GOpenCV::m_instance = 0;
//===============================================
GOpenCV::GOpenCV() {
    
}
//===============================================
GOpenCV::~GOpenCV() {
    
}
//===============================================
GOpenCV* GOpenCV::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCV;
    }
    return m_instance;
}
//===============================================
void GOpenCV::run(int argc, char** argv) {
    G_STATE = "S_INIT";
    while(1) {
        if(G_STATE == "S_ADMIN") run_ADMIN(argc, argv);
        else if(G_STATE == "S_INIT") run_INIT(argc, argv);
        else if(G_STATE == "S_METHOD") run_METHOD(argc, argv);
        else if(G_STATE == "S_CHOICE") run_CHOICE(argc, argv);
        //
        else if(G_STATE == "S_IMAGE_LOAD_IMAGE_PATH") run_IMAGE_LOAD_IMAGE_PATH(argc, argv);
        else if(G_STATE == "S_IMAGE_LOAD_IMAGE_NAME") run_IMAGE_LOAD_IMAGE_NAME(argc, argv);
        else if(G_STATE == "S_IMAGE_LOAD") run_IMAGE_LOAD(argc, argv);
        //
        else if(G_STATE == "S_VIDEO_LOAD") run_VIDEO_LOAD(argc, argv);
        //
        else if(G_STATE == "S_SAVE") run_SAVE(argc, argv);
        else if(G_STATE == "S_LOAD") run_LOAD(argc, argv);
        else if(G_STATE == "S_QUIT") run_QUIT(argc, argv);
        else break;
    }
}
//===============================================
void GOpenCV::run_ADMIN(int argc, char** argv) {
    GProcess::Instance()->run(argc, argv);
    G_STATE = "S_END";
}
//===============================================
void GOpenCV::run_INIT(int argc, char** argv) {
    printf("\n");
    printf("%s\n", "CPP_OPENCV !!!");
    printf("\t%-2s : %s\n", "-q", "quitter l'application");
    printf("\t%-2s : %s\n", "-i", "reinitialiser l'application");
    printf("\t%-2s : %s\n", "-a", "redemarrer l'application");
    printf("\n");
    G_STATE = "S_LOAD";
}
//===============================================
void GOpenCV::run_METHOD(int argc, char** argv) {
    printf("%s\n", "CPP_OPENCV :");
    printf("\t%-2s : %s\n", "1", "S_IMAGE_LOAD");
    printf("\t%-2s : %s\n", "10", "S_VIDEO_LOAD");
    printf("\n");
    G_STATE = "S_CHOICE";
}
//===============================================
void GOpenCV::run_CHOICE(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("CPP_OPENCV_ID");
    printf("CPP_OPENCV_ID (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    //
    else if(lAnswer == "1") {G_STATE = "S_IMAGE_LOAD_IMAGE_PATH"; GConfig::Instance()->setData("CPP_OPENCV_ID", lAnswer);}
    else if(lAnswer == "10") {G_STATE = "S_VIDEO_LOAD_IMAGE_PATH"; GConfig::Instance()->setData("CPP_OPENCV_ID", lAnswer);}
}
//===============================================
void GOpenCV::run_IMAGE_LOAD_IMAGE_PATH(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("CPP_IMAGE_PATH");
    printf("CPP_IMAGE_PATH (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer != "") {G_STATE = "S_IMAGE_LOAD_IMAGE_NAME"; GConfig::Instance()->setData("CPP_IMAGE_PATH", lAnswer);}
}
//===============================================
void GOpenCV::run_IMAGE_LOAD_IMAGE_NAME(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("CPP_IMAGE_NAME");
    printf("CPP_IMAGE_NAME (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer != "") {G_STATE = "S_IMAGE_LOAD"; GConfig::Instance()->setData("CPP_IMAGE_NAME", lAnswer);}
}
//===============================================
void GOpenCV::run_IMAGE_LOAD(int argc, char** argv) {
    printf("\n");
    std::string lImagePath = "";
    lImagePath += GConfig::Instance()->getData("CPP_IMAGE_PATH");
    lImagePath += GManager::Instance()->getSeparator();
    lImagePath += GConfig::Instance()->getData("CPP_IMAGE_NAME");
    printf("%s\n", lImagePath.c_str());
    printf("\n");
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCV::run_VIDEO_LOAD(int argc, char** argv) {
    printf("\n");
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCV::run_SAVE(int argc, char** argv) {
    G_STATE = "S_QUIT";
}
//===============================================
void GOpenCV::run_LOAD(int argc, char** argv) {
    G_STATE = "S_METHOD";
}
//===============================================
void GOpenCV::run_QUIT(int argc, char** argv) {
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
