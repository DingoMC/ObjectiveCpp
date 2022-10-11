#include <iostream>
#include "person.h"
using namespace std;
Person::Person(const string &name1, const string &surname1, int age1) : name(name1), surname(surname1), age(age1) {
    cout<<"Konstruktor klasy bazowej - Person"<<endl;
}
Person::Person() {cout<<"Konstruktor bez. klasy bazowej - Person"<<endl;}
void Person::setAge(int age1) {age = age1;}
string Person::getSurname() {return surname;}
string Person::getName() {return name;}
bool Person::is_18() {return age >= 18;}
void Person::showInfoPerson() {cout<<"Imie: "<<name<<" nazwisko: "<<surname<<"wiek: "<<age<<endl;}
void Person::init(const string &name1, const string &surname1, int age1) {
    name = name1;
    surname = surname1;
    age = age1;
}
