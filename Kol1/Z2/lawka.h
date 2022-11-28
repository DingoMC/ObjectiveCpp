#ifndef LAWKA_H
#define LAWKA_H
#include "mebel.h"
class Lawka : public Mebel {
    public:
        Lawka (float w) : Mebel(w) {
            this->liczbaNog = 6;
        }
        float oblicz_koszt () {
            return 20.0 + this->waga * 4.0;
        }
};
#endif