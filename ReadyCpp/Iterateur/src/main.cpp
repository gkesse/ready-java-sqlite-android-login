//===============================================
#include <iostream>
#include <string>
#include <vector>
#include <map>
//===============================================
using namespace std;
//===============================================
void find(map<string, int> dataMap, string key) {
    map<string, int>::iterator it;
    it = dataMap.find(key);
    if(it != dataMap.end()) cout << "The key \""<< key << "\" exists\n";
    else cout << "The key \""<< key << "\" does not exist\n";
}
//===============================================

void iterator1() {
    vector<int> m_vector(5, 10);
    vector<int>::iterator it;
    
    for(it = m_vector.begin(); it != m_vector.end(); it++) {
        cout << *it;
        cout << "\n";
    }
}
//===============================================
void iterator2() {
    vector<int> m_vector(5, 20);
    vector<int>::iterator it;
    
    for(int i = 0; i < m_vector.size(); i++) {
        it = m_vector.begin() + i;
        cout << *it;
        cout << "\n";
    }
}
//===============================================
void iterator3() {
    map<string, int> m_map;
    map<string, int>::iterator it;
    string m_tab[] = {"one", "two", "three", "four", "five"};
    
    for(int i = 0; i < 5; i++) {
        string m_key = m_tab[i];
        int m_value = (i + 1)*(i + 1);
        m_map[m_key] = m_value;
    }
    
    for(it = m_map.begin(); it != m_map.end(); it++) {
        cout << it->first << " : ";
        cout << it->second;
        cout << "\n";
    }
    
    cout << "\n";
    find(m_map, "one");
    find(m_map, "ten");
}
//===============================================
int main(int argc, char** argv) {
    cout << "-------------------------------------------------\n";
    iterator1();
    cout << "-------------------------------------------------\n";
    iterator2();
    cout << "-------------------------------------------------\n";
    iterator3();
    cout << "-------------------------------------------------\n";
    return 0;
}
//===============================================
