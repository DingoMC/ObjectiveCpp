#include <iostream>
#include "cat.h"
void Cat::initMice (const int *m) {
    for (int i = 0; i < 5; i++) this->mice[i] = m[i];
}
void Cat::initCat (int l, const int *m) {
    this->levelOfMouseHunting = l;
    for (int i = 0; i < 5; i++) this->mice[i] = m[i];
}
void Cat::info () {
    cout<<"Poziom lowienia myszy: "<<this->levelOfMouseHunting<<endl;
    cout<<"Myszy zdobyte z okresu ostatnich 5 lat:";
    for (int i = 0; i < 5; i++) cout<<this->mice[i]<<" ";
    cout<<endl;
}