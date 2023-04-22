#include "include.h"

inline short diff(string s) {
    return (s[0] != 'S') + (s[1] != 'O') + (s[2] != 'S');
}

int marsExploration(string s) {
    int t = 0;

    for (int i = 0; i < s.size(); i += 3)
        t += diff(s.substr(i, 3));

    return t;
}

int main(void) {

    string s;
    cin >> s;

    cout << marsExploration(s);

    return 0;
}