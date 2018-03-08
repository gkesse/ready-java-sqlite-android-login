//===============================================
#include <iostream>
#include <vector>
#include <bitset>
//===============================================
using namespace std;
//===============================================
double divide(const double& a, const double& b) {
    if(b == 0) throw domain_error("Divide by zero !");
    return a / b;
}
//===============================================
void argument(const string& str) {
    try {
        bitset<5> mybitset (str);
    }
    catch(const exception& e) {
        cerr << "ERROR invalid_argument : " << e.what() << "\n";
    }
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    double mA;
    double mB;
    cout << "Enter the value of A : ";
    cin >> mA;
    cout << "Enter the value of B : ";
    cin >> mB;
    try {
        cout << "The result : " << divide(mA, mB) << "\n";
    }
    catch(const exception& e) {
        cerr << "ERROR domain_error : " << e.what() << "\n";
    }
    cout << "-------------------------------------------------\n";
    argument("01234");
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
