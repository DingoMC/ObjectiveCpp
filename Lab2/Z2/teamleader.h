#ifndef TEAMLEADER_H
#define TEAMLEADER_H
#include "employee.h"
class TeamLeader : public Employee {
    public:
        TeamLeader (const string &sn, int a, int e, float s) : Employee(sn, a, e, s) {};
        float calculateBonus (int value) {return value * (1 + getSalary() + getExperience());}
        void show () override {
            cout<<getSurname()<<" l."<<getAge()<<" - staz pracy: "<<getExperience()<<", placa: "<<getSalary()<<endl;
            cout<<"Jestem Team Leader z "<<getExperience()<<" letnim doswiadczeniem"<<endl;
        }
};
#endif // !TEAMLEADER_H