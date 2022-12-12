#include <iostream>
#include <regex>
using namespace std;
bool isHour (string str) {
    return regex_match(str, regex("([0-1][0-9]|[2][0-3]):[0-5][0-9](:[0-5][0-9])?"));
}
int main () {
    cout<<isHour("24:00")<<endl;
    cout<<isHour("23:59:09")<<endl;
    cout<<isHour("23:60")<<endl;
    cout<<isHour("00:00:00")<<endl;
    cout<<isHour("09:09:09")<<endl;
    cin.ignore();
    cin.get();
    return 0;
}