//===============================================
#include <iostream>
#include <string>
//===============================================
using namespace std;
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    bool m_bool = true;
    char m_char = 'A';
    int m_int = 10;
    float m_float = 3.14;
    double m_double = 12.25;                                                                                                                                  
    string m_string = "Hello world!";                                                                                                                                  
    
    cout << "m_bool : " << m_bool << "\n";
    cout << "m_char : " << m_char << "\n";
    cout << "m_int : " << m_int << "\n";
    cout << "m_float : " << m_float << "\n";
    cout << "m_double : " << m_double << "\n";
    cout << "m_string : " << m_string << "\n";
    cout << "-------------------------------------------------\n";
    cout << "m_bool : " << sizeof(bool) << "\n";
    cout << "m_char : " << sizeof(char) << "\n";
    cout << "m_int : " << sizeof(int) << "\n";
    cout << "m_float : " << sizeof(float) << "\n";
    cout << "m_double : " << sizeof(double) << "\n";
    cout << "m_string : " << sizeof(string) << "\n";
    cout << "-------------------------------------------------\n";
    
    return 0;
}
//===============================================
