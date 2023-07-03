#include "../include.h"

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        map<char, char> m;
        int diff = 0;

        if (s == goal) {
            map<char, int> freq;
            for (int i = 0; i < s.size(); i++) {
                if (freq[s[i]]) {
                    return true;
                }
                else {
                    freq[s[i]] = 1;
                }
            }
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                diff++;
                m[s[i]] = goal[i];
            }
        }

        if (diff != 2) return false;

        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->first != m[it->second]) return false;
        }

        return true;
    }
};