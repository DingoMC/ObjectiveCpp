#include "student.h"
Student::Student (int mark, const string &name) {
    this->mark=mark;
    this->name=name;
}
int Student::getMark () {
    return mark;
}