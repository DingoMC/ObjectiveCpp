#ifndef CAT_H
#define CAT_H
#include <iostream>
#include "animal.h"
using namespace std;
class Cat : public Animal {
    private:
        int levelOfMouseHunting;
        int mice[5];
    public:
        Cat ();
        Cat (int ln, const string& n, bool p) : Animal::Animal(ln, n, p) {
            this->setLimbNr(ln);
            this->setName(n);
            this->setProtected(p);
        };
        void initMice (const int*);
        void initCat (int, const int*);
        void setLevelOfMouseHunting (int l) {this->levelOfMouseHunting = l;}
        int getLevelOfMouseHunting () {return this->levelOfMouseHunting;}
        int getMice (int i) {return this->mice[i];}
        void giveVoice () {cout<<"Miau, miau"<<endl;}
        void info (); 
};
#endif