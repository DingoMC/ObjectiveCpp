#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;
class Animal {
    private:
        int limbNr;
        string name;
        bool protectedAnimal;
    public:
        Animal ();
        Animal (int, const string&, bool);
        void setLimbNr (int);
        void setName (const string&);
        void setProtected (bool);
        int getLimbNr ();
        string getName ();
        bool getProtected ();
        void giveVoice ();
        void info ();
};
#endif