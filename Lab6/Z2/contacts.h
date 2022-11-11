#ifndef CONTACTS_H
#define CONTACTS_H
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/bind.hpp>
#include <set>
#include "contact.h"
using namespace boost::multi_index;
using namespace std;
typedef multi_index_container <Contact, indexed_by<
hashed_non_unique<member<Contact, string, &Contact::imie>>,
hashed_non_unique<member<Contact, string, &Contact::nazwisko>>,
hashed_non_unique<member<Contact, int, &Contact::wiek>>,
hashed_unique<member<Contact, string, &Contact::tel>>,
hashed_non_unique<member<Contact, string, &Contact::ulica>>
>> ksiazka;
typedef ksiazka::nth_index<3>::type tel_type;
typedef ksiazka::nth_index<4>::type ulica_type;
typedef ksiazka::nth_index<2>::type wiek_type;
typedef ksiazka::nth_index<1>::type nazwisko_type;
void newStreetName (Contact& x, string old_name, string new_name) {
    if (x.ulica == old_name) x.ulica = new_name;
}
class Contacts {
    public:
        ksiazka Ksiazka;
        void insert (string imie, string nazwisko, int wiek, string tel, string ulica) {
            if (Ksiazka.get<3>().count(tel) == 0) {
                Ksiazka.insert({imie, nazwisko, wiek, tel, ulica});
            }
        }
        void del (string tel) {
            tel_type &tel_index = Ksiazka.get<3>();
            auto it = tel_index.find(tel);
            tel_index.erase(it);
        }
        void findByStreet (const string &ulica) {
            for (ulica_type::iterator it = Ksiazka.get<4>().begin(); it != Ksiazka.get<4>().end(); ++it) {
                if (it->ulica == ulica) cout<<it->imie<<" "<<it->nazwisko<<" l."<<it->wiek<<", tel. "<<it->tel<<endl;
            }
        }
        void findByAge (int min, int max) {
            for (wiek_type::iterator it = Ksiazka.get<2>().begin(); it != Ksiazka.get<2>().end(); ++it) {
                if (it->wiek >= min && it->wiek <= max) cout<<it->imie<<" "<<it->nazwisko<<" l."<<it->wiek<<", tel. "<<it->tel<<endl;
            }
        }
        void findByPhone (const string &tel) {
            tel_type &tel_index = Ksiazka.get<3>();
            auto it = tel_index.find(tel);
            cout<<it->imie<<" "<<it->nazwisko<<" l."<<it->wiek<<", ulica: "<<it->ulica<<endl;
        }
        void changeStreetName (const string &old_name, const string &new_name) {
            vector<ulica_type::iterator> elements;
            auto &ulica_index = Ksiazka.get<4>();
            for (ulica_type::iterator it = Ksiazka.get<4>().begin(); it != Ksiazka.get<4>().end(); ++it) elements.push_back(it);
            for (int i = 0; i < elements.size(); i++) ulica_index.modify(elements[i], boost::bind(newStreetName, _1, old_name, new_name));
        }
        int CountAdults () {
            int cnt = 0;
            for (wiek_type::iterator it = Ksiazka.get<2>().begin(); it != Ksiazka.get<2>().end(); ++it) {
                if (it->wiek >= 18) cnt++;
            }
            return cnt;
        }
        int CountUniqueSurnames () {
            set <string> s;
            int cnt = 0;
            for (nazwisko_type::iterator it = Ksiazka.get<1>().begin(); it != Ksiazka.get<1>().end(); ++it) {
                if (s.find(it->nazwisko) == s.end()) {
                    s.insert(it->nazwisko);
                    cnt++;
                }
                else cnt--;
            }
            return cnt;
        }
        void show () {
            for (wiek_type::iterator it = Ksiazka.get<2>().begin(); it != Ksiazka.get<2>().end(); ++it) {
                cout<<it->imie<<" "<<it->nazwisko<<" l."<<it->wiek<<", tel. "<<it->tel<<", ul: "<<it->ulica<<endl;
            }
        }
};
#endif // !CONTACTS_H