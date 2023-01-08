#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void show (const vector <int> &Vec) {
    for_each(Vec.begin(), Vec.end(), [] (int el) -> void { cout<<el<<"|"; });
    cout<<endl;
}
double mean (const vector <int> &Vec) {
    double sum = 0.0;
    for_each(Vec.begin(), Vec.end(), [&sum] (int el) { sum += (el * 1.0); });
    return sum / (Vec.size() *  1.0);
}
unsigned countEven (const vector <int> &Vec) {
    return count_if(Vec.begin(), Vec.end(), [] (int el) { return (el % 2 == 0); });
}
void removeNegative (vector <int> &Vec) {
    Vec.erase(remove_if(Vec.begin(), Vec.end(), [] (int el) { return el < 0; }), Vec.end());
}
void sortByParity (vector <int> &Vec) {
    sort(Vec.begin(), Vec.end(), [] (int el, int el2) { return (el % 2 < el2 % 2); });
}
void replaceWithOpposite (vector <int> &Vec) {
    transform(Vec.begin(), Vec.end(), Vec.begin(), [] (int el) { return -el; });
}
unsigned countLessThan (const vector <int> &Vec, int val) {
    return count_if(Vec.begin(), Vec.end(), [val] (int el) { return (el < val); });
}
int main () {
    vector <int> A = {1, 2, 4, 5, -2, 0, 7};
    show(A);
    cout<<"Srednia: "<<mean(A)<<endl;
    cout<<"Ile parzystych: "<<countEven(A)<<endl;
    removeNegative(A);
    cout<<"Bez ujemnych: ";
    show(A);
    sortByParity(A);
    cout<<"Parzyste, nieparzyste: ";
    show(A);
    replaceWithOpposite(A);
    cout<<"Przeciwne: ";
    show(A);
    cout<<"< -2: "<<countLessThan(A, -2);
    cin.ignore();
    cin.get();
    return 0;
}