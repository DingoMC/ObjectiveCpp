#ifndef KSIAZKA_H
#define KSIAZKA_H
#include <iostream>
#include <vector>
#include "przepis.h"
using namespace std;
class KsiazkaKucharska {
    public:
        int rok;
        vector <Przepis> Przepisy;
        KsiazkaKucharska(int r) : rok(r) {}
        void dodaj (Przepis przepis) {
            Przepisy.push_back(przepis);
        }
        void dodaj (vector<Przepis> p) {
            for (int i = 0; i < p.size(); i++) Przepisy.push_back(p[i]);
        }
        void show () {
            cout<<"Ksiazka kucharska rok: "<<rok<<endl;
            for (int i = 0; i < this->Przepisy.size(); i++) this->Przepisy[i].show();
        }
};
#endif