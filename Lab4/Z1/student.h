#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
class Student {
    private:
        int mark;
        string name;
    public:
        Student (int mark, const string &name);
        int getMark ();
};
#endif // STUDENT_H