#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <vector>
#include "citizen.h"
using namespace std;
class City {
    private:
        vector <Citizen> citizens;
        string city_name;
    public:
        City (const string &Name) : city_name(Name) {}
        void addCitizen (Citizen newCitizen) {citizens.push_back(newCitizen);}
        void deleteCitizen (const string &surname, int age);
        void showCitizens ();
        inline void showCity () {cout<<this->city_name<<endl;}
        unsigned women ();
        inline unsigned cityCitizens () {return this->citizens.size();}
        unsigned adults ();
        unsigned postal_codes (int mode);
};
#endif // !CITY_H