#include <iostream>
#include "bufor.h"
#include "meanbufor.h"
#include "maxbufor.h"
#pragma GCC optimize("O2")
using namespace std;
int main () {
    MaxBufor b(10);
    MeanBufor b2(10);
    b.add(7);
    b.add(15);
    b.show();
    cin.ignore();
    cin.get();
    return 0;
}