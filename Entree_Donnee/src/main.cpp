//===============================================
#include <iostream>
#include <string>
//===============================================
using namespace std;
//===============================================
void input1() {
    int m_int = -1;
    cout << "Input : ";
    cin >> m_int;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Output : " << m_int;
    cout << "\n";
}
//===============================================
void input2() {
    string m_str = "_NONE_";
    cout << "Input : ";
    getline(cin, m_str);
    cout << "Output : " << m_str;
    cout << "\n";
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    input1();
    cout << "-------------------------------------------------\n";
    input2();
    cout << "-------------------------------------------------\n";
    input1();
    cout << "-------------------------------------------------\n";
    input2();
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
