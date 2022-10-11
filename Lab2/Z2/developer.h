#ifndef DEVELOPER_H
#define DEVELOPER_H
#include "employee.h"
class Developer : public Employee {
    public:
        Developer (const string &sn, int a, int e, float s) : Employee(sn, a, e, s) {};
        float calculateBonus (int value) {return value + 0.2 * value * (getSalary() + getExperience());}      
};
#endif // !DEVELOPER_H