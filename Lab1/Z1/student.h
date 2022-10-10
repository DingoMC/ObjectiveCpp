#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "person.h"
class Student : public Person {
    private:
        string index;
    public:
        Student (string index1, string name1, string surname1, int age1) : Person(name1, surname1, age1) {
            index1 = index;
        }
        void setIndex(string newIndex) {
            index = newIndex;
        }
        string getIndex() {return index;}
        void showInfoStudent () {
            cout<<index<<" "<<endl;
        }
};

#endif // STUDENT_H_INCLUDED
