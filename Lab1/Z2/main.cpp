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
void howManyTrackerDogs (Dog *d, int n) {
    for (int i = 0; i < n; i++) {
        if (d[i].getSkillLevel(1) > d[i].getSkillLevel(0)) d[i].info();
    }
}
void howManyCats (Cat *c, int n) {
    for (int i = 0; i < n; i++) {
        int mice = 0;
        for (int j = 0; j < 5; j++) mice += c[i].getMice(j);
        cout<<"Liczba myszy zlapanych przez kota "<<i+1<<": "<<mice<<endl;
    }

}
int main () {
    Animal *A = new Animal[3];
    A[0] = Animal(4, "Cat", true);
    A[1] = Animal(4, "Dog", false);
    A[2] = Animal(4, "Horse", true);
    cout<<"Liczba chronionych zwierzat: "<<howManyProtectedAnimals(A, 3)<<endl;
    Dog *D = new Dog[3];
    D[0] = Dog("Buldog", 2, 4);
    D[1] = Dog("Jamnik", 5, 3);
    D[2] = Dog("Owczarek Niemiecki", 3, 6);
    howManyTrackerDogs(D, 3);
    Cat *C = new Cat[3];
    int **m = new int*[3];
    for (int i = 0; i < 5; i++) m[i] = new int[5];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) m[i][j] = i+j;
    }
    for (int i = 0; i < 3; i++) C[i].initCat(i, m[i]);
    howManyCats(C, 3);
    cin.ignore();
    cin.get();
    return 0;
}