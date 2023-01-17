// Do zadania 13.4 //
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
using namespace std;
class BankAccount {
    private:
        string last_name;
        string account_number;
        float balance;
    public:
        BankAccount (string ln, string an, float bal);
        void add (float amount);
        void withdraw (float amount);
        bool isMillionaire ();
        inline void setLastName (string ln) { this->last_name = ln; }
        inline void setAccountNumber (string an) { this->account_number = an; }
        inline void setBalance (float bal) { this->balance = bal; }
        inline string getLastName () { return this->last_name; }
        inline string getAccountNumber () { return this->account_number; }
        inline float getBalance () { return this->balance; }
};

#endif // BANKACCOUNT_H
