#include "include.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> m;
        map<string, bool> taken;
        vector<string> words;
        
        stringstream ss(s);
        string x;
        while (ss >> x) words.push_back(x);

        if (pattern.size() != words.size()) return false;

        for (int i = 0; i < pattern.size(); i++) {
            if (m[pattern[i]].empty() && !taken[words[i]]) {
                m[pattern[i]] = words[i];
                taken[words[i]] = true;
            }
            else {
                if (m[pattern[i]] != words[i]) return false;
            }
        }

        return true;
    }
};