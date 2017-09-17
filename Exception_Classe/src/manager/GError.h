//===============================================
#ifndef _GError_
#define _GError_
//===============================================
#include <exception>
#include <iostream>
#include <string>
//===============================================
using namespace std;
//===============================================
class GError : public exception {
public:
    GError() throw();
    GError(const int& number, const string& error, const int& level) throw();
    ~GError() throw();

public:
    const char* what() const throw();
    
public:
    int getNumber() const;
    int getLevel() const;
    
private:
    int m_number;
    string m_error;
    int m_level;
};
//===============================================
#endif
//===============================================
