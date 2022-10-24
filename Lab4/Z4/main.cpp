#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;
int digitSum (int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int digits (int n) {
    int d = 1;
    while (n >= 10) {
        d++;
        n /= 10;
    }
    return d;
}
bool compare1 (int i, int j) {
    return digitSum(i) < digitSum(j);
}
bool compare2 (int i, int j) {
    return digits(i) > digits(j);
}
void show (int el) {
    cout<<el<<"  ";
}
int main () {
    srand(time(NULL));
    vector <int> n;
    n.resize(10);
    for (int i = 0; i < 10; i++) n[i] = rand() % 120;
    for_each(n.begin(), n.end(), show);
    cout<<endl<<"Dane posortowane rosnoco wg sumy cyfr:"<<endl;
    sort(n.begin(), n.end(), compare1);
    for_each(n.begin(), n.end(), show);
    cout<<endl<<"Dane posortowane malejaco wg liczby cyfr:"<<endl;
    sort(n.begin(), n.end(), compare2);
    for_each(n.begin(), n.end(), show);
    cout<<endl;
    cin.ignore();
    cin.get();
    return 0;
}