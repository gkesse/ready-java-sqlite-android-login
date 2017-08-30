//===============================================
#include "GRect.h"
//===============================================
template<class T>
GRect<T>::GRect() {
    m_left = 0;
    m_right = 0;
    m_top = 0;
    m_bottom = 0;
}
//===============================================
template<class T>
GRect<T>::GRect(const GRect<T>& rect) {
    m_left = rect.m_left;
    m_right = rect.m_right;
    m_top = rect.m_top;
    m_bottom = rect.m_bottom;
}
//===============================================
template<class T>
GRect<T>::GRect(const T& left, const T& right, const T& top, const T& bottom) {
    m_left = left;
    m_right = right;
    m_top = top;
    m_bottom = bottom;
}
//===============================================
template<class T>
GRect<T>::~GRect() {

}
//===============================================
template<class T>
T GRect<T>::getLeft() const {
    return m_left;
}
//===============================================
template<class T>
T GRect<T>::getRight() const {
    return m_right;
}
//===============================================
template<class T>
T GRect<T>::getTop() const {
    return m_top;
}
//===============================================
template<class T>
T GRect<T>::getBottom() const {
    return m_bottom;
}
//===============================================
template<class T>
void GRect<T>::setLeft(const T& left) {
    m_left = left;
}
//===============================================
template<class T>
void GRect<T>::setRight(const T& right) {
    m_right = right;
}
//===============================================
template<class T>
void GRect<T>::setTop(const T& top) {
    m_top = top;
}
//===============================================
template<class T>
void GRect<T>::setBottom(const T& bottom) {
    m_bottom = bottom;
}
//===============================================
