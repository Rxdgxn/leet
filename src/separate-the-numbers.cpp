#include "../include.h"

void separateNumbers(string s) {
    string first;

    const int sz = s.size();

    for (int i = 1; i <= sz / 2; i++) {
        int off = 0, ok = 1, cnt;
        string curr = s.substr(off, i), x = curr;
        cnt = curr.size();

        while (off + cnt < sz) {
            const int eps = to_string(stoll(curr) + 1).size() - curr.size();
            off += curr.size();
            cnt += eps;

            string nxt = s.substr(off, cnt);

            if (stoll(nxt) - stoll(curr) != 1) {
                ok = 0;
                break;
            }

            curr = nxt;
        }

        if (ok) {
            first = x;
            break;
        }
    }

    if (first.empty()) cout << "NO";
    else cout << "YES " << first;

    cout << endl;
}

int main(void) {
    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        separateNumbers(s);
    }

    return 0;
}