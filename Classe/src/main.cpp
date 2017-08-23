//===============================================
#include "GPerson.h"
#include <iostream>
//===============================================
using namespace std;
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    GPerson m_person1("Gerard", 10);
    GPerson m_person2("Deborah", 20);
    m_person1.print("m_person1");
    m_person2.print("m_person2");
    cout << "-------------------------------------------------\n";
    m_person1.setName("Gerard KESSE");
    m_person2.setName("Deborah YOBOUE");
    m_person1.print("m_person1");
    m_person2.print("m_person2");
    cout << "-------------------------------------------------\n";
    m_person1.setAge(15);
    m_person2.setAge(25);
    m_person1.print("m_person1");
    m_person2.print("m_person2");
    cout << "-------------------------------------------------\n";
    cout << "m_age1 : " << m_person1.getAge() << "\n";
    cout << "m_age2 : " << m_person2.getAge() << "\n";
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
