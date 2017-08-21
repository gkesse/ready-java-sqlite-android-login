//===============================================
#include "GPerson.h"
#include <iostream>
//===============================================
GPerson::GPerson() {
    m_name = "";
    m_age = 0;
}
//===============================================
GPerson::GPerson(const string& name, const int& age) {
    m_name = name;
    m_age = age;
}
//===============================================
GPerson::~GPerson() {
    
}
//===============================================
string GPerson::getName() const {
    return m_name;
}
//===============================================
int GPerson::getAge() const {
    return m_age;
}
//===============================================
void GPerson::setName(const string& name) {
    m_name = name;
}
//===============================================
void GPerson::setAge(const int& age) {
    m_age = age;
}
//===============================================
void GPerson::print(const string& name) const {
    cout << name << " : ( ";
    cout << m_name << " ; ";
    cout << m_age << " )";
    cout << "\n";
}
//===============================================
