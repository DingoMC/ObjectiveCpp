#include <iostream>
#include <vector>
#include <algorithm>
#include "even.h"
#include "student.h"
#include "compare.h"
using namespace std;
void print (int el) {
    cout<<el<<"***";
}
void add10 (int &el) {
    el = el + 10;
}
bool isEven (int x) {
    return (x % 2) == 0;
}
void showMark (Student &s) {
    cout<<s.getMark()<<endl;
}
int main () {
    vector <int> num = {1, 2, 7, 0};
    for_each(num.begin(), num.end(), print);
    cout<<endl;
    cout<<count_if(num.begin(), num.end(), isEven)<<endl;
    cout<<count_if(num.begin(), num.end(), Even(2))<<endl;
    vector <Student> st;
    st.push_back(Student(1, "Ala"));
    st.push_back(Student(5, "Ola"));
    st.push_back(Student(2, "Piotr"));
    for_each(st.begin(),st.end(), showMark);
    cout<<endl;
    sort(st.begin(), st.end(), Compare());
    for_each(st.begin(), st.end(), showMark);
    cin.ignore();
    cin.get();
    return 0;
}