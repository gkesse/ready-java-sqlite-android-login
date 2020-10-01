//===============================================
#include "GProcess.h"
#include "GJson.h"
//===============================================
int main(int argc, char** argv) {
    //GJson::Instance()->test();
    GProcess::Instance()->run(argc, argv);
    return 0;
}
//===============================================