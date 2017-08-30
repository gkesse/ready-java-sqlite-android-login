//===============================================
#ifndef _GRect_
#define _GRect_
//===============================================
#include <iostream>
//===============================================
using namespace std;
//===============================================
template<class T>
class GRect {
public:
    GRect();
    GRect(const GRect<T>& rect);
    GRect(const T& left, const T& right, const T& top, const T& bottom);
    ~GRect();

public:
    T getLeft() const;
    T getRight() const;
    T getTop() const;
    T getBottom() const;
    void setLeft(const T& left);
    void setRight(const T& right);
    void setTop(const T& top);
    void setBottom(const T& bottom);
    
public:
    //===============================================
    friend ostream& operator<<(ostream& s, const GRect<T>& rect) {
        s << "(" << rect.m_left << " ; ";
        s << rect.m_right << " ; ";
        s << rect.m_top << " ; ";
        s << rect.m_bottom << ")";
        return s;
    }
    //===============================================
private:
    T m_left;
    T m_right;
    T m_top;
    T m_bottom;
};
//===============================================
#include "GRect.cpp"
//===============================================
#endif
//===============================================
