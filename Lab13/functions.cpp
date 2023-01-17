#include "functions.h"
// Do zadania 13.1 //
bool isEven (int n) {
    return (n % 2 == 0);
}
int sign (int n) {
    if (n < 0) return -1;
    if (n > 0) return 1;
    return 0;
}

vector<int> difference (vector<int> vec) {
    vector<int> res;
    for(int i = 1; i < vec.size(); i++) res.push_back(vec[i]-vec[i-1]);
    return res;
}

void show (string line) {
    if (line.empty()) throw runtime_error("Pusty napis");
    cout<<"Podany napis to: "<<line<<endl;
}
// Do zadania 13.2 //
bool isPrime (int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
// Do zadania 13.3 //
float reciprocal (float n) {
    if (n == 0) throw runtime_error("Blad dzielenia przez 0!");
    return 1.0 / n;
}
