//===============================================
#include "GParent.h"
#include <iostream>
//===============================================
GParent::GParent() {
    m_name = "_NONE_";
}
//===============================================
GParent::GParent(const string& name) {
    m_name = name;
}
//===============================================
GParent::~GParent() {
    
}
//===============================================
string GParent::getName() const {
    return m_name;
}
//===============================================
void GParent::setName(const string& name) {
    m_name = name;
}
//===============================================
void GParent::print(const string& name) const {
    cout << name << " : ";
    cout << "Parent : " << m_name;
    cout << "\n";
}
//===============================================
