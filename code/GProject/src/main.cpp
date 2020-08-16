//===============================================
#include "GProcess.h"
#include "GSQLiteMgr.h"
//===============================================
int main(int argc, char** argv) {
    GSQLiteMgr::Instance()->query();
    //GProcess::Instance()->run(argc, argv);
    return 0;
}
//===============================================
