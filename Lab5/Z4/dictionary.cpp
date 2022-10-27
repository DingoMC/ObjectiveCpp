#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "dictionary.h"
using namespace std;
Dictionary::Dictionary () {

}
string Dictionary::lowercase (string s) {
    string f = "";
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) >= 65 && s.at(i) <= 90) f += (char) (s.at(i) + 32);
        else f += s.at(i);
    }
    return f;
}
bool Dictionary::compare (pair <string, string> el1, pair <string, string> el2) {
    string t1 = el1.second, t2 = el2.second;
    int t1l = t1.length(), t2l = t2.length();
    if (t1l > t2l) {
        for (int i = t2l; i < t1l; i++) t2 += '0';
    }
    if (t1l < t2l) {
        for (int i = t1l; i < t2l; i++) t1 += '0';
    }
    t1l = t1.length();
    for (int i = 0; i < t1l; i++) {
        if (t1.at(i) > t2.at(i)) return true;
        if (t1.at(i) < t2.at(i)) return false;
    }
    return true;
}
void Dictionary::add (const string &word, const string &translation) {
    string l_w = lowercase(word), l_t = lowercase(translation);
    if (this->words.find(l_w) != this->words.end()) {
        cout<<"Error at "<<__PRETTY_FUNCTION__<<": Word "<<l_w<<" already exists!"<<endl;
        return;
    }
    this->words.insert(make_pair(l_w, l_t));
}
void Dictionary::remove (const string &word) {
    string l_w = lowercase(word);
    if (this->words.find(l_w) == this->words.end()) {
        cout<<"Error at "<<__PRETTY_FUNCTION__<<": Cannot find word "<<l_w<<endl;
        return;
    }
    this->words.erase(l_w);
}
void Dictionary::show () {
    if (this->words.empty()) {
        cout<<"Error at "<<__PRETTY_FUNCTION__<<": Dictionary is empty!"<<endl;
        return;
    }
    for (map<string, string>::iterator i = this->words.begin(); i != this->words.end(); ++i) {
        cout<<i->first<<" -> "<<i->second<<endl;
    }
}
void Dictionary::getTranslation (const string &word) {
    string l_w = lowercase(word);
    if (this->words.find(l_w) == this->words.end()) {
        cout<<"Error at "<<__PRETTY_FUNCTION__<<": Cannot find word "<<l_w<<endl;
        return;
    }
    cout<<"Translation for "<<l_w<<": "<<this->words.find(l_w)->second<<endl;
}
void Dictionary::showZToA () {
    if (this->words.empty()) {
        cout<<"Error at "<<__PRETTY_FUNCTION__<<": Dictionary is empty!"<<endl;
        return;
    }
    vector <pair<string, string>> translations;
    for (map<string, string>::iterator i = this->words.begin(); i != this->words.end(); ++i) {
        translations.push_back(make_pair(i->first, i->second));
    }
    sort(translations.begin(), translations.end(), compare);
    for (int i = 0; i < translations.size(); i++) {
        cout<<translations[i].first<<" -> "<<translations[i].second<<endl;
    }
}