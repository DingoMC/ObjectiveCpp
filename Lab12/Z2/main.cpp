#include <iostream>
#include <algorithm>
#include <vector>
#include "car.h"
using namespace std;
int main () {
    vector <Car> c;
    c.push_back(Car("Astra K", 2015, 1.4));
    c.push_back(Car("Vectra B", 2002, 1.8));
    c.push_back(Car("Insignia", 2017, 1.6));
    c.push_back(Car("Corsa F", 2019, 1.5));
    c.push_back(Car("Mokka", 2012, 1.6));
    sort(c.begin(), c.end(), [] (Car c1, Car c2) { return c1.getRok() < c2.getRok(); });
    int cnt = 1;
    for_each(c.begin(), c.end(), [&cnt] (Car el) { cout<<cnt<<": "; el.show(); cnt++; });
    sort(c.begin(), c.end(), [] (Car c1, Car c2) { return c1.getPojemnosc() > c2.getPojemnosc(); });
    cnt = 1;
    for_each(c.begin(), c.end(), [&cnt] (Car el) { cout<<cnt<<": "; el.show(); cnt++; });
    cin.ignore();
    cin.get();
    return 0;
}