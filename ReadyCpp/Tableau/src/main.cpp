//===============================================
#include <iostream>
#include <iomanip>
//===============================================
using namespace std;
//===============================================
void array1() {
    const int SIZE = 10;
    int m_arr[SIZE];
    
    for(int i = 0; i < SIZE; i++) {
        m_arr[i] = i*10;
    }
    
    for(int i = 0; i < SIZE; i++) {
        int m_data = m_arr[i];
        cout << m_data << "\n";
    }
}
//===============================================
void array2() {
    const int SIZE_1 = 10;
    const int SIZE_2 = 5;
    int m_arr[SIZE_1][SIZE_2];
    
    for(int i = 0; i < SIZE_1; i++) {
        for(int j = 0; j < SIZE_2; j++) {
            m_arr[i][j] = (i + 1)*(j + 1);
        }
    }
    
    for(int i = 0; i < SIZE_1; i++) {
        for(int j = 0; j < SIZE_2; j++) {
            cout << setw(3);
            int m_data = m_arr[i][j];
            cout << m_data << " ; ";
        }
        cout << "\n";
    }
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    array1();
    cout << "-------------------------------------------------\n";
    array2();
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
