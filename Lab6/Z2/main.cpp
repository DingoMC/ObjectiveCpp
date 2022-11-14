#include <iostream>
#include "contacts.h"
using namespace std;
int main () {
    Contacts K;
    K.insert("Katarzyna", "Zeszczecina", 15, "012345678", "Gdanska");
    K.insert("Anna", "Wanna", 15, "123456789", "Prysznicowa");
    K.insert("Grazyna", "Zeszczecina", 37, "234567890", "Poznanska");
    K.insert("Lukasz", "Obiektowy", 42, "345678901", "Ceplusplusa");
    K.insert("Marcin", "Obiektowy", 65, "456789012", "Gdanska");
    K.insert("Kasia", "Zpodlasia", 80, "567890123", "Mazurska");
    K.insert("Jacek", "Beztacek", 19, "678901234", "Mickiewicza");
    K.insert("Marek", "Pieczarek", 18, "789012345", "Pieczarska");
    K.insert("Marek", "Pieczarek", 18, "789012345", "Pieczarska"); // Nie da się. Ten sam nr tel
    cout<<"Ksiazka: "<<endl;
    K.show();
    K.del("789012345");
    cout<<endl<<"Ksiazka bez Marka:"<<endl;
    K.show();
    cout<<endl<<"Osoby mieszkajace przy ul. Gdanskiej:"<<endl;
    K.findByStreet("Gdanska");
    cout<<endl<<"Osoby w wiekiem 20 - 70 lat:"<<endl;
    K.findByAge(20, 70);
    cout<<endl<<"Osoba o numerze tel. 678901234:"<<endl;
    K.findByPhone("678901234");
    K.changeStreetName("Gdanska", "Poznanska");
    cout<<endl<<"Ksiazka po zmianie z ul. Gdanskiej na Poznanska:"<<endl;
    K.show();
    cout<<endl<<"Liczba osob pelnoletnich: "<<K.CountAdults()<<endl;
    cout<<endl<<"Liczba unikatowych nazwisk: "<<K.CountUniqueSurnames()<<endl;
    cin.ignore();
    cin.get();
    return 0;
}