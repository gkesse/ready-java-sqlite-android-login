//================================================
#ifndef _GShow_
#define _GShow_
//================================================
#include "GInclude.h"
//================================================
#define GDIR_DATA_PATH "/Programs/ReadyC/unix"
//================================================
class GShow {
private:
    GShow();

public:
    ~GShow();
    static GShow* Instance();
    void test(int argc, char** argv);
    void showData(std::string data);
    void showData(int key, ...);
    void showData(std::map<std::string, std::string> data);
    void showData(std::vector<std::vector<std::string>> data);
    void showData(std::vector<std::vector<std::string>*> data);

private:
    const char* __CLASSNAME__;
    static GShow* m_instance;
};
//================================================
#endif
//================================================
