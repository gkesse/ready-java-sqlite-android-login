//===============================================
#include "GProcess.h"
#include "GDebug.h"
//===============================================
int main(int argc, char** argv) {
    GProcess::Instance()->process(argc, argv);
    GDebug::Instance()->process("help");
    return 0;
}
//===============================================
