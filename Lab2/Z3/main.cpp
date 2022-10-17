#include <iostream>
#include "bufor.h"
#include "meanbufor.h"
#include "maxbufor.h"
#pragma GCC optimize("O2")
using namespace std;
int main () {
    Bufor* b = new MaxBufor(10);
    Bufor* b2 = new MeanBufor(10);
    b->add(5);
    b->add(7);
    cout<<"Max bufor: "<<b->calculate()<<endl;
    b2->add(9);
    b2->add(3);
    b2->add(5);
    b2->show();
    cout<<"Mean bufor: "<<b2->calculate()<<endl;
    Bufor *b3 = new MaxBufor(2);
    b3->add(5);
    b3->add(8);
    b3->add(14); // Error
    b3->show();
    cin.ignore();
    cin.get();
    return 0;
}