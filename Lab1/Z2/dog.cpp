#include <iostream>
#include "dog.h"
using namespace std;
Dog::Dog () {

}
Dog::Dog (const string& b, int lG, int lT) {
    this->breed = b;
    this->levelOfGuideSkills = lG;
    this->levelOfTrackerSkills = lT;
}
void Dog::setSkillLevel (int type, int value) {
    if (value < 1 || value > 10) return;
    if (type == 0) this->levelOfGuideSkills = value;
    else this->levelOfTrackerSkills = value;
}
int Dog::getSkillLevel (int type) {
    if (type == 0) return this->levelOfGuideSkills;
    return this->levelOfTrackerSkills;
}
void Dog::giveVoice () {cout<<"Hau, hau"<<endl;}
void Dog::info () {
    cout<<"Rasa: "<<this->breed<<endl;
    cout<<"Poziom umiejetnosci przewodnika: "<<this->levelOfGuideSkills<<endl;
    cout<<"Poziom umiejetnosci tropiciela: "<<this->levelOfTrackerSkills<<endl;
}