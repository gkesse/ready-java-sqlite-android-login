//================================================
#ifndef _GProcess_
#define _GProcess_
//================================================
#include "GInclude.h"
//================================================
class GProcess {
private:
	GProcess();

public:
	~GProcess();
	static GProcess* Instance();
	void process(int argc, char** argv);

private:
	void test(int argc, char** argv);
	void help(int argc, char** argv);
	void window(int argc, char** argv, const char* key);

private:
	const char* __CLASSNAME__;
	static GProcess* m_instance;
};
//===============================================
#endif
//================================================
