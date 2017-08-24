//===============================================
#include "GTime.h"
#include <iostream>
//===============================================
using namespace std;
//===============================================
void overload1() {
    GTime m_time0;
    GTime m_time1(13, 25, 30);
    GTime m_time2(15, 25, 30);
    m_time0.print("m_time0");
    m_time1.print("m_time1");
    m_time2.print("m_time2");
    
    cout << "\n";
    cout << "m_isEqual1 : m_time1 == m_time1 : " << m_time1.isEqual(m_time1) << "\n";
    cout << "m_isEqual2 : m_time1 == m_time2 : " << m_time1.isEqual(m_time2) << "\n";
    
    cout << "\n";
    cout << "m_isEqual1 : m_time1 == m_time1 : " << (m_time1 == m_time1) << "\n";
    cout << "m_isEqual2 : m_time1 == m_time2 : " << (m_time1 == m_time2) << "\n";

    cout << "\n";
    cout << "m_isDiff1 : m_time1 != m_time1 : " << (m_time1 != m_time1) << "\n";
    cout << "m_isDiff2 : m_time1 != m_time2 : " << (m_time1 != m_time2) << "\n";
}
//===============================================
void overload2() {
    GTime m_time1(20, 30, 15);
    GTime m_time2(20, 30, 30);
    m_time1.print("m_time1");
    m_time2.print("m_time2");
    
    cout << "\n";
    cout << "m_isSmaller1 : m_time1 < m_time2 : " << m_time1.isSmaller(m_time2) << "\n";
    cout << "m_isSmaller2 : m_time2 < m_time1 : " << m_time2.isSmaller(m_time1) << "\n";
    
    cout << "\n";
    cout << "m_isSmaller1 : m_time1 < m_time2 : " << (m_time1 < m_time2) << "\n";
    cout << "m_isSmaller2 : m_time2 < m_time1 : " << (m_time2 < m_time1) << "\n";
    
    cout << "\n";
    cout << "m_isSmallerEq1 : m_time1 <= m_time1 : " << (m_time1 <= m_time1) << "\n";
    cout << "m_isSmallerEq2 : m_time1 <= m_time2 : " << (m_time1 <= m_time2) << "\n";
    
    cout << "\n";
    cout << "m_isGreater1 : m_time1 > m_time2 : " << (m_time1 > m_time2) << "\n";
    cout << "m_isGreater2 : m_time2 > m_time1 : " << (m_time2 > m_time1) << "\n";

    cout << "\n";
    cout << "m_isGreaterEq1 : m_time2 >= m_time2 : " << (m_time2 >= m_time2) << "\n";
    cout << "m_isGreaterEq2 : m_time2 >= m_time1 : " << (m_time2 >= m_time1) << "\n";
}
//===============================================
void overload3() {
    GTime m_time1(4, 30, 15);
    GTime m_time2(8, 30, 30);
    m_time1.print("m_time1");
    m_time2.print("m_time2");
    
    cout << "\n";
    m_time2 += m_time1;
    m_time2.print("m_time2");
    
    cout << "\n";
    m_time1 += 45;
    m_time1.print("m_time1");
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    overload1();
    cout << "-------------------------------------------------\n";
    overload2();
    cout << "-------------------------------------------------\n";
    overload3();
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
