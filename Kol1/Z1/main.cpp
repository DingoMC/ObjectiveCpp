#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
template <typename T>
set<T> CzescWspolna (set<T> S1, set<T> S2) {
    set <T> sIntersec;
    set_intersection(S1.begin(), S1.end(), S2.begin(), S2.end(), insert_iterator(sIntersec, sIntersec.begin()));
    return sIntersec;
}
int main () {
    set <string> s1 = {"Ab", "Abc", "Abcd", "Abcde"};
    set <string> s2 = {"Abcd", "Abcde", "Abcdef"};
    set <string> s3 = CzescWspolna(s1, s2);
    for (auto it = s3.cbegin(); it != s3.cend(); ++it) cout<<*it<<", ";
    cout<<endl;
    set <int> i1 = {1, 2, 3, 5, 7, 9};
    set <int> i2 = {2, 4, 6, 8};
    set <int> i3 = CzescWspolna(i1, i2);
    for (auto it = i3.cbegin(); it != i3.cend(); ++it) cout<<*it<<", ";
    cout<<endl;
    cin.ignore();
    cin.get();
    return 0;
}