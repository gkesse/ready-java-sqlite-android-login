//===============================================
#include "GCsv.h"
#include "GShow.h"
#include "GDebug.h"
//===============================================
GCsv* GCsv::m_instance = 0;
//===============================================
GCsv::GCsv() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GCsv::~GCsv() {

}
//===============================================
GCsv* GCsv::Instance() {
	if(m_instance == 0) {
		m_instance = new GCsv;
	}
	return m_instance;
}
//===============================================
void GCsv::test(int argc, char** argv) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
void GCsv::addRow() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    m_itemMap = new std::vector<std::string>;
    m_dataMap.push_back(m_itemMap);
}
//===============================================
void GCsv::addData(std::string data) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    m_itemMap->push_back(data);
}
//===============================================
void GCsv::setData(int row, int col, std::string data) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::vector<std::string>* lItemMap = m_dataMap.at(row);
    lItemMap->at(col) = data;
}
//===============================================
std::string GCsv::getData(int row, int col) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::vector<std::string>* lItemMap = m_dataMap.at(row);
    std::string lData = lItemMap->at(col);
    return lData;
}
//===============================================
void GCsv::removeData(int row) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::vector<std::string>* lItemMap = m_dataMap.at(row);
    lItemMap->clear();
    delete lItemMap;
    m_dataMap.erase(m_dataMap.begin() + row);
}
//===============================================
void GCsv::clear() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    for(int i = 0; i < m_dataMap.size(); i++) {
        std::vector<std::string>* lItemMap = m_dataMap.at(i);
        lItemMap->clear();
        delete lItemMap;
    }
    m_dataMap.clear();
}
//===============================================
void GCsv::size(int& row, int& col) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::vector<std::string>* lItemMap = m_dataMap.at(0);
    row = m_dataMap.size();
    col = lItemMap->size();
}
//===============================================
void GCsv::showData() {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GShow::Instance()->showData(m_dataMap);
}
//===============================================
