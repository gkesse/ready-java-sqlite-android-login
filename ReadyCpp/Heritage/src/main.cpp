//===============================================
#include "GParent.h"
#include "GChild.h"
#include <iostream>
//===============================================
using namespace std;
//===============================================
void parent1() {
    GParent m_parent0;
    GParent m_parent1("Gerard");
    GParent m_parent2("Deborah");
    m_parent0.print("m_parent0");
    m_parent1.print("m_parent1");
    m_parent2.print("m_parent2");
    
    cout << "\n";
    m_parent0.setName("Bryan KESSE");
    m_parent1.setName("Gerard KESSE");
    m_parent2.setName("Deborah YOBOUE");
    m_parent0.print("m_parent0");
    m_parent1.print("m_parent1");
    m_parent2.print("m_parent2");

    cout << "\n";
    cout << "m_name0 : Parent : " << m_parent0.getName() << "\n";
    cout << "m_name1 : Parent : " << m_parent1.getName() << "\n";
    cout << "m_name2 : Parent : " << m_parent2.getName() << "\n";
}
//===============================================
void child1() {
    GChild m_child0;
    GChild m_child1("Gerard");
    GChild m_child2("Deborah", 20);
    m_child0.print("m_child0");
    m_child1.print("m_child1");
    m_child2.print("m_child2");

    cout << "\n";
    m_child0.setName("Bryan KESSE");
    m_child1.setName("Gerard KESSE");
    m_child2.setName("Deborah YOBOUE");
    m_child0.print("m_child0");
    m_child1.print("m_child1");
    m_child2.print("m_child2");

    cout << "\n";
    m_child0.setAge(5);
    m_child1.setAge(15);
    m_child2.setAge(25);
    m_child0.print("m_child0");
    m_child1.print("m_child1");
    m_child2.print("m_child2");
    
    cout << "\n";
    cout << "m_name0 : Child : " << m_child0.getName() << "\n";
    cout << "m_name1 : Child : " << m_child1.getName() << "\n";
    cout << "m_name2 : Child : " << m_child2.getName() << "\n";

    cout << "\n";
    cout << "m_age0 : Child : " << m_child0.getAge() << "\n";
    cout << "m_age1 : Child : " << m_child1.getAge() << "\n";
    cout << "m_age2 : Child : " << m_child2.getAge() << "\n";
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    parent1();
    cout << "-------------------------------------------------\n";
    child1();
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
