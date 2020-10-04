//===============================================
#include "GOpenCVUi.h"
#include "GProcess.h"
#include "GConfig.h"
#include "GManager.h"
#include "GOpenCV.h"
//===============================================
GOpenCVUi* GOpenCVUi::m_instance = 0;
//===============================================
GOpenCVUi::GOpenCVUi() {
    
}
//===============================================
GOpenCVUi::~GOpenCVUi() {
    
}
//===============================================
GOpenCVUi* GOpenCVUi::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCVUi;
    }
    return m_instance;
}
//===============================================
void GOpenCVUi::run(int argc, char** argv) {
    G_STATE = "S_INIT";
    while(1) {
        if(G_STATE == "S_ADMIN") run_ADMIN(argc, argv);
        else if(G_STATE == "S_INIT") run_INIT(argc, argv);
        else if(G_STATE == "S_METHOD") run_METHOD(argc, argv);
        else if(G_STATE == "S_CHOICE") run_CHOICE(argc, argv);
        //
        else if(G_STATE == "S_TEST") run_TEST(argc, argv);
        //
        else if(G_STATE == "S_OPEN") run_OPEN(argc, argv);
        else if(G_STATE == "S_CLOSE") run_CLOSE(argc, argv);
        //
        else if(G_STATE == "S_IMAGE_LOAD_IMAGE_PATH") run_IMAGE_LOAD_IMAGE_PATH(argc, argv);
        else if(G_STATE == "S_IMAGE_LOAD_IMAGE_NAME") run_IMAGE_LOAD_IMAGE_NAME(argc, argv);
        else if(G_STATE == "S_IMAGE_LOAD") run_IMAGE_LOAD(argc, argv);
        //
        else if(G_STATE == "S_IMAGE_INVERT_IMAGE_PATH") run_IMAGE_INVERT_IMAGE_PATH(argc, argv);
        else if(G_STATE == "S_IMAGE_INVERT_IMAGE_NAME") run_IMAGE_INVERT_IMAGE_NAME(argc, argv);
        else if(G_STATE == "S_IMAGE_INVERT") run_IMAGE_INVERT(argc, argv);
        //
        else if(G_STATE == "S_VIDEO_LOAD_VIDEO_PATH") run_VIDEO_LOAD_VIDEO_PATH(argc, argv);
        else if(G_STATE == "S_VIDEO_LOAD_VIDEO_NAME") run_VIDEO_LOAD_VIDEO_NAME(argc, argv);
        else if(G_STATE == "S_VIDEO_LOAD") run_VIDEO_LOAD(argc, argv);
        //
        else if(G_STATE == "S_VIDEO_TRACKBAR_VIDEO_PATH") run_VIDEO_TRACKBAR_VIDEO_PATH(argc, argv);
        else if(G_STATE == "S_VIDEO_TRACKBAR_VIDEO_NAME") run_VIDEO_TRACKBAR_VIDEO_NAME(argc, argv);
        else if(G_STATE == "S_VIDEO_TRACKBAR") run_VIDEO_TRACKBAR(argc, argv);
        //
        else if(G_STATE == "S_BASIS") run_BASIS(argc, argv);
        else if(G_STATE == "S_BASIS_POINT") run_BASIS_POINT(argc, argv);
        else if(G_STATE == "S_BASIS_FUNCTION") run_BASIS_FUNCTION(argc, argv);
        //
        else if(G_STATE == "S_SAVE") run_SAVE(argc, argv);
        else if(G_STATE == "S_LOAD") run_LOAD(argc, argv);
        else if(G_STATE == "S_QUIT") run_QUIT(argc, argv);
        else break;
    }
}
//===============================================
void GOpenCVUi::run_ADMIN(int argc, char** argv) {
    GProcess::Instance()->run(argc, argv);
    G_STATE = "S_END";
}
//===============================================
void GOpenCVUi::run_INIT(int argc, char** argv) {
    printf("\n");
    printf("%s\n", "CPP_OPENCV !!!");
    printf("\t%-2s : %s\n", "-q", "quitter l'application");
    printf("\t%-2s : %s\n", "-i", "reinitialiser l'application");
    printf("\t%-2s : %s\n", "-a", "redemarrer l'application");
    printf("\t%-2s : %s\n", "-v", "valider les configurations");
    printf("\n");
    G_STATE = "S_LOAD";
}
//===============================================
void GOpenCVUi::run_METHOD(int argc, char** argv) {
    printf("%s\n", "CPP_OPENCV :");
    printf("\t%-2s : %s\n", "0", "executer un test");
    printf("\n");
    printf("\t%-2s : %s\n", "1", "ouvrir l'application");
    printf("\t%-2s : %s\n", "2", "fermer l'application");
    printf("\t%-2s : %s\n", "3", "S_IMAGE_LOAD");
    printf("\t%-2s : %s\n", "4", "S_IMAGE_INVERT");
    printf("\n");
    printf("\t%-2s : %s\n", "10", "S_VIDEO_LOAD");
    printf("\t%-2s : %s\n", "11", "S_VIDEO_TRACKBAR");
    printf("\n");
    printf("\t%-2s : %s\n", "20", "S_BASIS");
    printf("\t%-2s : %s\n", "21", "S_BASIS_POINT");
    printf("\t%-2s : %s\n", "22", "S_BASIS_FUNCTION");
    printf("\n");
    G_STATE = "S_CHOICE";
}
//===============================================
void GOpenCVUi::run_CHOICE(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_OPENCV_ID");
    printf("CPP_OPENCV (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    //
    else if(lAnswer == "0") {G_STATE = "S_TEST"; GConfig::Instance()->setData("G_OPENCV_ID", lAnswer);}
    //
    else if(lAnswer == "1") {G_STATE = "S_OPEN"; GConfig::Instance()->setData("G_OPENCV_ID", lAnswer);}
    else if(lAnswer == "2") {G_STATE = "S_CLOSE"; GConfig::Instance()->setData("G_OPENCV_ID", lAnswer);}
    else if(lAnswer == "3") {G_STATE = "S_IMAGE_LOAD_IMAGE_PATH"; GConfig::Instance()->setData("G_OPENCV_ID", lAnswer);}
    else if(lAnswer == "4") {G_STATE = "S_IMAGE_INVERT_IMAGE_PATH"; GConfig::Instance()->setData("G_OPENCV_ID", lAnswer);}
    //
    else if(lAnswer == "10") {G_STATE = "S_VIDEO_LOAD_VIDEO_PATH"; GConfig::Instance()->setData("G_OPENCV_ID", lAnswer);}
    else if(lAnswer == "11") {G_STATE = "S_VIDEO_TRACKBAR_VIDEO_PATH"; GConfig::Instance()->setData("G_OPENCV_ID", lAnswer);}
    //
    else if(lAnswer == "20") {G_STATE = "S_BASIS"; GConfig::Instance()->setData("G_OPENCV_ID", lAnswer);}
    else if(lAnswer == "21") {G_STATE = "S_BASIS_POINT"; GConfig::Instance()->setData("G_OPENCV_ID", lAnswer);}
    else if(lAnswer == "22") {G_STATE = "S_BASIS_FUNCTION"; GConfig::Instance()->setData("G_OPENCV_ID", lAnswer);}
    //
}
//===============================================
void GOpenCVUi::run_TEST(int argc, char** argv) {
    printf("\n");
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVUi::run_OPEN(int argc, char** argv) {
    printf("\n");
    sGOpenCV* lOpenCV = GManager::Instance()->dataGet()->opencv;
    if(lOpenCV->state == "close") {
        lOpenCV->run_me = 1;
        GOpenCV::Instance()->open();
        lOpenCV->state = "open";
        printf("[info] ouverture de l'application\n");
    }
    else {
        printf("[error] l'application est deja ouverte\n");
    }
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVUi::run_CLOSE(int argc, char** argv) {
    printf("\n");
    sGOpenCV* lOpenCV = GManager::Instance()->dataGet()->opencv;
    if(lOpenCV->state == "open") {
        lOpenCV->run_me = 0;
        lOpenCV->state = "close";
        printf("[info] fermeture de l'application\n");
    }
    else {
        printf("[error] l'application est deja fermee\n");
    }
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVUi::run_BASIS(int argc, char** argv) {
    printf("\n");
    printf("%s\n", __FUNCTION__);
    GOpenCV::Instance()->basis();
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVUi::run_BASIS_POINT(int argc, char** argv) {
    printf("\n");
    printf("%s\n", __FUNCTION__);
    GOpenCV::Instance()->basisPoint();
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVUi::run_BASIS_FUNCTION(int argc, char** argv) {
    printf("\n");
    printf("%s\n", __FUNCTION__);
    GOpenCV::Instance()->basisFunction();
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVUi::run_IMAGE_LOAD_IMAGE_PATH(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_IMAGE_PATH");
    printf("G_IMAGE_PATH (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_IMAGE_LOAD";
    else if(lAnswer != "") {G_STATE = "S_IMAGE_LOAD_IMAGE_NAME"; GConfig::Instance()->setData("G_IMAGE_PATH", lAnswer);}
}
//===============================================
void GOpenCVUi::run_IMAGE_LOAD_IMAGE_NAME(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_IMAGE_NAME");
    printf("G_IMAGE_NAME (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT"; 
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_IMAGE_LOAD";
    else if(lAnswer != "") {G_STATE = "S_IMAGE_LOAD"; GConfig::Instance()->setData("G_IMAGE_NAME", lAnswer);}
}
//===============================================
void GOpenCVUi::run_IMAGE_LOAD(int argc, char** argv) {
    printf("\n");
    printf("%s\n", __FUNCTION__);
    std::string lImagePath = "";
    lImagePath += GConfig::Instance()->getData("G_IMAGE_PATH");
    lImagePath += GManager::Instance()->separatorGet();
    lImagePath += GConfig::Instance()->getData("G_IMAGE_NAME");
    printf("%s\n", lImagePath.c_str());
    GOpenCV::Instance()->imageLoad(lImagePath);
    printf("\n");
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVUi::run_IMAGE_INVERT_IMAGE_PATH(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_IMAGE_PATH");
    printf("G_IMAGE_PATH (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_IMAGE_INVERT";
    else if(lAnswer != "") {G_STATE = "S_IMAGE_INVERT_IMAGE_NAME"; GConfig::Instance()->setData("G_IMAGE_PATH", lAnswer);}
}
//===============================================
void GOpenCVUi::run_IMAGE_INVERT_IMAGE_NAME(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_IMAGE_NAME");
    printf("G_IMAGE_NAME (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT"; 
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_IMAGE_INVERT";
    else if(lAnswer != "") {G_STATE = "S_IMAGE_INVERT"; GConfig::Instance()->setData("G_IMAGE_NAME", lAnswer);}
}
//===============================================
void GOpenCVUi::run_IMAGE_INVERT(int argc, char** argv) {
    printf("\n");
    printf("%s\n", __FUNCTION__);
    std::string lImagePath = "";
    lImagePath += GConfig::Instance()->getData("G_IMAGE_PATH");
    lImagePath += GManager::Instance()->separatorGet();
    lImagePath += GConfig::Instance()->getData("G_IMAGE_NAME");
    GOpenCV::Instance()->imageInvert(lImagePath);
    printf("\n");
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVUi::run_VIDEO_LOAD_VIDEO_PATH(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_VIDEO_PATH");
    printf("G_VIDEO_PATH (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_VIDEO_LOAD";
    else if(lAnswer != "") {G_STATE = "S_VIDEO_LOAD_VIDEO_NAME"; GConfig::Instance()->setData("G_VIDEO_PATH", lAnswer);}
}
//===============================================
void GOpenCVUi::run_VIDEO_LOAD_VIDEO_NAME(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_VIDEO_NAME");
    printf("G_VIDEO_NAME (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT"; 
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_VIDEO_LOAD";
    else if(lAnswer != "") {G_STATE = "S_VIDEO_LOAD"; GConfig::Instance()->setData("G_VIDEO_NAME", lAnswer);}
}
//===============================================
void GOpenCVUi::run_VIDEO_LOAD(int argc, char** argv) {
    printf("\n");
    printf("%s\n", __FUNCTION__);
    std::string lVideoPath = "";
    lVideoPath += GConfig::Instance()->getData("G_VIDEO_PATH");
    lVideoPath += GManager::Instance()->separatorGet();
    lVideoPath += GConfig::Instance()->getData("G_VIDEO_NAME");
    GOpenCV::Instance()->videoLoad(lVideoPath);
    printf("\n");
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVUi::run_VIDEO_TRACKBAR_VIDEO_PATH(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_VIDEO_PATH");
    printf("G_VIDEO_PATH (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT";
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_VIDEO_TRACKBAR";
    else if(lAnswer != "") {G_STATE = "S_VIDEO_TRACKBAR_VIDEO_NAME"; GConfig::Instance()->setData("G_VIDEO_PATH", lAnswer);}
}
//===============================================
void GOpenCVUi::run_VIDEO_TRACKBAR_VIDEO_NAME(int argc, char** argv) {
    std::string lLast = GConfig::Instance()->getData("G_VIDEO_NAME");
    printf("G_VIDEO_NAME (%s) ? : ", lLast.c_str());
    std::string lAnswer; std::getline(std::cin, lAnswer);
    if(lAnswer == "") lAnswer = lLast;
    if(lAnswer == "-q") G_STATE = "S_END";
    else if(lAnswer == "-i") G_STATE = "S_INIT"; 
    else if(lAnswer == "-a") G_STATE = "S_ADMIN";
    else if(lAnswer == "-v") G_STATE = "S_VIDEO_TRACKBAR";
    else if(lAnswer != "") {G_STATE = "S_VIDEO_TRACKBAR"; GConfig::Instance()->setData("G_VIDEO_NAME", lAnswer);}
}
//===============================================
void GOpenCVUi::run_VIDEO_TRACKBAR(int argc, char** argv) {
    printf("\n");
    printf("%s\n", __FUNCTION__);
    std::string lVideoPath = "";
    lVideoPath += GConfig::Instance()->getData("G_VIDEO_PATH");
    lVideoPath += GManager::Instance()->separatorGet();
    lVideoPath += GConfig::Instance()->getData("G_VIDEO_NAME");
    GOpenCV::Instance()->videoTrackbar("https://www.youtube.com/watch?v=eg1C32wlEbU");
    printf("\n");
    G_STATE = "S_SAVE";
}
//===============================================
void GOpenCVUi::run_SAVE(int argc, char** argv) {
    GConfig::Instance()->saveData("G_OPENCV_ID");
    GConfig::Instance()->saveData("G_IMAGE_PATH");
    GConfig::Instance()->saveData("G_IMAGE_NAME");
    GConfig::Instance()->saveData("G_VIDEO_PATH");
    GConfig::Instance()->saveData("G_VIDEO_NAME");
    G_STATE = "S_QUIT";
}
//===============================================
void GOpenCVUi::run_LOAD(int argc, char** argv) {
    GConfig::Instance()->loadData("G_OPENCV_ID");
    GConfig::Instance()->loadData("G_IMAGE_PATH");
    GConfig::Instance()->loadData("G_IMAGE_NAME");
    GConfig::Instance()->loadData("G_VIDEO_PATH");
    GConfig::Instance()->loadData("G_VIDEO_NAME");
    G_STATE = "S_METHOD";
}
//===============================================
void GOpenCVUi::run_QUIT(int argc, char** argv) {
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
