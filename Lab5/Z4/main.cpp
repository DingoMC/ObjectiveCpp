#include <iostream>
#include "dictionary.h"
using namespace std;
int main () {
    Dictionary dict;
    dict.show();                    // Blad - pusty slownik
    dict.add("Pies", "Dog");
    dict.add("Kot", "Cat");
    dict.add("dcba", "abcd");
    dict.add("edcba", "abcde");
    dict.show();
    dict.getTranslation("kot");
    dict.getTranslation("mysz");    // Blad - brak slowa w slowniku
    dict.add("Mysz", "Mouse");
    dict.remove("Krolik");          // Blad - brak slowa w slowniku
    dict.remove("pies");
    dict.showZToA();
    cin.ignore();
    cin.get();
    return 0;
}