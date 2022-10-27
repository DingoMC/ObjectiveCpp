#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
char findAdditional (string s1, string s2) {
    map <char, int> m1, m2;
    for (int i = 0; i < s1.length(); i++) ++m1[s1.at(i)];
    for (int i = 0; i < s2.length(); i++) ++m2[s2.at(i)];
    for (map<char, int>::iterator i = m2.begin(); i != m2.end(); ++i) {
        char key = i->first;
        int value = i->second;
        if (key != m1.find(key)->first || value != m1.find(key)->second) return key;
    }
    return 0;
}
int main () {
    string s1 = "abcbcacba";
    string s2 = "cabdbacabc";
    cout<<findAdditional(s1, s2)<<endl;
    cin.ignore();
    cin.get();
    return 0;
}