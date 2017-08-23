//===============================================
#ifndef _GFunctor_
#define _GFunctor_
//===============================================
#include <string>
//===============================================
using namespace std;
//===============================================
class GFunctor1 {   
public:
    int operator()(const int& a, const int& b) {
        return (a + b);
    }
};
//===============================================
class GFunctor2 {
public:
    GFunctor2(const int& value);
    
public:
    int operator()() {
        m_value += 10;
        return m_value;
    }
    
private:
    int m_value;
};
//===============================================
#endif
//===============================================
