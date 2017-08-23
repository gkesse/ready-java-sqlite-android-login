//===============================================
#include "GShape.h"
//===============================================
#include <iostream>
#include <vector>
//===============================================
using namespace std;
//===============================================
void polymorphism1() {
    vector<GShape*> m_shape;
    m_shape.push_back(GShape::Create(GShape::Line));
    m_shape.push_back(GShape::Create(GShape::Rectangle));
    m_shape.push_back(GShape::Create(GShape::Ellipse));
    
    for(int i = 0; i < m_shape.size(); i++) {
        m_shape[i]->draw();
    }
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    polymorphism1();
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
