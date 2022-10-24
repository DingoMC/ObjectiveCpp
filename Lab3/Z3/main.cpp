#include <iostream>
#include "array.h"
using namespace std;
int main () {
    Array <int> *a1 = new Array<int>();
    a1->append(5);
    a1->append(2);
    a1->append(3);
    a1->append(7);
    cout<<"Max a1: "<<a1->array_max()<<endl;
    cout<<"a1[2]: "<<a1->elem_at(2)<<endl;
    a1->show();
    a1->sort_asc();
    a1->show();
    Array <double> a2(15);
    a2.append(3.7);
    a2.append(4.2);
    a2.append(6.1);
    a2.append(1.2);
    cout<<"Max a2: "<<a2.array_max()<<endl;
    cout<<"a2[1]: "<<a2.elem_at(1)<<endl;
    a2.show();
    a2.sort_asc();
    a2.show();
    Array <string> a3(4);
    a3.append("abc");
    a3.append("abcde");
    a3.append("ab");
    a3.append("abcd");
    a3.append("abcdef");
    cout<<a3.elem_at(6)<<endl;
    cout<<"Max a3: "<<a3.array_max()<<endl;
    cout<<"a3[3]: "<<a3.elem_at(3)<<endl;
    a3.show();
    a3.sort_asc();
    a3.show();
    cin.ignore();
    cin.get();
    return 0;
}