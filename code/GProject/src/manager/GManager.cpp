//===============================================
#include "GManager.h"
#include "GManagerUnix.h"
#include "GManagerWin.h"
//===============================================
GManager::GManager() {
    // manager
    m_mgr = new sGManager;
    // opencv
    m_mgr->opencv = new sGOpenCV;
    m_mgr->opencv->app_name = "ReadyApp";
    m_mgr->opencv->title = m_mgr->opencv->app_name;
    m_mgr->opencv->state = "close";
    m_mgr->opencv->width = 640;
    m_mgr->opencv->height = 480;
    m_mgr->opencv->bg_color = cv::Scalar(20, 20, 50);
    m_mgr->opencv->delay = 30;
    m_mgr->opencv->run_me = 1;
    // json
    m_mgr->json = new sGJson;
    m_mgr->json->file = ":/json/menu.json";
    // sqlite
    m_mgr->sqlite = new sGSQLite;
}
//===============================================
GManager::~GManager() {
    
}
//===============================================
GManager* GManager::Instance() {
#if defined(__unix)
    return GManagerUnix::Instance();
#elif defined(__WIN32)
    return GManagerWin::Instance();
#endif
    return 0;
}
//===============================================
sGManager* GManager::dataGet() {
    return m_mgr;
}
//===============================================
void GManager::dataClear() {
    delete m_mgr->opencv;
    delete m_mgr->json;
    delete m_mgr;
}
//===============================================
std::string GManager::separatorGet() {
    std::string lSep = "/";
#if defined(__WIN32)
    lSep = "\\";
#endif
    return lSep;
}
//===============================================
std::vector<std::string> GManager::split(std::string strIn, char sepIn) {
    std::stringstream lStream(strIn);
    std::string lItem;
    std::vector<std::string> lDataMap;
    while (std::getline(lStream, lItem, sepIn)) {
        lDataMap.push_back(lItem);
    }    
    return lDataMap;
}
//===============================================
int GManager::splitCount(std::string strIn, char sepIn) {
    std::stringstream lStream(strIn);
    std::string lItem;
    std::vector<std::string> lDataMap;
    while (std::getline(lStream, lItem, sepIn)) {
        lDataMap.push_back(lItem);
    }    
    return lDataMap.size();
}
//===============================================
std::string GManager::splitGet(std::string strIn, char sepIn, int indexIn, std::string defaultIn) {
    std::stringstream lStream(strIn);
    std::string lItem;
    std::vector<std::string> lDataMap;
    while (std::getline(lStream, lItem, sepIn)) {
        lDataMap.push_back(lItem);
    }   
    int lCount = lDataMap.size();
    std::string lData = defaultIn;
    if(indexIn < lCount) lData = lDataMap[indexIn];
    return lData;
}
//===============================================
std::string GManager::dataPath() {
    return std::string(getenv("GPATH"));
}
//===============================================
void GManager::shell(const char* command, char* output, int size, int shift) {
	FILE* lpFile = popen(command, "r");
	if(output != 0) {
		int lBytes = fread(output, 1, size, lpFile);
		if(lBytes >= 1) {
			output[lBytes] = 0;
			if(shift == 1) output[lBytes - 1] = 0;
		}
	}
	pclose(lpFile);
}
//===============================================
void GManager::system(const char* command) {
    system(command);
}
//===============================================
void GManager::dataShow(std::string data) {
    printf("%s\n", data.c_str());
}
//===============================================
void GManager::dataShow(std::vector<std::string> data) {
    for(int i = 0; i < data.size(); i++) {
        if(i != 0) printf(" ; ");
        std::string lData = data.at(i);
        printf("%s", lData.c_str());
    }
    printf("\n");
}
//===============================================
void GManager::dataShow(std::vector<std::vector<std::string>> data) {
    for(int i = 0; i < data.size(); i++) {
        std::vector<std::string> lDataMap = data.at(i);
        for(int j = 0; j < lDataMap.size(); j++) {
            if(j != 0) printf(" ; ");
            std::string lData = lDataMap.at(j);
            printf("%s", lData.c_str());
        }
        printf("\n");
    }
}
//===============================================
