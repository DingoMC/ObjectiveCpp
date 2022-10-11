#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "person.h"
class Student : public Person {
    private:
        string index;
    public:
        Student () {

        }
        Student (const string &name1, const string &surname1, int age1) : Person(name1, surname1, age1) {
            cout<<"Konstruktor klasy Student"<<endl;
        }
        void setIndex(const string &newIndex) {
            index = newIndex;
        }
        string getIndex() {return index;}
        void showInfoStudent () {
            cout<<getName()<<" "<<getSurname()<<" - "<<index<<endl;
        }
};

#endif // STUDENT_H_INCLUDED
