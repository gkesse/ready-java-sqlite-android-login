//===============================================
#include "GProcess.h"
#include "GSQLiteMgr.h"
//===============================================
int main(int argc, char** argv) {
    GSQLiteMgr::Instance()->queryShow("", ""
    "select *\n"
    "from CONFIG_DATA\n"
    "", 1, "20;20", "20");
    
    std::string lData = GSQLiteMgr::Instance()->queryValue("", ""
    "select CONFIG_VALUE\n"
    "from CONFIG_DATA\n"
    "where CONFIG_KEY=\"G_USER_NAME\"\n"
    "");
    printf("\n%s\n", lData.c_str());
    
    std::vector<std::string> lDataMap = GSQLiteMgr::Instance()->queryColumn("", ""
    "select CONFIG_VALUE\n"
    "from CONFIG_DATA\n"
    "");
    printf("\n%s\n", lDataMap[1].c_str());
    
    //GProcess::Instance()->run(argc, argv);
    return 0;
}
//===============================================
