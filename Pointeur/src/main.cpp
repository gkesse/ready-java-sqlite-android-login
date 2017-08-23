//===============================================
#include <iostream>
//===============================================
using namespace std;
//===============================================
void pointer1() {
    double m_data = 3.14;
    double *m_ptr = &m_data;
    
    cout << "Data : Content : " << m_data << "\n"; 
    cout << "Data : Address : " << &m_data << "\n"; 
    cout << "Pointer : Content : " << *m_ptr << "\n"; 
    cout << "Pointer : Address : " << m_ptr << "\n";
    
    cout << "\n";
    *m_ptr = 25.23;
    cout << "Data : Content : " << m_data << "\n"; 
    cout << "Data : Address : " << &m_data << "\n"; 
    cout << "Pointer : Content : " << *m_ptr << "\n"; 
    cout << "Pointer : Address : " << m_ptr << "\n";
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    pointer1();
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
