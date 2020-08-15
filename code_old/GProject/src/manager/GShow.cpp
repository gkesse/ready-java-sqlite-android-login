//===============================================
#include "GShow.h"
#include "GShell.h"
#include "GDebug.h"
//===============================================
GShow* GShow::m_instance = 0;
//===============================================
GShow::GShow() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GShow::~GShow() {

}
//===============================================
GShow* GShow::Instance() {
	if(m_instance == 0) {
		m_instance = new GShow;
	}
	return m_instance;
}
//===============================================
void GShow::test(int argc, char** argv) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
void GShow::showData(std::string data) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::cout << data << "\n";
}
//===============================================
void GShow::showData(int key, ...) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    char lBuffer[512];
    int lIndex = 0;
    va_list lArgs;
    va_start(lArgs, key);
    int lKey = key;
    while(1) {
        if(lKey == 0) break;
        if(lKey == 1) {
            int lData = va_arg(lArgs, int);
            lIndex += sprintf(&lBuffer[lIndex], "%d", lData);
        }
        else if(lKey == 2) {
            double lData = va_arg(lArgs, double);
            lIndex += sprintf(&lBuffer[lIndex], "%f", lData);
        }
        else if(lKey == 3) {
            char* lData = va_arg(lArgs, char*);
            lIndex += sprintf(&lBuffer[lIndex], "%s", lData);
        }
        lKey = va_arg(lArgs, int);
    }
    va_end(lArgs);
    printf("%s\n", lBuffer);
}
//===============================================
void GShow::showData(std::map<std::string, std::string> data) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    for(std::map<std::string, std::string>::iterator lItem = data.begin(); lItem != data.end(); ++lItem) {
        std::cout << lItem->first << " = " << lItem->second << "\n";
    }
}
//===============================================
void GShow::showData(std::vector<std::vector<std::string>> data) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    for(int i = 0; i < data.size(); i++) {
        std::vector<std::string> lDataMap = data.at(i);
        
        for(int j = 0; j < lDataMap.size(); j++) {
            std::string lData = lDataMap.at(j);
            printf("%*s", 20, lData.c_str());
        }
        printf("\n");
    }
}
//===============================================
void GShow::showData(std::vector<std::vector<std::string>*> data) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    for(int i = 0; i < data.size(); i++) {
        std::vector<std::string>* lDataMap = data.at(i);
        
        for(int j = 0; j < lDataMap->size(); j++) {
            std::string lData = lDataMap->at(j);
            printf("%*s", 20, lData.c_str());
        }
        printf("\n");
    }
}
//===============================================
