#include <iostream>
#include "animal.h"
using namespace std;
Animal::Animal () {

}
Animal::Animal (int ln, const string &n, bool p) {
    this->limbNr = ln;
    this->name = n;
    this->protectedAnimal = p;
}
void Animal::setLimbNr (int ln) {this->limbNr = ln;}
void Animal::setName (const string &n) {this->name = n;}
void Animal::setProtected (bool p) {this->protectedAnimal = p;}
int Animal::getLimbNr () {return this->limbNr;}
string Animal::getName () {return this->name;}
bool Animal::getProtected () {return this->protectedAnimal;}
void Animal::giveVoice () {
    cout<<"Chrum, miau, hau, piiii"<<endl;
}
void Animal::info () {
    cout<<"Liczba konczyn: "<<this->limbNr<<endl;
    cout<<"Nazwa: "<<this->name<<endl;
    cout<<"Czy chroniony: "<<this->protectedAnimal<<endl;
}