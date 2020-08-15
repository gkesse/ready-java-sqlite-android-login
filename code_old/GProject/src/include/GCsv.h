//================================================
#ifndef _GCsv_
#define _GCsv_
//================================================
#include "GInclude.h"
//================================================
#define GDIR_DATA_PATH "/Programs/ReadyC/unix"
//================================================
class GCsv {
private:
    GCsv();

public:
    ~GCsv();
    static GCsv* Instance();
    void test(int argc, char** argv);
    void addRow();
    void addData(std::string data);
    void setData(int row, int col, std::string data);
    std::string getData(int row, int col);
    void removeData(int row);
    void size(int& row, int& col);
    void clear();
    void showData();

private:
    const char* __CLASSNAME__;
    static GCsv* m_instance;
    std::vector<std::vector<std::string>*> m_dataMap;
    std::vector<std::string>* m_itemMap;
};
//================================================
#endif
//================================================
