#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>
using namespace std;
class Person {
    private:
        string name;
        string surname;
        int age;
    public:
        Person(const string&, const string&, int);
        Person();
        void setAge(int);
        string getSurname();
        string getName();
        bool is_18();
        void showInfoPerson();
        void init(const string&, const string&, int);
};
#endif // PERSON_H_INCLUDED
