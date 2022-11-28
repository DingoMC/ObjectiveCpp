#include <iostream>
#include <algorithm>
#include "mebel.h"
#include "stol.h"
#include "lawka.h"
using namespace std;
pair <int, float> zamowienie (Mebel **meble, int n) {
    int sumaNog = 0;
    float lacznyKoszt = 0.00;
    for (int i = 0; i < 15; i++) {
        sumaNog += meble[i]->getLiczbaNog();
        lacznyKoszt += meble[i]->oblicz_koszt();
    }
    return make_pair(sumaNog, lacznyKoszt);
}
int main () {
    Mebel **meble = new Mebel*[15];
    for (int i = 0; i < 5; i++) meble[i] = new Stol(i * 20);
    for (int i = 5; i < 15; i++) meble[i] = new Lawka(i * 5);
    pair <int, float> z = zamowienie(meble, 15);
    cout<<"Liczba nog: "<<z.first<<endl;
    cout<<"Laczny koszt: "<<z.second<<endl;
    cin.ignore();
    cin.get();
    return 0;
}