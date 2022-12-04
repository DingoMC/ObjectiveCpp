#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;
class Student {
    public:
        string imie, nazwisko, email;
        char plec;
        float ocena;
        Student(const string &imie1, const string &nazwisko1, char plec1, float ocena1, const string &email1) : imie(imie1), nazwisko(nazwisko1), plec(plec1), ocena(ocena1), email(email1) {}
        void show () {
            cout<<left<<setw(20)<<setfill('_')<<this->imie;
            cout<<left<<setw(20)<<setfill('_')<<this->nazwisko;
            cout<<left<<setw(8)<<setfill('_')<<this->plec;
            cout<<left<<setw(9)<<setfill('_')<<fixed<<setprecision(1)<<this->ocena;
            cout<<left<<setw(20)<<setfill('_')<<this->email<<endl;
        }
};
void openFile (ifstream &p, string n = "dane.csv") {
    p.open(n);
    if (!p) throw runtime_error("Could not open file!");
    cout<<"Znaleziono: "<<n<<endl;
}
bool checkName (string n) {
    if (n.length() < 1) return false;
    if (n.at(0) < 65 || n.at(0) > 90) return false;
    for (int i = 1; i < n.length(); i++) {
        if (n.at(i) < 97 || n.at(i) > 122) return false;
    }
    return true;
}
bool checkSex (char s) {
    return (s == 'K' || s == 'M');
}
bool checkMark (float o) {
    return (o >= 2.0 && o <= 5.0);
}
bool checkEmail (string e) {
    if (e.length() == 0) return true;
    for (int i = 0; i < e.length(); i++) {
        if (e.at(i) == '@') return true;
    }
    return false;
}
int countWithSurname (vector <Student> k, const string &s) {
    int cnt = 0;
    for (int i = 0; i < k.size(); i++) {
        if (k[i].nazwisko == s) cnt++;
    }
    return cnt;
}
void showHeaders () {
    cout<<left<<setw(20)<<"[Imie]";
    cout<<left<<setw(20)<<"[Nazwisko]";
    cout<<left<<setw(8)<<"[Plec]";
    cout<<left<<setw(9)<<"[Ocena]";
    cout<<left<<setw(20)<<"(E-mail)"<<endl;
}
bool markCompare (Student s1, Student s2) {
    return s1.ocena < s2.ocena;
}
int main () {
    vector <Student> k;
    ifstream p;
    string fname = "";
    int line_count = 0;
    cout<<"Podaj nazwe pliku [dane.csv]: ";
    getline(cin, fname);
    try {
        if (fname.length() != 0) openFile(p, fname);
        else {
            fname = "dane.csv";
            openFile(p);
        }
    }
    catch (exception &ex) {
        cout<<"Blad odczytu pliku!"<<endl;
        cin.ignore();
        cin.get();
        return 0;
    }
    string line, field;
    getline(p, line); // Pierwsza linia - naglowki
    while (getline(p, line)) {
        stringstream str(line);
        string imie, nazwisko, email = "";
        char plec;
        float ocena;
        int i = 0;
        while (getline(str, field, ';')) {
            if (i == 0) imie = field;
            if (i == 1) nazwisko = field;
            if (i == 2) plec = field.at(0);
            if (i == 3) ocena = stof(field);
            if (i == 4) email = field;
            i++;
        }
        k.push_back(Student(imie, nazwisko, plec, ocena, email));
        line_count++;
    }
    p.close();
    cout<<"Wczytanych wierszy: "<<line_count<<endl;
    bool end = false;
    unsigned opcja = 1;
    while (!end) {
        do {
            if (!cin) {
                cout<<"Nieprawidlowa opcja!"<<endl;
                cin.clear();
                cin.ignore();
            }
            cout<<"Podaj opcje (1~7): ";
            cin>>opcja;
        } while (!cin);
        switch (opcja) {
            case 1: {
                cout<<"Znalezionych wierszy: "<<fixed<<setprecision(0)<<k.size()<<endl;
                showHeaders();
                for (int i = 0; i < k.size(); i++) k[i].show();
                break;
            }
            case 2: {
                string imie;
                do {
                    cout<<"Podaj imie: ";
                    cin>>imie;
                    if (!checkName(imie)) {
                        cin.clear();
                        cout<<"Nieprawidlowe imie!"<<endl;
                    }
                } while (!checkName(imie));
                string nazwisko;
                do {
                    cout<<"Podaj nazwisko: ";
                    cin>>nazwisko;
                    if (!checkName(nazwisko)) {
                        cin.clear();
                        cout<<"Nieprawidlowe nazwisko!"<<endl;
                    }
                } while (!checkName(nazwisko));
                char plec;
                do {
                    cout<<"Podaj plec (K/M): ";
                    cin>>plec;
                    if (!checkSex(plec) || !cin) {
                        cin.clear();
                        cin.ignore();
                        cout<<"Nieprawidlowa plec!"<<endl;
                    }
                } while (!checkSex(plec) || !cin);
                float ocena;
                do {
                    cout<<"Podaj ocene (2.0 ~ 5.0): ";
                    cin>>ocena;
                    if (!checkMark(ocena) || !cin) {
                        cin.clear();
                        cin.ignore();
                        cout<<"Nieprawidlowa ocena!"<<endl;
                    }
                } while (!checkMark(ocena) || !cin);
                string email;
                do {
                    cin.ignore();
                    cout<<"Podaj E-mail [opcjonalny]: ";
                    getline(cin, email);
                    if (email.length() == 0) email = "";
                    if (!checkEmail(email)) {
                        cin.clear();
                        cin.ignore();
                        cout<<"Nieprawidlowy email!"<<endl;
                    }
                } while (!checkEmail(email));
                k.push_back(Student(imie, nazwisko, plec, ocena, email));
                fstream zapis;
                zapis.open(fname, ios::app);
                zapis<<endl<<imie<<";"<<nazwisko<<";"<<plec<<";"<<fixed<<setprecision(1)<<ocena<<";"<<email;
                zapis.close();
                cout<<"Zapisano"<<endl;
                break;
            }
            case 3: {
                string nazwisko;
                do {
                    cout<<"Podaj nazwisko: ";
                    cin>>nazwisko;
                    if (!checkName(nazwisko)) {
                        cin.clear();
                        cout<<"Nieprawidlowe nazwisko!"<<endl;
                    }
                } while (!checkName(nazwisko));
                cout<<"Znalezionych wierszy: "<<fixed<<setprecision(0)<<countWithSurname(k, nazwisko)<<endl;
                showHeaders();
                for (int i = 0; i < k.size(); i++) {
                    if (k[i].nazwisko == nazwisko) k[i].show();
                }
                break;
            }
            case 4: {
                fstream zapis;
                zapis.open("k.csv", ios::out);
                zapis<<"imie;nazwisko;plec;ocena;email";
                for (int i = 0; i < k.size(); i++) {
                    if (k[i].plec == 'K') zapis<<endl<<k[i].imie<<";"<<k[i].nazwisko<<";"<<k[i].plec<<";"<<fixed<<setprecision(1)<<k[i].ocena<<";"<<k[i].email;
                }
                zapis.close();
                zapis.open("m.csv", ios::out);
                zapis<<"imie;nazwisko;plec;ocena;email";
                for (int i = 0; i < k.size(); i++) {
                    if (k[i].plec == 'M') zapis<<endl<<k[i].imie<<";"<<k[i].nazwisko<<";"<<k[i].plec<<";"<<fixed<<setprecision(1)<<k[i].ocena<<";"<<k[i].email;
                }
                zapis.close();
                cout<<"Zapisano do k.csv i m.csv."<<endl;
                break;
            }
            case 5: {
                unsigned cnt;
                do {
                    cout<<"Podaj liczbe wierszy: ";
                    cin>>cnt;
                    if (!cin || cnt > k.size()) {
                        cin.clear();
                        cin.ignore();
                        cout<<"Nieprawidlowa wartosc!"<<endl;
                    }
                } while (!cin || cnt > k.size());
                cout<<"Wyswietlanie: "<<fixed<<setprecision(0)<<cnt<<endl;
                showHeaders();
                for (int i = 0; i < cnt; i++) k[i].show();
                break;
            }
            case 6: {
                sort(k.begin(), k.end(), markCompare);
                cout<<"Posortowano."<<endl;
                break;
            }
            case 7: {
                cout<<"Dowidzenia!"<<endl;
                end = true;
                break;
            }
            default: {cout<<"Nie ma takiej opcji!"<<endl; break;}
        }
    }
    cin.ignore();
    cin.get();
    return 0;
}