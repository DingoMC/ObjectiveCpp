#ifndef STOL_H
#define STOL_H
#include "mebel.h"
class Stol : public Mebel {
    public:
        Stol (float w) : Mebel(w) {
            this->liczbaNog = 4;
        }
        float oblicz_koszt () {
            return 50.0 + this->waga * 2.0;
        }
};
#endif