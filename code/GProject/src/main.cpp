//===============================================
#include "GProcess.h"
#include "GDebug.h"
//===============================================
int main(int argc, char** argv) {
    GDebug::Instance()->process("write", __FUNCTION__, "()");
    GProcess::Instance()->process(argc, argv);
    return 0;
}
//===============================================
