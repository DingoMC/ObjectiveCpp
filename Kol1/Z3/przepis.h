#ifndef PRZEPIS_H
#define PRZEPIS_H
#include <iostream>
#include <map>
using namespace std;
class Przepis {
    private:
        string nazwa;
        map <string, float> skladniki;
    public:
        Przepis (string n, map <string, float> s) : nazwa(n), skladniki(s) {}
        void zamiennik (string istniejacy, string nowy) {
            if (this->skladniki.find(istniejacy) == this->skladniki.end()) {
                cout<<"Nie ma takiego skladnika!"<<endl;
            }
            else {
                map<string, float>::iterator it = this->skladniki.find(istniejacy);
                skladniki.insert(make_pair(nowy, it->second));
                skladniki.erase(istniejacy);
            }
        }
        void show () {
            cout<<nazwa<<":"<<endl;
            for (map<string, float>::iterator i = this->skladniki.begin(); i != this->skladniki.end(); ++i) {
                cout<<i->first<<" - "<<i->second<<endl;
            }
        }
};
#endif