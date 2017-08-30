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
template <>
string maximum<string>(const string& a, const string& b) {
    if(a.size() > b.size()) return a;
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
    string m_string1 = "elephant";
    string m_string2 = "souris";
    string m_max1 = maximum(m_string1, m_string2);
    
    cout << "m_string1 : " << m_string1 << "\n";
    cout << "m_string2 : " << m_string2 << "\n";
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
