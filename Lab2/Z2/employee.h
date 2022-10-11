#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;
class Employee {
    private:
        string surname;
        int age;
        int experience;
        float salary;
    public:
        Employee();
        Employee(const string &sn, int a, int e, float s) : surname(sn), age(a), experience(e), salary(s) {}
        virtual ~Employee() { cout<<"Pracownik zniszczony"<<endl; }
        virtual void show ();
        virtual float calculateBonus (int value) = 0;
        int ageEmployment () {return age - experience;}
        string getSurname () {return surname;}
        int getAge () {return age;}
        int getExperience () {return experience;}
        float getSalary () {return salary;}
};
#endif