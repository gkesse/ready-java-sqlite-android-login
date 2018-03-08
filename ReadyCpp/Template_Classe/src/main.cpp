//===============================================
#include "GRect.h"
//===============================================
void template1() {
    GRect<int> m_rect1;
    GRect<int> m_rect2(1, 2, 3, 4);
    GRect<int> m_rect3(m_rect2);
    
    cout << "\n";
    cout << "m_rect1 : " << m_rect1 << "\n";
    cout << "m_rect2 : " << m_rect2 << "\n";
    cout << "m_rect3 : " << m_rect3 << "\n";
    
    cout << "\n";
    cout << "m_left3 : " << m_rect3.getLeft() << "\n";
    cout << "m_right3 : " << m_rect3.getRight() << "\n";
    cout << "m_top : " << m_rect3.getTop() << "\n";
    cout << "m_bottom : " << m_rect3.getBottom() << "\n";
    
    m_rect3.setLeft(10);
    m_rect3.setRight(20);
    m_rect3.setTop(30);
    m_rect3.setBottom(40);
    
    cout << "\n";
    cout << "m_left3 : " << m_rect3.getLeft() << "\n";
    cout << "m_right3 : " << m_rect3.getRight() << "\n";
    cout << "m_top3 : " << m_rect3.getTop() << "\n";
    cout << "m_bottom3 : " << m_rect3.getBottom() << "\n";
}
//===============================================
void template2() {
    GRect<double> m_rect1;
    GRect<double> m_rect2(1.15, 2.25, 3.35, 4.45);
    GRect<double> m_rect3(m_rect2);
    
    cout << "m_rect1 : " << m_rect1 << "\n";
    cout << "m_rect2 : " << m_rect2 << "\n";
    cout << "m_rect3 : " << m_rect3 << "\n";
    
    cout << "\n";
    cout << "m_left3 : " << m_rect3.getLeft() << "\n";
    cout << "m_right3 : " << m_rect3.getRight() << "\n";
    cout << "m_top2 : " << m_rect3.getTop() << "\n";
    cout << "m_bottom3 : " << m_rect3.getBottom() << "\n";
    
    m_rect3.setLeft(10.15);
    m_rect3.setRight(20.25);
    m_rect3.setTop(30.35);
    m_rect3.setBottom(40.45);
    
    cout << "\n";
    cout << "m_left3 : " << m_rect3.getLeft() << "\n";
    cout << "m_right3 : " << m_rect3.getRight() << "\n";
    cout << "m_top3 : " << m_rect3.getTop() << "\n";
    cout << "m_bottom3 : " << m_rect3.getBottom() << "\n";
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    template1();
    cout << "-------------------------------------------------\n";
    template2();
    cout << "-------------------------------------------------\n";
    
    return 0;
}
//===============================================
