#include <iostream>
#include <algorithm>
#include <map>
#include "ksiazka.h"
#include "przepis.h"
using namespace std;
KsiazkaKucharska changeAll (KsiazkaKucharska k, string s1, string s2) {
    for (int i = 0; i < k.Przepisy.size(); i++) {
        k.Przepisy[i].zamiennik(s1, s2);
    }
    return k;
}
int main () {
    KsiazkaKucharska k(2020);
    map<string, float> m1;
    m1.insert(make_pair("Jajka", 2));
    m1.insert(make_pair("Maka zytnia", 200));
    m1.insert(make_pair("Cukier", 100));
    map<string, float> m2;
    m2.insert(make_pair("Jajka", 3));
    m2.insert(make_pair("Maka zytnia", 400));
    m2.insert(make_pair("Sol", 15));
    k.dodaj(Przepis("Nalesniki", m1));
    k.dodaj(Przepis("Placki", m2));
    k.show();
    k = changeAll(k, "Maka zytnia", "Maka pszenna");
    cout<<endl<<"Po zmianie maki: "<<endl;
    k.show();
    cin.ignore();
    cin.get();
    return 0;
}