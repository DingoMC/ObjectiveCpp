#include <iostream>
#include <vector>
#include <memory>
#include "warehouse.h"
#include "shop.h"
using namespace std;
int main () {
    vector <shared_ptr<Warehouse>> Magazyny;
    vector <unique_ptr<Shop>> Sklepy;
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Krzeslo", 5)));
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Stol", 3)));
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Lampa", 4)));
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Biurko", 3)));
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Fotel", 5)));
    Magazyny.push_back(shared_ptr<Warehouse>(new Warehouse("Szafa", 4)));
    for (int i = 0; i < 4; i++) {
        string sname = "Sklep ";
        sname += (char) (i + 49);
        Sklepy.push_back(unique_ptr<Shop>(new Shop(sname)));
        for (int j = i; j < i + 3; j++) Sklepy[i]->addWarehouse(Magazyny[j]);
        Sklepy[i]->show();
        Sklepy[i]->showWarehouses();
    }
    Sklepy[0]->sellProduct("Lampa", 3);
    Sklepy[0]->showWarehouses();
    Sklepy[1]->sellProduct("Lampa", 2); // Brak produktow
    cin.ignore();
    cin.get();
    return 0;
}