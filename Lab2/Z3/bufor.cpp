#include <iostream>
#include "bufor.h"
using namespace std;
Bufor::Bufor () {
    s = 10;
    tab = new int[s];
    iterFirstFree = 0;
}
Bufor::Bufor (unsigned tabSize) {
    s = tabSize;
    tab = new int[tabSize];
    iterFirstFree = 0;
}
void Bufor::add (int value) {
    tab[iterFirstFree] = value;
    iterFirstFree++;
}
void Bufor::show () {
    cout<<"[ ";
    for (int i = 0; i < iterFirstFree; i++) cout<<tab[i]<<" ";
    cout<<"]"<<endl;
}