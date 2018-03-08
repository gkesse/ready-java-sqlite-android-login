//===============================================
#include <iostream>
//===============================================
using namespace std;
//===============================================
void reference1() {
    double m_data = 3.14;
    double &m_ref = m_data;
    
    cout << "Data : Content : " << m_data << "\n"; 
    cout << "Data : Address : " << &m_data << "\n"; 
    cout << "Reference : Content : " << m_ref << "\n"; 
    cout << "Reference : Address : " << &m_ref << "\n";
    
    cout << "\n";
    m_ref = 12.34;
    cout << "Data : Content : " << m_data << "\n"; 
    cout << "Data : Address : " << &m_data << "\n"; 
    cout << "Reference : Content : " << m_ref << "\n"; 
    cout << "Reference : Address : " << &m_ref << "\n";
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    reference1();
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
