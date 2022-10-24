#include <iostream>
#include <vector>
#include <set>
using namespace std;
pair <int, int> getDuplicate (vector <int> arr) {
    set <int> s;
    int found = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (s.count(arr[i])) {
            found = arr[i];
            sum -= found;
        }
        else {
            s.insert(arr[i]);
            sum += arr[i];
        }
    }
    return {found, sum};
}
int main () {
    vector <int> arr = {0, 2, 5, 7, 8, 9, 7, 1, 3, 4, 6};
    cout<<"Zduplikowana wartosc: "<<getDuplicate(arr).first<<endl;
    cout<<"Suma unikatowych wartosci: "<<getDuplicate(arr).second<<endl;
    cin.ignore();
    cin.get();
    return 0;
}