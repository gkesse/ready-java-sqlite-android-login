//===============================================
#include "GError.h"
//===============================================
double divide(const double& a, const double& b) {
    if(b == 0) throw GError(1, "Divide by zero !", 2);
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
    catch(const exception& e) {
        cerr << "ERROR Class : " << e.what() << "\n";
    }
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
