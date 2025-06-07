#include "../include.h"

class Solution {
public:
    string clearStars(string s) {
        string ret;
        map<char, vector<int>> indices;

        for (int i = 0; i < s.size(); i++) {
            if ('a' <= s[i] && s[i] <= 'z') {
                indices[s[i]].push_back(i);
            }
            else {
                auto& p = *indices.begin();

                s[p.second.back()] = '|';
                p.second.pop_back();

                if (p.second.empty())
                    indices.erase(indices.begin());
            }
        }

        for (int i = 0; i < s.size(); i++)
            if ('a' <= s[i] && s[i] <= 'z')
                ret += s[i];

        return ret;
    }
};