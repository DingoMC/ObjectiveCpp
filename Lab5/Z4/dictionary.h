#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <map>
using namespace std;
class Dictionary {
    private:
        map <string, string> words;
        static string lowercase (string s);
        static bool compare (pair <string, string> el1, pair <string, string> el2);
    public:
        Dictionary ();
        void add (const string &word, const string &translation);
        void remove (const string &word);
        void show ();
        void getTranslation (const string &word);
        void showZToA ();
};
#endif // !DICTIONARY_H