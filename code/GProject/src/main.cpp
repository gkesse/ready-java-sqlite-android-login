//===============================================
#include "GProcess.h"
#include "GGslTest.h"
#include "GOpenCVTest.h"
//===============================================
int main(int argc, char** argv) {
    GOpenCVTest::Instance()->mouse();
    GProcess::Instance()->run(argc, argv);
    return 0;
}
//===============================================
