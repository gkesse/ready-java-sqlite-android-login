//===============================================
#include <iostream>
#include <vector>
//===============================================
using namespace std;
//===============================================
void function1(const string& str) {
    cout << "Argument : " << str.c_str() << "\n";
}
//===============================================
void exception1() {
    try {
        vector<double> m_vector(1000000000, 1.5);
        cout << "SUCCESS : Vector is created\n";
    }
    catch(const exception& e) {
        cerr << "ERROR Vector : " << e.what() << "\n";
    }
}
//===============================================
void exception2() {
    try {
        vector<double> m_vector(5, 10.25);
        m_vector[10] = 10.25;
        cout << "SUCCESS : Vector is created\n";
    }
    catch(const exception& e) {
        cerr << "ERROR Argument : " << e.what() << "\n";
    }
}
//===============================================
void exception3() {
    try {
        vector<double> m_vector(5, 10.25);
        m_vector.at(10) = 10.25;
        cout << "SUCCESS : Vector is created\n";
    }
    catch(const exception& e) {
        cerr << "ERROR Argument : " << e.what() << "\n";
    }
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    exception1();
    cout << "-------------------------------------------------\n";
    exception2();
    cout << "-------------------------------------------------\n";
    exception3();
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
