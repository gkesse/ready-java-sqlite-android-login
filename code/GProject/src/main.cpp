//===============================================
#include "GProcess.h"
#include "GGslTest.h"
//===============================================
int main(int argc, char** argv) {
    //GGslTest::Instance()->polynomial();
    GProcess::Instance()->run(argc, argv);
    return 0;
}
//===============================================
