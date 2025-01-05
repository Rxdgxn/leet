#include "../include.h"

class Solution {
public:
    inline void shift(char *c, int t) {
        if (t == 0) return;

        int sgn = t / abs(t);
        t = abs(t);
        t %= 26;

        int s = *c + sgn * t;

        if (s < 'a') s = 'z' - ('a' - s - 1);
        else if (s > 'z') s = 'a' + (s - 'z' - 1);

        *c = static_cast<char>(s);
    }

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int n = s.size();
        vector<int> transforms(n, 0);

        for (const auto& shift : shifts) {
            const int modifier = (shift[2] == 1 ? 1 : -1);

            transforms[shift[0]] += modifier;

            if (shift[1] + 1 < n)
                transforms[shift[1] + 1] -= modifier;
        }

        shift(&s[0], transforms[0]);

        int prev = transforms[0];

        for (int i = 1; i < n; i++) {
            shift(&s[i], transforms[i] + prev);
            prev += transforms[i];
        }

        return s;
    }
};