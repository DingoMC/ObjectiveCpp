#include <iostream>
#include "animal.h"
#include "dog.h"
#include "cat.h"
using namespace std;

int howManyProtectedAnimals (Animal *a, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {if (a[i].getProtected()) cnt++;}
    return cnt;
}
int howManyTrackerDogs (Dog *d, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {if (d[i].getSkillLevel(1) > d[i].getSkillLevel(0)) cnt++;}
}
int howManyCats (Cat *c, int n) {
    for (int i = 0; i < n; i++) {
        int mice = 0;
        for (int j = 0; j < 5; j++) mice += c[i].getMice(j);
        cout<<"Liczba myszy kota "<<i+1<<": "<<mice<<endl;
    }
}
int main () {
    cin.ignore();
    cin.get();
    return 0;
}