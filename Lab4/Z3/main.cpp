#include <iostream>
#include <vector>
#include <random>
#include <string>
#include "city.h"
using namespace std;
string randomName () {
    const char SMG_D[6] = {'A', 'E', 'I', 'O', 'U', 'Y'};
    const char SMG_M[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    const char SPG_D[17] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'R', 'S', 'T', 'W', 'Z'};
    const char SPG_M[17] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'r', 's', 't', 'w', 'z'};
    int len = 3 + rand() % 10;
    bool sm = rand () % 2;
    string name = "";
    for (unsigned i = 0; i < len; i++) {
        if (i == 0) {
            if (!sm) name += SPG_D[rand()%17];
            else name += SMG_D[rand()%6];
        }
        else {
            if (!sm) name += SPG_M[rand()%17];
            else name += SMG_M[rand()%6];
        }
        sm = !sm;
    }
    return name;
}
char randomSex () {
    const char Sex[2] = {'M', 'W'};
    return Sex[rand()%2];
}
int randomAge () {
    return rand()%100;
}
string randomPostalCode () {
    int f_begin = 8, f_end = 11, s_begin = 99, s_end = 101;
    string code = "";
    unsigned f = f_begin + rand() % (f_end - f_begin + 1);
    if (f < 10) code += "0";
    code += to_string(f) + "-";
    unsigned s = s_begin + rand() % (s_end - s_begin + 1);
    if (s < 100) code += "0";
    if (s < 10) code += "0";
    code += to_string(s);
    return code;
}
void showCities (vector <City> c) {
    for (int i = 0; i < c.size(); i++) {
        c[i].showCity();
        c[i].showCitizens();
        cout<<"Liczba mieszkancow: "<<c[i].cityCitizens()<<endl;
        cout<<"Dorosli: "<<c[i].adults()<<endl;
        cout<<"Kobiety: "<<c[i].women()<<endl;
        unsigned u = c[i].postal_codes(1);
        cout<<"Unikatowe adresy: "<<u<<endl;
        cout<<endl;
    }
}
void theMost (vector <City> c, int mode) {
    if (mode == 1) {
        unsigned max_index = 0;
        unsigned pc_max = c[0].postal_codes(0);
        for (unsigned i = 1; i < c.size(); i++) {
            if (c[i].postal_codes(0) > pc_max) {
                pc_max = c[i].postal_codes(0);
                max_index = i;
            }
        }
        cout<<"Miasto o najwiekszej liczbie unikatowych kodow pocztowych: ";
        c[max_index].showCity();
        return;
    }
    if (mode == 2) {
        unsigned min_index = 0;
        unsigned m_min = c[0].cityCitizens();
        for (unsigned i = 1; i < c.size(); i++) {
            if (c[i].cityCitizens() < m_min) {
                m_min = c[i].cityCitizens();
                min_index = i;
            }
        }
        cout<<"Miasto o najmniejszej liczbie mieszkancow: ";
        c[min_index].showCity();
        return;
    }
}
void statistic (vector <City> c) {
    for (unsigned i = 0; i < c.size(); i++) {
        c[i].showCity();
        cout<<"Liczba mieszkancow: "<<c[i].cityCitizens()<<endl;
        cout<<"Kobiety/Mezczyzni: "<<c[i].women()<<" / "<<(c[i].cityCitizens()-c[i].women())<<endl;
        cout<<"Pelnoletni/Niepelnoletni: "<<c[i].adults()<<" / "<<(c[i].cityCitizens()-c[i].adults())<<endl;
    }
}
void sortCities (vector <City> &c) {
    for (unsigned i = 0; i < c.size(); i++) {
        for (unsigned j = i; j < c.size(); j++) {
            if (c[i].cityCitizens() > c[j].cityCitizens()) swap(c[i], c[j]);
        }
    }
}
int main () {
    srand(time(NULL));
    vector <City> c;
    c.push_back(City("Lublin"));
    c.push_back(City("Warszawa"));
    c.push_back(City("Swidnik"));
    for (int i = 0; i < 5; i++) {
        Citizen ct(randomName(), randomName(), randomAge(), randomSex(), randomPostalCode());
        c[0].addCitizen(ct);
    }
    for (int i = 0; i < 10; i++) {
        Citizen ct(randomName(), randomName(), randomAge(), randomSex(), randomPostalCode());
        c[1].addCitizen(ct);
    }
    for (int i = 0; i < 3; i++) {
        Citizen ct(randomName(), randomName(), randomAge(), randomSex(), randomPostalCode());
        c[2].addCitizen(ct);
    }
    showCities(c);
    theMost(c, 1);
    theMost(c, 2);
    statistic(c);
    cout<<endl;
    sortCities(c);
    for (int i = 0; i < c.size(); i++) c[i].showCity();
    cin.ignore();
    cin.get();
    return 0;
}