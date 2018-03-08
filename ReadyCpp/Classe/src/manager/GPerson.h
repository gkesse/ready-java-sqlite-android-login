//===============================================
#ifndef _GPerson_
#define _GPerson_
//===============================================
#include <string>
//===============================================
using namespace std;
//===============================================
class GPerson {
public:
    GPerson();
    GPerson(const string& name, const int& age);
    ~GPerson();

public:
    string getName() const;
    int getAge() const;
    void setName(const string& name);
    void setAge(const int& age);
   
public:
    void print(const string& name) const;
    
private:
    string m_name;
    int m_age;
};
//===============================================
#endif
//===============================================
