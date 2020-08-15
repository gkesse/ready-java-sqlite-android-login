//===============================================
#include "GConfig.h"
//===============================================
GConfig* GConfig::m_instance = 0;
//===============================================
GConfig::GConfig() {
    
}
//===============================================
GConfig::~GConfig() {
    
}
//===============================================
GConfig* GConfig::Instance() {
    if(m_instance == 0) {
        m_instance = new GConfig;
    }
    return m_instance;
}
//===============================================
void GConfig::setData(std::string keyIn, std::string valueIn) {
    m_dataMap[keyIn] = valueIn;
}
//===============================================
std::string GConfig::getData(std::string keyIn) {
    return m_dataMap[keyIn];
}
//===============================================
