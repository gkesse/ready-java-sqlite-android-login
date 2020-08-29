//===============================================
#include "GProcess.h"
#include "GGslTest.h"
//===============================================
int main(int argc, char** argv) {
    GGslTest::Instance()->matrix();
    exit(0);
    GProcess::Instance()->run(argc, argv);
    return 0;
}
//===============================================
