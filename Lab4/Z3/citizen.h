#ifndef CITIZEN_H
#define CITIZEN_H
#include <iostream>
using namespace std;
class Citizen {
    private:
        string name, surname, postal_code;
        int age;
        char sex;
    public:
        Citizen ();
        Citizen (const string &Name, const string &Surname, int Age, char Sex, const string &Postal_Code) : name(Name), surname(Surname), age(Age), sex(Sex), postal_code(Postal_Code) {}
        void show () {cout<<this->name<<" "<<this->surname<<" - "<<this->age<<", "<<this->sex<<", "<<this->postal_code<<endl;}
        inline string getName () {return this->name;}
        inline string getSurname () {return this->surname;}
        inline string getPostalCode () {return this->postal_code;}
        inline int getAge () {return this->age;}
        inline char getSex () {return this->sex;}
};
#endif // !CITIZEN_H