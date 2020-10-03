//===============================================
#include "GManager.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
GManager::GManager() {
    // manager
    m_mgr = new sGManager;
    // opencv
    m_mgr->opencv = new sGOpenCV;
    m_mgr->opencv->title = "MainWindow | OpenCV";
    m_mgr->opencv->width = 640;
    m_mgr->opencv->height = 480;
    m_mgr->opencv->bgColor = cv::Scalar(50, 100, 150);
    m_mgr->opencv->delay = 30;
    m_mgr->opencv->runMe = 1;
    // qt
    m_mgr->qt = new sGQt;
    m_mgr->qt->title = "MainWindow | Qt";
    m_mgr->qt->state = "H_CLOSE";
    m_mgr->qt->width = 640;
    m_mgr->qt->height = 480;
    m_mgr->qt->pageC = 0;
    m_mgr->qt->win = 0;    
    // json
    m_mgr->json = new sGJson;
    m_mgr->json->file = ":/json/menu.json";
}
//===============================================
GManager::~GManager() {
    
}
//===============================================
GManager* GManager::Instance() {
    if(m_instance == 0) {
        m_instance = new GManager;
    }
    return m_instance;
}
//===============================================
sGManager* GManager::dataGet() {
    return m_mgr;
}
//===============================================
void GManager::dataClear() {
    printf("[info] liberation de la memoire des donnees\n");
    delete m_mgr->opencv;
    delete m_mgr->qt;
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
void GManager::qtClose() {
    if(m_mgr->qt->win != 0) {
        m_mgr->qt->win->close();
    }
}
//===============================================
