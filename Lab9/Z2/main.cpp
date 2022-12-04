#include <iostream>
using namespace std;
void checkSum (unsigned s) {
    if (s > 21) throw runtime_error("Sum > 21!");
}
int main () {
    bool end = false;
    unsigned s = 0, l = 0, udane = 0, nieudane = 0;
    while (!end) {
        do {
            cin.clear();
            cin.ignore();
            cout<<"Podaj liczbe: ";
            cin>>l;
        } while (!cin);
        s += l;
        udane++;
        if (s == 21) {
            cout<<"Oczko!"<<endl;
            cout<<"Proby: udane - "<<udane<<", nieduane - "<<nieudane<<endl;
            end = true;
        }
        try {
            checkSum(s);
        }
        catch (exception &ex) {
            cout<<"Suma > 21!"<<endl;
            cout<<"Sprobuj ponownie!"<<endl;
            s -= l;
            if (udane > 0) udane--;
            nieudane++;
        }
    }
    cin.ignore();
    cin.get();
    return 0;
}