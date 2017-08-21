//===============================================
#include <iostream>
#include <string>
//===============================================
using namespace std;
//===============================================
void function1() {
    cout << "F1 : Hello world!\n";    
}
//===============================================
string function2() {
    return "F2 : Hello world!";    
}
//===============================================
void function3(const string& str) {
    cout << "F3 : " << str << "\n";    
}
//===============================================
string function4(const string& str) {
    return ("F4 : " + str);    
}
//===============================================
int main(int argc, char** argv) {
    function1();
    cout << function2() << "\n";
    function3("Hello world!");
    cout << function4("Hello world!") << "\n";
    return 0;
}
//===============================================
