#include <iostream>
#include <regex>
#include <string>
#include <fstream>
using namespace std;
string toLower (string str) {
    string f = "";
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) >= 65 && str.at(i) <= 90) f += (char) (str.at(i) + 32);
        else f += str.at(i);
    }
    return f;
}
bool isName (string str) {
    return regex_match(str, regex("[A-Z][a-z]+"));
}
bool isSurname (string str) {
    return regex_match(str, regex("[A-Z][a-z]+(-[A-Z][a-z]+)?"));
}
bool isAge (string str) {
    return regex_match(str, regex("([0]|[1-9][0-9]?)"));
}
bool isPhoneNo (string str) {
    return regex_match(str, regex("[1-9][0-9]{8}"));
}
bool isEmail (string str) {
    return regex_match(toLower(str), regex("[a-z][a-z0-9_\\.\\-]+\\@[a-z0-9]+\\.[a-z0-9]{2,3}"));
}
int main () {
    string name, surname, age, phone, email;
    do {
        cout<<"Podaj imie: ";
        cin>>name;
    } while (!isName(name));
    do {
        cout<<"Podaj nazwisko: ";
        cin>>surname;
    } while (!isSurname(surname));
    do {
        cout<<"Podaj wiek (0 ~ 99): ";
        cin>>age;
    } while (!isAge(age));
    do {
        cout<<"Podaj nr telefonu: ";
        cin>>phone;
    } while (!isPhoneNo(phone));
    do {
        cout<<"Podaj email: ";
        cin>>email;
    } while (!isEmail(email));
    cout<<"Dane poprawne!"<<endl;
    string fn;
    cout<<"Podaj nazwe pliku do zapisu: ";
    cin>>fn;
    fstream f;
    f.open(fn, ios::app);
    f<<name<<";"<<surname<<";"<<age<<";"<<phone<<";"<<email<<endl;
    f.close();
    cout<<"Zapisano!"<<endl;
    cin.ignore();
    cin.get();
    return 0;
}