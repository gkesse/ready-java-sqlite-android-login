//===============================================
#include "GTest.h"
#include "GManager.h"
//===============================================
using namespace std;
using namespace cv;
//===============================================
GTest* GTest::m_instance = 0;
//===============================================
GTest::GTest() {
    
}
//===============================================
GTest::~GTest() {
    
}
//===============================================
GTest* GTest::Instance() {
    if(m_instance == 0) {
        m_instance = new GTest;
    }
    return m_instance;
}
//===============================================
void GTest::run(int argc, char** argv) {
    CommandLineParser parser(argc, argv, keys);
    parser.about("Application name v1.0.0");
    if (parser.has("help")) {parser.printMessage(); return;}
    int N = parser.get<int>("N");
    double fps = parser.get<double>("fps");
    String path = parser.get<String>("path");
    use_time_stamp = parser.has("timestamp");
    String img1 = parser.get<String>(0);
    String img2 = parser.get<String>(1);
    int repeat = parser.get<int>(2);
    if (!parser.check()){parser.printErrors();return;}
}
//===============================================
