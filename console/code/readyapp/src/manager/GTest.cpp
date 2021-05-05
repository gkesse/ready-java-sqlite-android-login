//===============================================
#include "GTest.h"
#include "GManager.h"
//===============================================
GTest* GTest::m_instance = 0;
//===============================================
GTest::GTest() {
    
}
//===============================================
GTest::~GTest() {
    
}
//===============================================
GTest* GTest::Instance() {
    if(m_instance == 0) {
        m_instance = new GTest;
    }
    return m_instance;
}
//===============================================
void GTest::run(int argc, char** argv) {
    // on definit les arguments en ligne de commande
    // syntaxe  : "{arg_1}{...}{arg_i}{...}{arg_n}"
    // arg_i    : nom_i | defaut_i | desc_i
    // nom_i    : mot_i (pour argument long) ou lettre_i (pour argument court)
    // defaut_i : valeur par defaut_i (peut etre vide)
    // desc_i   : description (peut etre vide)
    // nom_i    : argument obligatoire si (@nom_i)
    // nom_i    : argument optionnel   si (nom_i)
    const cv::String lKeys =
    "{help h usage ? |      | affichier le message d'aide }"
    "{@image1        |      | definir l'image 1 pour la comparaison }"
    "{@image2        |<none>| definir l'image 2 pour la comparaison }"
    "{@repeat        |1     | definir le nombre de repetitions }"
    "{path           |.     | definir le repertoire du fichier de sortie }"
    "{fps            |25    | definir le fps pour la video de sortie }"
    "{N count        |100   | definir le nombre d'objets a compter }"
    "{ts timestamp   |      | utiliser le timestamp }"
    ;
    
    // on cree l'analyseur de ligne de commande
    cv::CommandLineParser lParser(argc, argv, lKeys);
    // on definit la description de l'application
    lParser.about("ReayApp v1.0.0");
    
    // on verifie la presence de l'option (help)
    if (lParser.has("help")) {
        // on affiche le message d'aide si l'option (help) est present
        lParser.printMessage(); 
        return;
    }
    
    // on recupere le nombre d'objets (N : entier)
    int N = lParser.get<int>("N");
    // on recupere le fps (fps : reel)
    double fps = lParser.get<double>("fps");
    // on recupere le chemin du repertoire de sortie (path : chaine)
    cv::String path = lParser.get<cv::String>("path");
    // on recupere l'utilisation du timestamp (ts : booleen)
    bool use_time_stamp = lParser.has("timestamp");
    // on recupere le chemin de l'image 1 (image1 : chaine)
    cv::String img1 = lParser.get<cv::String>(0);
    // on recupere le chemin de l'image 2 (image2 : chaine)
    cv::String img2 = lParser.get<cv::String>(1);
    // on recupere le nombre de repetitions (repeat : entier)
    int repeat = lParser.get<int>(2);
    
    //on affiche les arguments
    printf("%-40s : %d\n", "Nombre d'objets[N]", N);
    printf("%-40s : %f\n", "Nombre d'image par seconde[fps]", fps);
    printf("%-40s : %s\n", "Repertoire de sortie [path]", path.c_str());
    printf("%-40s : %d\n", "Utilisation du timestamp [ts]", use_time_stamp);
    printf("%-40s : %s\n", "Image 1 [image1]", img1.c_str());
    printf("%-40s : %s\n", "Image 2 [image2]", img2.c_str());
    printf("%-40s : %d\n", "Nombre de repetition [repeat]", repeat);
    
    // on verifie l'analyseur
    if (!lParser.check()){
        // on afficheur le message d'erreur s'il y a erreur
        lParser.printErrors();
        return;
    }
}
//===============================================
