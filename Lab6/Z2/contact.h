#ifndef CONTACT_H
#define CONTACT_H
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/member.hpp>
#include <iostream>
using namespace std;
class Contact {
    public:
        string imie;
        string nazwisko;
        int wiek;
        string tel;
        string ulica;
};
#endif // !CONTACT_H   