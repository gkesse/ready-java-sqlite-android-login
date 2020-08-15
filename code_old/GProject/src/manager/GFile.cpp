//===============================================
#include "GFile.h"
#include "GString.h"
#include "GShow.h"
#include "GConfig.h"
#include "GCsv.h"
#include "GDebug.h"
//===============================================
GFile* GFile::m_instance = 0;
//===============================================
GFile::GFile() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GFile::~GFile() {

}
//===============================================
GFile* GFile::Instance() {
    if(m_instance == 0) {
        m_instance = new GFile;
    }
    return m_instance;
}
//===============================================
void GFile::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    
    int lId = 2;
    
    if(lId == 1) {
        std::string lFile = "lFile";
        std::string lFilename = "data/file/file.txt";
        GFile::Instance()->createIfstream(lFile, lFilename);
        std::string lData = GFile::Instance()->getData(lFile);
        GShow::Instance()->showData(lData);
        GFile::Instance()->deleteIfstream(lFile);
    }
    else if(lId == 2) {
        std::string lFile = "lFile";
        std::string lFilename = "data/file/file2.txt";
        GFile::Instance()->createIfstream(lFile, lFilename);
        GFile::Instance()->getDataMap(lFile, '=');
        GConfig::Instance()->setData("MY_KEY_02", "MY_UPDATE");
        GConfig::Instance()->removeData("MY_KEY_03");
        GConfig::Instance()->showData();
        GFile::Instance()->deleteIfstream(lFile);
    }
    else if(lId == 3) {
        std::string lFile = "lFile";
        std::string lFilename = "data/file/file3.txt";
        int lRows, lCols; std::string lData;
        GFile::Instance()->createIfstream(lFile, lFilename);
        GFile::Instance()->getDataCsv(lFile, ';');
        GCsv::Instance()->size(lRows, lCols);
        GCsv::Instance()->setData(1, 1, "MY_UPDATE");
        GCsv::Instance()->removeData(3);
        GShow::Instance()->showData(3, "[lRows ; lCols] = ", 1, lRows, 3, " ; ", 1, lCols, 0);
        lData = GCsv::Instance()->getData(1, 1);
        GShow::Instance()->showData(lData);
        GCsv::Instance()->showData();
        GFile::Instance()->deleteIfstream(lFile);
    }
}
//===============================================
// ifstream
//===============================================
void GFile::createIfstream(std::string fileId, std::string filename) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::ifstream* lFile = new std::ifstream(filename.c_str(), std::ifstream::in);
    m_ifstreamMap[fileId] = lFile;
}
//===============================================
std::string GFile::getData(std::string fileId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::ifstream* lFile = m_ifstreamMap[fileId];
    std::string lData((std::istreambuf_iterator<char>(*lFile)), std::istreambuf_iterator<char>());
    return lData;
}
//===============================================
std::map<std::string, std::string> GFile::getDataMap(std::string fileId, char sep) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::ifstream* lFile = m_ifstreamMap[fileId];
    std::string lLine;
    std::map<std::string, std::string> lStringsMap;
    while(getline(*lFile, lLine)) {
        lLine = GString::Instance()->trim(lLine);
        if(lLine == "") continue;
        char lFirst = lLine.at(0);
        if(lFirst == '#') continue;
        std::vector<std::string> lStrings = GString::Instance()->split(lLine, sep);
        std::string lKey = lStrings.at(0);
        std::string lValue = lStrings.at(1);
        lStringsMap[lKey] = lValue;
        GConfig::Instance()->setData(lKey, lValue);
    }
    return lStringsMap;
}
//===============================================
std::vector<std::vector<std::string>> GFile::getDataCsv(std::string fileId, char sep) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::ifstream* lFile = m_ifstreamMap[fileId];
    std::string lLine;
    std::vector<std::vector<std::string>> lStringsMap;
    while(getline(*lFile, lLine)) {
        lLine = GString::Instance()->trim(lLine);
        if(lLine == "") continue;
        char lFirst = lLine.at(0);
        if(lFirst == '#') continue;
        std::vector<std::string> lStringMap = GString::Instance()->split(lLine, sep);
        GCsv::Instance()->addRow();
        for(int i = 0; i < lStringMap.size(); i++) {
            std::string lData = lStringMap.at(i);
            GCsv::Instance()->addData(lData);
        }
        lStringsMap.push_back(lStringMap);
    }
    return lStringsMap;
}
//===============================================
void GFile::deleteIfstream(std::string fileId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::ifstream* lFile = m_ifstreamMap[fileId];
    delete lFile;
    m_ifstreamMap[fileId] = 0;
}
//===============================================
