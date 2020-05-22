//===============================================
#include "GConfig.h"
#include "GShow.h"
#include "GDebug.h"
//===============================================
GConfig* GConfig::m_instance = 0;
//===============================================
GConfig::GConfig() {
	__CLASSNAME__ = __FUNCTION__;
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
void GConfig::test(int argc, char** argv) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
void GConfig::setData(std::string key, std::string value) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    m_dataMap[key] = value;
}
//===============================================
std::string GConfig::getData(std::string key) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    return m_dataMap[key];
}
//===============================================
void GConfig::removeData(std::string key) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::map<std::string, std::string>::iterator lItem = m_dataMap.find(key);
    if(lItem != m_dataMap.end()) {
        m_dataMap.erase(lItem);
    }
}
//===============================================
int GConfig::size() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    return m_dataMap.size();
}
//===============================================
void GConfig::showData() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GShow::Instance()->showData(m_dataMap);
}
//===============================================