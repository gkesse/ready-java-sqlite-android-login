//===============================================
#ifndef _GTime_
#define _GTime_
//===============================================
#include <string>
//===============================================
using namespace std;
//===============================================
class GTime {
public:
    GTime();
    GTime(const int& hour, const int& minute, const int& second);
    ~GTime();

public:
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void setHour(const int& hour);
    void setMinute(const int& minute);
    void setSecond(const int& second);
    
public:
    void print(const string& name) const;

private:
    bool isEqual(const GTime& a) const;
    bool isSmaller(const GTime& a) const;
    void add(const GTime& a);
    void add(const int& a);
    void print(ostream& s) const;
    
public:
    GTime& operator+=(const GTime& a);
    GTime& operator+=(const int& a);

public:
    friend GTime operator+(const GTime& a, const GTime& b);
    friend GTime operator+(const GTime& a, const int& b);
    friend GTime operator+(const int& a, const GTime& b);

public:
    friend ostream& operator<<(ostream& s, const GTime& b);

public:
    friend bool operator==(const GTime& a, const GTime& b);
    friend bool operator!=(const GTime& a, const GTime& b);
    friend bool operator<(const GTime& a, const GTime& b);
    friend bool operator<=(const GTime& a, const GTime& b);
    friend bool operator>(const GTime& a, const GTime& b);
    friend bool operator>=(const GTime& a, const GTime& b);
    
private:
    int m_hour;
    int m_minute;
    int m_second;
};
//===============================================
#endif
//===============================================