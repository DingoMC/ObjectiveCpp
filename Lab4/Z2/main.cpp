#include <iostream>
#include <list>
#include <random>
#include <algorithm>
using namespace std;
void show (int el) {
    cout<<el<<" ";
}
int main () {
    srand(time(NULL));
    unsigned n = 1 + rand() % 100;
    list <int> liczby;
    for (int i = 0; i < n; i++) {
        int liczba = -100 + rand() % 201;
        if (liczba >= 0) liczby.push_front(liczba);
        else liczby.push_back(liczba);
    }
    for_each(liczby.begin(), liczby.end(), show);
    cin.ignore();
    cin.get();
    return 0;
}