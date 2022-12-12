#include <iostream>
#include <regex>
using namespace std;
bool floatFound (string str) {
    return regex_match(str, regex("(\\+|\\-)[0-9]+[\\.][0-9]+"));
}
int main () {
    cout<<floatFound("+1.254")<<endl;
    cout<<floatFound("-3.37745")<<endl;
    cout<<floatFound("+0.444")<<endl;
    cout<<floatFound("-1.7")<<endl;
    cout<<floatFound("+u77.254")<<endl;
    cout<<floatFound("-19.254")<<endl;
    cin.ignore();
    cin.get();
    return 0;
}