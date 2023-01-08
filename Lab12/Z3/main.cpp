#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#pragma GCC optimize("O3")

using namespace std;

tuple<unsigned, double, string> stats (const vector<string> &Vec) {
    double mean = 0.0;
    unsigned dnn = (*min_element(Vec.begin(), Vec.end(), [] (string s1, string s2) { return s1.length() < s2.length(); })).length();
    for_each(Vec.begin(), Vec.end(), [&mean] (string s) { mean += (s.length() * 1.0); });
    mean /= (Vec.size() * 1.0);
    string nn = *max_element(Vec.begin(), Vec.end(), [] (string s1, string s2) { return s1.length() < s2.length(); });
    return make_tuple(dnn, mean, nn);
}

int main () {
    vector <string> S;
    S.push_back("abcd");
    S.push_back("abcdef");
    S.push_back("a");
    S.push_back("abc");
    S.push_back("abcdefgh");
    S.push_back("ab");
    tuple<unsigned, double, string> t = stats(S);
    cout<<"Dlugosc najkrotszego napisu: "<<get<0>(t)<<endl;
    cout<<"Srednia dlugosc napisu: "<<get<1>(t)<<endl;
    cout<<"Najdluzszy napis: "<<get<2>(t)<<endl;
    // END //
    cin.ignore();
    cin.get();
    return 0;
}