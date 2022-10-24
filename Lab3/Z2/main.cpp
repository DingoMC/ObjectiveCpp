#include <iostream>
#pragma GCC optimize("O2")
using namespace std;
template <typename T>
T arrayMin (const T* arr, unsigned arr_size) {
    T min = arr[0];
    for (unsigned i = 1; i < arr_size; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}
int main () {
    int arr[5] = {3, 2, 5, 1, 7};
    cout<<arrayMin(arr, 5)<<endl;
    cin.ignore();
    cin.get();
    return 0;
}