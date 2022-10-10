#ifndef DOG_H
#define DOG_H
#include <iostream>
#include "animal.h"
using namespace std;
class Dog : public Animal {
    private:
        string breed;
        int levelOfGuideSkills;
        int levelOfTrackerSkills;
    public:
        Dog ();
        Dog (const string&, int, int);
        Dog (int ln, const string& n, bool p) : Animal::Animal(ln, n, p) {
            this->setLimbNr(ln);
            this->setName(n);
            this->setProtected(p);
        };
        void setSkillLevel (int, int);
        int getSkillLevel (int);
        void giveVoice ();
        void info ();
};
#endif