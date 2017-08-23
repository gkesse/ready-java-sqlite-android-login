//===============================================
#ifndef _GParent_
#define _GParent_
//===============================================
#include <string>
//===============================================
using namespace std;
//===============================================
class GParent {
public:
    GParent();
    GParent(const string& name);
    ~GParent();

public:
    string getName() const;
    void setName(const string& name);
   
public:
    void print(const string& name) const;
    
protected:
    string m_name;
};
//===============================================
#endif
//===============================================
