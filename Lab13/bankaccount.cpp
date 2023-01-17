// Do zadania 13.4 //
#include "bankaccount.h"

BankAccount::BankAccount (string ln, string an, float bal) :
    last_name(ln), account_number(an), balance(bal) {

}
void BankAccount::add (float amount) {
    if (amount <= 0.00) throw runtime_error("Dodawana wartosc powinna byc dodatnia!");
    this->balance += amount;
}
void BankAccount::withdraw (float amount) {
    if (amount > this->balance) throw runtime_error("Brak odpowiednich srodkow na koncie!");
    this->balance -= amount;
}
bool BankAccount::isMillionaire () {
    return this->balance >= 1000000.00;
}
