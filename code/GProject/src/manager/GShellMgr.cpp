//===============================================
#include "GShellMgr.h"
//===============================================
#define B_COMMAND 256
#define B_PATH 256
//===============================================
GShellMgr* GShellMgr::m_instance = 0;
//===============================================
GShellMgr::GShellMgr() {
    
}
//===============================================
GShellMgr::~GShellMgr() {
    
}
//===============================================
GShellMgr* GShellMgr::Instance() {
    if(m_instance == 0) {
        m_instance = new GShellMgr;
    }
    return m_instance;
}
//===============================================
void GShellMgr::run(const char* command, char* output, int size, int shift) {
	FILE* lpFile = popen(command, "r");
	if(output != 0) {
		int lBytes = fread(output, 1, size, lpFile);
		if(lBytes >= 1) {
			output[lBytes] = 0;
			if(shift == 1) output[lBytes - 1] = 0;
		}
	}
	pclose(lpFile);
}
//===============================================
void GShellMgr::system(const char* command) {
    system(command);
}
//===============================================
