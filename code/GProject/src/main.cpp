//===============================================
#include "GProcess.h"
#include "GDebug.h"
//===============================================
int main(int argc, char** argv) {
	GDebug::Instance()->process("sep");
    GDebug::Instance()->process("log", __FUNCTION__, "()", 0);
    GProcess::Instance()->process(argc, argv);
    return 0;
}
//===============================================
