//===============================================
#include "GProcess.h"
#include "GDebug.h"
//===============================================
int main(int argc, char** argv) {
    GDebug::Instance()->sep();
    GDebug::Instance()->write(__FUNCTION__, "()", 0);
    GProcess::Instance()->process(argc, argv);
    return 0;
}
//===============================================
