//===============================================
#include "GProcess.h"
#include "GManager.h"
//===============================================
int main(int argc, char** argv) {
    GProcess::Instance()->run(argc, argv);
    return 0;
}
//===============================================
