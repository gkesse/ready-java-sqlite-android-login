//===============================================
#include <iostream>
#include <string>
//===============================================
using namespace std;
//===============================================
double divide(const double& a, const double& b) {
    if(b == 0) throw string("ERROR : Divide by zero !");
    return a / b;
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
    catch(const string& e) {
        cerr << e << "\n";
    }
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
