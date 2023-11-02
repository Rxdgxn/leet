#include "../include.h"

class Solution {
public:
    enum class Quantity {
        Fixed = 1,
        Undetermined = 2
    };

    bool isMatch(string s, string p) {
        vector<pair<Quantity, pair<char, int>>> letters, pattern; // (Quantity, (char, len))
        int i, it_l, it_p, len;

        // String processing
        char last = 0, ch;
        len = 1;
        for (i = 0; i < s.size() - 1; i++) {
            ch = s[i];

            if (ch == last) len++;
            else {
                if (last != 0) letters.push_back(make_pair(Quantity::Fixed, make_pair(last, len)));
                len = 1;
            }

            last = ch;
        }
        // Last character
        ch = s[i];
        if (ch != last) {
            letters.push_back(make_pair(Quantity::Fixed, make_pair(last, len)));
            letters.push_back(make_pair(Quantity::Fixed, make_pair(ch, 1)));
        }
        else letters.push_back(make_pair(Quantity::Fixed, make_pair(ch, len + 1)));


        // Pattern processing (should be reversed) (seems ok?)
        last = 0;
        len = 1;
        for (i = p.size() - 1; i > 0; i--) {
            if (p[i] == '*') {
                if (len > 1) pattern.push_back(make_pair(Quantity::Fixed, make_pair(last, len)));
                else if (last != 0 && last != '*') pattern.push_back(make_pair(Quantity::Fixed, make_pair(last, 1)));

                pattern.push_back(make_pair(Quantity::Undetermined, make_pair(p[--i], 1)));
                last = '*';
                continue;
            }
            else {
                if (p[i] == last) len++;
                else {
                    if (last != 0 && last != '*') pattern.push_back(make_pair(Quantity::Fixed, make_pair(last, len)));
                    len = 1;
                }
            }

            last = p[i];
        }
        // First character
        if (p[0] != last) {
            if (last != 0 && last != '*') pattern.push_back(make_pair(Quantity::Fixed, make_pair(last, len)));
            if (last != '*') pattern.push_back(make_pair(Quantity::Fixed, make_pair(p[0], 1)));
        }
        else pattern.push_back(make_pair(Quantity::Fixed, make_pair(p[0], len + 1)));
        
        for (auto it = pattern.rbegin(); it != pattern.rend(); it++)
            cout << (it->first == Quantity::Fixed ? "FIXED" : "UNDETERMINED") << " " << it->second.first << endl;
        
        // Main logic (TODO)
        it_l = 0, it_p = pattern.size() - 1;
        while (it_l < letters.size() && it_p >= 0) {
            if (pattern[it_p].first == Quantity::Undetermined && pattern[it_p].second.first == '.') {
                if (it_p == 0) return true;
                else {
                    while (it_p >= 0) {
                        if (pattern[it_p].first != Quantity::Undetermined) return false;
                        it_p--;
                    }
                    return true;
                }
            }
            else {
                if (pattern[it_p].second == letters[it_l].second || (pattern[it_p].second.first == '.' && pattern[it_p].second.second == letters[it_l].second.second) || (pattern[it_p].first > letters[it_l].first && pattern[it_p].second.first == letters[it_l].second.first)) {
                    if (pattern[it_p].first >= letters[it_l].first) {
                        it_l++;
                        it_p--;
                    }
                    else return false;
                }
                else {
                    if (pattern[it_p].first == Quantity::Undetermined) it_p--;
                    else return false;
                }
            }
        }
        
        return true && it_p == -1 && it_l == letters.size();
    }
};

// TODO
// "aaa"
// "a.a"