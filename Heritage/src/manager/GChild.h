//===============================================
#ifndef _GChild_
#define _GChild_
//===============================================
#include "GParent.h"
#include <string>
//===============================================
using namespace std;
//===============================================
class GChild : public GParent {
public:
    GChild();
    GChild(const string& name);
    GChild(const string& name, const int& age);
    ~GChild();

public:
    int getAge() const;
    void setAge(const int& age);
   
public:
    void print(const string& name) const;
    
private:
    int m_age;
};
//===============================================
#endif
//===============================================
