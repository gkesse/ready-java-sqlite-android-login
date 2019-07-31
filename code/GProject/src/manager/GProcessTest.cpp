//===============================================
#include "GProcessTest.h"
#include "GConsole.h"
//===============================================
GProcessTest* GProcessTest::m_instance = 0;
//===============================================
GProcessTest::GProcessTest() {

}
//===============================================
GProcessTest::~GProcessTest() {

}
//===============================================
GProcessTest* GProcessTest::Instance() {
    if(m_instance == 0) {
        m_instance = new GProcessTest;
    }
    return m_instance;
}
//===============================================
void GProcessTest::run(int argc, char **argv) {
	GConsole::Instance()->print("Bonjour tout le monde\n");
}
//===============================================
