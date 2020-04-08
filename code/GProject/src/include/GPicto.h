//================================================
#ifndef _GPicto_
#define _GPicto_
//================================================
#include "GInclude.h"
//================================================
class GPicto {
private:
	GPicto();

public:
	~GPicto();
	static GPicto* Instance();
    void process(const char* key, ...);

private:
    void load(QString filename);

private:
    const char* __CLASSNAME__;
	static GPicto* m_instance;
};
//================================================
#endif
//================================================
