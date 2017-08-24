//===============================================
#include "GTime.h"
#include <iostream>
#include <iomanip>
//===============================================
GTime::GTime() {
    m_hour = 0;
    m_minute = 0;
    m_second = 0;
}
//===============================================
GTime::GTime(const int& hour, const int& minute, const int& second) {
    m_hour = hour;
    m_minute = minute;
    m_second = second;
}
//===============================================
GTime::~GTime() {
    
}
//===============================================
int GTime::getHour() const {
    return m_hour;
}
//===============================================
int GTime::getMinute() const {
    return m_minute;
}
//===============================================
int GTime::getSecond() const {
    return m_second;
}
//===============================================
void GTime::setHour(const int& hour) {
    m_hour = hour;
}
//===============================================
void GTime::setMinute(const int& minute) {
    m_minute = minute;
}
//===============================================
void GTime::setSecond(const int& second) {
    m_second = second;
}
//===============================================
void GTime::print(const string& name) const {
    cout << name << " : ";
    cout << setw(2) << setfill('0') << m_hour << " h ";
    cout << setw(2) << setfill('0') << m_minute << " min ";
    cout << setw(2) << setfill('0') << m_second << " sec";
    cout << "\n";
}
//===============================================
bool GTime::isEqual(const GTime& a) const {
    bool m_data = true;
    m_data &= (m_hour == a.m_hour);
    m_data &= (m_minute == a.m_minute);
    m_data &= (m_second == a.m_second);
    return m_data;
}
//===============================================
bool GTime::isSmaller(const GTime& a) const {
    if(m_hour < a.m_hour) return true;
    if(m_minute < a.m_minute) return true;
    if(m_second < a.m_second) return true;
    return false;
}
//===============================================
void GTime::add(const GTime& a) {
    m_second += a.m_second;
    m_minute += m_second / 60;
    m_second %= 60;
    m_minute += a.m_minute;
    m_hour += m_minute / 60;
    m_minute %= 60;
    m_hour += a.m_hour;
}
//===============================================
void GTime::add(const int& a) {
    m_second += a;
    m_minute += m_second / 60;
    m_second %= 60;
    m_hour += m_minute / 60;
    m_minute %= 60;
}
//===============================================
GTime& GTime::operator+=(const GTime& a) {
    add(a);
    return *this;
}
//===============================================
GTime& GTime::operator+=(const int& a) {
    add(a);
    return *this;
}
//===============================================
GTime operator+(const GTime& a, const GTime& b) {
    GTime m_copy(a);
    m_copy += b;
    return m_copy;
}
//===============================================
GTime operator+(const GTime& a, const int& b) {
    GTime m_copy(a);
    m_copy += b;
    return m_copy;
}
//===============================================
GTime operator+(const int& a, const GTime& b) {
    GTime m_copy(b);
    m_copy += a;
    return m_copy;
}
//===============================================
bool operator==(const GTime& a, const GTime& b) {
    return a.isEqual(b);
}
//===============================================
bool operator!=(const GTime& a, const GTime& b) {
    return !a.isEqual(b);
}
//===============================================
bool operator<(const GTime& a, const GTime& b) {
    return a.isSmaller(b);
}
//===============================================
bool operator<=(const GTime& a, const GTime& b) {
    return (a.isSmaller(b) || a.isEqual(b));
}
//===============================================
bool operator>(const GTime& a, const GTime& b) {
    return (!a.isSmaller(b) && !a.isEqual(b));
}
//===============================================
bool operator>=(const GTime& a, const GTime& b) {
    return (!a.isSmaller(b) || a.isEqual(b));
}
//===============================================
