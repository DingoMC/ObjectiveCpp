#include <QCoreApplication>
#include <iostream>
#include <QVector>
#include <QSet>
#include <QMap>
#include <QPair>
#include "car.h"
using namespace std;
string getRandomVIN () {
    string vin = "";
    for (int i = 0; i < 16; i++) {
        int rnd = 0;
        if (i < 10) rnd = rand() % 36;
        else rnd = rand() % 10;
        if (rnd < 10) vin += (char) (rnd + 48);
        else vin += (char) (rnd + 55);
    }
    return vin;
}
void show (QVector<Car> vec) {
    typename QVector<Car>::iterator p;
    for (p = vec.begin(); p != vec.end(); ++p) {
        Car s = *p;
        s.show();
    }
}
int CountOlderThan (QVector<Car> vec, int year) {
    int cnt = 0;
    typename QVector<Car>::iterator p;
    for (p = vec.begin(); p != vec.end(); ++p) {
        Car s = *p;
        if (s.getYear() < year) cnt++;
    }
    return cnt;
}
void DeleteByVIN (QVector<Car> &vec, string vin) {
    typename QVector<Car>::iterator p;
    int i = 0;
    for (p = vec.begin(); p != vec.end(); ++p) {
        Car s = *p;
        if (s.getVin() == vin) vec.remove(i);
        i++;
    }
}
class CompareYear {
public:
    bool operator() (Car c1, Car c2) {
        return c1.getYear() > c2.getYear();
    }
};
class CompareBrand {
public:
    bool operator() (Car c1, Car c2) {
        string b1 = c1.getBrand();
        string b2 = c2.getBrand();
        int l1 = b1.length(), l2 = b2.length();
        if (l1 > l2) {
            for (int i = l2; i < l1; i++) b2 += '0';
        }
        if (l1 < l2) {
            for (int i = l1; i < l2; i++) b1 += '0';
        }
        l1 = b1.length();
        for (int i = 0; i < l1; i++) {
            if (b1.at(i) < b2.at(i)) return true;
            if (b1.at(i) > b2.at(i)) return false;
        }
        return false;
    }
};
bool isPangram (string text) {
    int len = text.length();
    QSet<char> s;
    for (int i = 0; i < len; i++) {
        if (text.at(i) >= 65 && text.at(i) <= 90) s.insert((char) (text.at(i) + 32));
        if (text.at(i) >= 97 && text.at(i) <= 122) s.insert(text.at(i));
    }
    if (s.count() == 26) return true;
    return false;
}
void showCountries(QMap<string, int> k) {
    QMapIterator<string, int> i(k);
    while (i.hasNext()) {
        i.next();
        cout<<i.key()<<" - "<<i.value()<<endl;
    }
}
void showCountryNames(QMap<string, int> k) {
    QMapIterator<string, int> i(k);
    while (i.hasNext()) {
        i.next();
        cout<<i.key()<<endl;
    }
}
void showCountriesRange(QMap<string, int> k, int min, int max) {
    QMapIterator<string, int> i(k);
    while (i.hasNext()) {
        i.next();
        if (i.value() >= min && i.value() <= max) cout<<i.key()<<" - "<<i.value()<<endl;
    }
}
class CompareCountryASC {
public:
    bool operator() (QPair<string, int> c1, QPair<string, int> c2) {
        return c1.second < c2.second;
    }
};
class CompareCountryDESC {
public:
    bool operator() (QPair<string, int> c1, QPair<string, int> c2) {
        return c1.second > c2.second;
    }
};
void showCountriesByInhabitants (QMap<string, int> k, bool asc = true) {
    QMapIterator<string, int> i(k);
    QVector<QPair<string, int>> vec;
    while (i.hasNext()) {
        i.next();
        vec.append(QPair<string, int>(i.key(), i.value()));
    }
    if (asc) sort(vec.begin(), vec.end(), CompareCountryASC());
    else sort(vec.begin(), vec.end(), CompareCountryDESC());
    typename QVector<QPair<string, int>>::iterator p;
    for (p = vec.begin(); p != vec.end(); ++p) {
        QPair<string, int> s = *p;
        cout<<s.first<<" - "<<s.second<<endl;
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector<Car> katalog;
    srand(time(NULL));
    katalog.append(Car("Opel", "Astra", getRandomVIN(), 2002));
    katalog.append(Car("Toyota", "Verso", getRandomVIN(), 2012));
    katalog.append(Car("Fiat", "126P", getRandomVIN(), 1981));
    katalog.append(Car("BMW", "X3", "0AGSHS726SD123456", 2015));
    katalog.append(Car("Ford", "Focus", getRandomVIN(), 2003));
    katalog.append(Car("Audi", "A4", getRandomVIN(), 2006));
    show(katalog);
    cout<<CountOlderThan(katalog, 2005)<<endl;
    DeleteByVIN(katalog, "0AGSHS726SD123456");
    sort(katalog.begin(), katalog.end(), CompareYear());
    show(katalog);
    cout<<endl;
    sort(katalog.begin(), katalog.end(), CompareBrand());
    show(katalog);
    // Zadanie 2
    cout<<isPangram("The quick brown fox jumps over the lazy dog")<<endl;
    cout<<isPangram("qwertyuioplkjhgfdsazxcvbnm")<<endl;
    cout<<isPangram("zxcvbnmlkjhgfdsaqwertyuio")<<endl;
    // Zadanie 3
    QMap<string, int> kraje;
    kraje.insert("Indie", 1411415000);
    kraje.insert("Stany Zjednoczone", 337341954);
    kraje.insert("Indonezja", 277329163);
    kraje.insert("Pakistan", 242923845);
    kraje.insert("Nigeria", 225082083);
    kraje.insert("Brazylia", 217240060);
    showCountries(kraje);
    showCountryNames(kraje);
    showCountriesRange(kraje, 100000000, 300000000);
    kraje.remove("Indie");
    cout<<endl;
    showCountriesByInhabitants(kraje);
    return a.exec();
}
