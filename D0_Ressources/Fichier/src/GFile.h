//===============================================
#ifndef _GFile_
#define _GFile_
//===============================================
#include <iostream>
//===============================================
using namespace std;
//===============================================
class GFile {
public:
	GFile();
	~GFile();
	
public:
	static GFile* Instance();
	void run();
	
private:
	static GFile* m_instance;
};
//===============================================
#endif
//===============================================
