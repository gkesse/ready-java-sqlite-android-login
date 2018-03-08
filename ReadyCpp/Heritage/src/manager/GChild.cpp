//===============================================
#include "GChild.h"
#include <iostream>
//===============================================
GChild::GChild() {
    m_age = 0;
}
//===============================================
GChild::GChild(const string& name) :
GParent(name) {
    m_age = 0;
}
//===============================================
GChild::GChild(const string& name, const int& age) :
GParent(name) {
    m_age = age;
}
//===============================================
GChild::~GChild() {
    
}
//===============================================
int GChild::getAge() const {
    return m_age;
}
//===============================================
void GChild::setAge(const int& age) {
    m_age = age;
}
//===============================================
void GChild::print(const string& name) const {
    cout << name << " : ";
    cout << "Child : " << m_name;
    cout << " ; " << m_age;
    cout << "\n";
}
//===============================================
