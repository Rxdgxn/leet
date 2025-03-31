#include "../include.h"

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;

        for (const string& w : words) {
            unordered_map<char, char> p1, p2;
            bool matches = true;

            for (int i = 0; i < pattern.size(); i++) {
                if (p1.find(w[i]) == p1.end()) {
                    p1[w[i]] = pattern[i];

                    if (p2.find(pattern[i]) != p2.end()) {
                        matches = false;
                        break;
                    }

                    p2[pattern[i]] = w[i];
                }
                else if (pattern[i] != p1[w[i]]) {
                    matches = false;
                    break;
                }
            }

            if (matches) ret.push_back(w);
        }

        return ret;
    }
};