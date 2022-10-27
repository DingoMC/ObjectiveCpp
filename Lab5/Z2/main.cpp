#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
void show (set <int> s) {
    set <int>::iterator itr;
    cout<<"{ ";
    for (itr = s.begin(); itr != s.end(); itr++) cout<<*itr<<" ";
    cout<<"}"<<endl;
}
void set_XOR (set <int> s1, set <int> s2) {
    set <int> sUnion, sIntersec, sUDiffer;
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator(sUnion, sUnion.begin()));
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator(sIntersec, sIntersec.begin()));
    set_difference(sUnion.begin(), sUnion.end(), sIntersec.begin(), sIntersec.end(), insert_iterator(sUDiffer, sUDiffer.begin()));
    show(sUDiffer);
}
int main () {
    set <int> s1 = {1, 2, 3, 5, 7, 9};
    set <int> s2 = {4, 2, 6, 8, 5, 7};
    set_XOR(s1, s2);
    cin.ignore();
    cin.get();
    return 0;
}