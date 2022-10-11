#include <iostream>
#include <string>
#include "person.h"
#include "teacher.h"
#include "student.h"
using namespace std;
int main() {
    cout<<endl<<"Obiekty klasy Person"<<endl;
    Person o1("Grazyna","Nowak",45);
    o1.showInfoPerson();
    cout<<"Czy pelnoletnia?: "<<o1.is_18()<<endl;
    o1.setAge(16);
    cout<<endl<<"Obiekty klasy Teacher"<<endl;
    Teacher n1("Barbara","Kowalska",56,30,"Phd");
    n1.showInfoTeacher();
    cout<<"Czy ma Phd?: "<<n1.is_Phd()<<endl;
    n1.setAge(34);
    Person p1[3];
    Person* p2;
    Person* p3[3];
    Person** p4;
    for (int i=0; i<3; i++) {
        p1[i].init("Anna","Nowak",20+i);
        p1[i].showInfoPerson();
    }
    p2=new Person[3];
    for (int i=0; i<3; i++) {
        p2[i].init("Ola","Adamek",20+i);
        p2[i].showInfoPerson();
    }
    for(int i=0; i<3; i++) {
        p3[i]=new Person("Kasia","Kowalska",20+i);
        p3[i]->showInfoPerson();
    }
    p4=new Person*[3];
    for(int i=0; i<3; i++) {
        p4[i]=new Person("Pawel","Wojcik",20+i);
        p4[i]->showInfoPerson();
    }
    for(int i=0;i<3;i++) delete p3[i];
    for(int i=0;i<3;i++) delete p4[i];
    delete [] p4;
    Student SS[3];
    Student *DS;
    Student *SD[3];
    Student **DD;
    for (int i = 0; i < 3; i++) {
        SS->init("Anna", "Wanna", 18+i);
        SS->setIndex("1234" + to_string(i));
        SS->showInfoStudent();
    }
    DS = new Student[3];
    for (int i = 0; i < 3; i++) {
        DS->init("Katarzyna", "Zeszczecina", 19+i);
        DS->setIndex("2345" + to_string(i));
        DS->showInfoStudent();
    }
    for (int i = 0; i < 3; i++) {
        SD[i] = new Student("Czarek", "Jarek", 20+i);
        SD[i]->setIndex("3456" + to_string(i));
        SD[i]->showInfoStudent();
    }
    DD = new Student* [3];
    for (int i = 0; i < 3; i++) {
        DD[i] = new Student("Maciej", "Obiektowy", 21+i);
        DD[i]->setIndex("4567" + to_string(i));
        DD[i]->showInfoStudent();
    }
    for(int i = 0; i < 3; i++) delete SD[i];
    for(int i = 0; i < 3; i++) delete DD[i];
    delete [] DD;
    cin.ignore();
    cin.get();
    return 0;
}
