#include <iostream>
#include <vector>
#include <map>
#include "city.h"
using namespace std;
void City::deleteCitizen(const std::string &surname, int age) {
    unsigned c = this->citizens.size();
    for (unsigned i = 0; i < c; i++) {
        if (surname == this->citizens[i].getSurname() && age == this->citizens[i].getAge()) this->citizens.erase(this->citizens.begin()+i);
    }
}
void City::showCitizens() {
    unsigned c = this->citizens.size();
    for (unsigned i = 0; i < c; i++) this->citizens[i].show();
}
unsigned City::women() {
    unsigned c = this->citizens.size(), w = 0;
    for (unsigned i = 0; i < c; i++) {
        if (this->citizens[i].getSex() == 'W') w++;
    }
    return w;
}
unsigned City::adults() {
    unsigned c = this->citizens.size(), a = 0;
    for (unsigned i = 0; i < c; i++) {
        if (this->citizens[i].getAge() >= 18) a++;
    }
    return a;
}
// Mode 1 - Show console output, 0 - Don't show console output
unsigned City::postal_codes(int mode) {
    unsigned u = 0;
    map <string, int> m;
    unsigned c = this->citizens.size();
    for (unsigned i = 0; i < c; i++) {
        string kod = this->citizens[i].getPostalCode();
        ++m[kod];
    }
    for (map<string,int>::iterator i = m.begin(); i != m.end(); ++i) {
        if (mode == 1) cout<<i->first<<" -> ";
        if (i->second == 1) {
            if (mode == 1) cout<<"unikatowy"<<endl;
            u++;
        }
        else {
            if (mode == 1) cout<<i->second<<" mieszkancow"<<endl;
        }
    }
    return u;
}