#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED
#include "person.h"
class Teacher : public Person {
    private:
        int experience;
        string title;
    public:
        Teacher(const string&, const string&, int age1,int experience1, const string&);
        Teacher();
        void setTitle(const string &title1);
        int getExperience();
        bool is_Phd();
        void showInfoTeacher();
};

#endif // TEACHER_H_INCLUDED
