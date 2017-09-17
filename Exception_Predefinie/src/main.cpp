//===============================================
#include <iostream>
#include <vector>
//===============================================
using namespace std;
//===============================================
void vector1() {
    try {
        vector<double> m_vector(1000000000, 1.5);
        cout << "SUCCESS : Vector is created\n";
    }
    catch(const exception& e) {
        cerr << "ERROR Predefined : " << e.what() << "\n";
    }
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    vector1();
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
