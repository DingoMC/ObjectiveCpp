#include <iostream>
#include <regex>
using namespace std;
bool isStreet (string str) {
    return regex_match(str, regex("[A-Za-z ]+"));
}
bool isPostalCode (string str) {
    return regex_match(str, regex("[0-9]{2}-[0-9]{3}"));
}
bool isHouseNo (string str) {
    return regex_match(str, regex("[1-9][0-9]*[A-Z]?"));
}
bool isFlatNo (string str) {
    return regex_match(str, regex("[1-9][0-9]*"));
}
int main () {
    cout<<isStreet("Nadbystrzycka")<<endl;
    cout<<isStreet("Aleja Krasnicka")<<endl;
    cout<<isPostalCode("20-604")<<endl;
    cout<<isPostalCode("59604")<<endl;
    cout<<isHouseNo("78")<<endl;
    cout<<isHouseNo("A")<<endl;
    cout<<isFlatNo("13")<<endl;
    cout<<isFlatNo("2")<<endl;
    cin.ignore();
    cin.get();
    return 0;
}