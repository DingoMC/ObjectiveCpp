#ifndef MEBEL_H
#define MEBEL_H
#include <iostream>
using namespace std;
class Mebel {
    protected:
        float waga;
        int liczbaNog;
    public:
        Mebel (float w) : waga(w) {}
        virtual float oblicz_koszt() = 0;
        virtual void show() {
            cout<<"Liczba nog: "<<this->liczbaNog<<endl;
        }
        virtual ~Mebel() {
            
        }
        int getLiczbaNog () {return this->liczbaNog;}
};
#endif