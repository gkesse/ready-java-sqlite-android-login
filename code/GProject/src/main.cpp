//===============================================
#include "GProcess.h"
#include "GGslTest.h"
#include "GOpenCVTest.h"
//===============================================
int main(int argc, char** argv) {
    GOpenCVTest::Instance()->text();
    GProcess::Instance()->run(argc, argv);
    return 0;
}
//===============================================
