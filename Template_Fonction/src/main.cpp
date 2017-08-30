//===============================================
#include <iostream>
#include <string>
//===============================================
using namespace std;
//===============================================
template <typename T>
T maximum(const T& a, const T& b) {
    if(a > b) return a;
    else return b;
}
//===============================================
void template1() {
    double m_double1 = 25.33;
    double m_double2 = 12.33;
    double m_max1 = maximum(m_double1, m_double2);
    
    cout << "m_data1 : " << m_double1 << "\n";
    cout << "m_data2 : " << m_double2 << "\n";
    cout << "maximum : " << m_max1 << "\n";
}
//===============================================
void template2() {
    double m_int1 = 25;
    double m_int2 = 12;
    double m_max1 = maximum(m_int1, m_int2);
    
    cout << "m_int1 : " << m_int1 << "\n";
    cout << "m_int2 : " << m_int2 << "\n";
    cout << "maximum : " << m_max1 << "\n";
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    template1();
    cout << "-------------------------------------------------\n";
    template2();
    cout << "-------------------------------------------------\n";
    
    return 0;
}
//===============================================
