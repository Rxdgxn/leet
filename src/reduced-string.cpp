#include "../include.h"

string superReducedString(string& s) {
    int i = 0;

    while (i < s.size() - 1 && s.size()) {
        if (s[i] == s[i+1]) {
            s.erase(s.begin() + i);
            s.erase(s.begin() + i);
            if (i) i--;
        }
        else i++;
    }

    return (s.size() ? s : "Empty String");
}

int main(void) {

    string s;
    cin >> s;
    cout << superReducedString(s);

    return 0;
}