#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int CommentIndex (string line) {
    for (int i = 1; i < line.length(); i++) {
        if (line.at(i) == '/' && line.at(i-1) == '/') return (i-1);
    }
    return -1;
}
bool IsEmpty (string line, int c_index) {
    for (int i = 0; i < c_index; i++) {
        if (line.at(i) > 32) return false;
    }
    return true;
}
void showPart (string line, int c_index) {
    if (IsEmpty(line, c_index)) return;
    for (int i = 0; i < c_index; i++) {
        cout<<line.at(i);
    }
    cout<<endl;
}
void openFile (ifstream &p, string n) {
    p.open(n);
    if (!p) throw runtime_error("Could not open file!");
}
int main () {
    ifstream p;
    try {
        openFile(p, "Z1.txt");
    }
    catch (exception &ex) {
        cout<<"Blad odczytu pliku!"<<endl;
        cin.ignore();
        cin.get();
        return 0;
    }
    string l;
    while (getline(p, l)) {
        if (CommentIndex(l) == -1) cout<<l<<endl;
        else showPart(l, CommentIndex(l));
    }
    cin.ignore();
    cin.get();
    return 0;
}