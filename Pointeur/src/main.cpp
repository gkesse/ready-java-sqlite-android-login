//===============================================
#include <iostream>
#include <string>
//===============================================
using namespace std;
//===============================================
void condition1(const int& a, const int& b) {
    if(a > b) {
        cout << a << " is greater than " << b << "\n"; 
        return;
    }
    cout << a << " is smaller than " << b << "\n"; 
}
//===============================================
void condition2(const int& a, const int& b) {
    if(a > b) {
        cout << a << " is strictly greater than " << b << "\n"; 
    }
    else {
        cout << a << " is smaller than or equal to " << b << "\n"; 
    }
}
//===============================================
void condition3(const int& a, const int& b) {
    if(a > b) {
        cout << a << " is strictly greater than " << b << "\n"; 
    }
    else if (a > b) {
        cout << a << " is strictly smaller than " << b << "\n"; 
    }
    else {
        cout << a << " is equal to " << b << "\n"; 
    }
}
//===============================================
int main(int argc, char** argv) {
    condition1(10, 20);
    condition2(20, 10);
    condition3(10, 10);
    return 0;
}
//===============================================
