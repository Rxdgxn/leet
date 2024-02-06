#include "../include.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;

        // Thank you GPT
        auto vectorHash = [](const vector<int>& v) {
            hash<int> hasher;
            size_t result = 0;
            for (int i : v) {
                result ^= hasher(i) + 0x9e3779b9 + (result << 6) + (result >> 2);
            }
            return result;
        };

        // Could've just used a string instead of vector<int> to avoid vectorHash
        unordered_map<vector<int>, vector<string>, decltype(vectorHash)> mp(10000, vectorHash);

        for (const string& s : strs) {
            auto tmp = vector<int>(26, 0);

            for (const char& c : s) tmp[c - 'a']++;

            mp[tmp].push_back(s);
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
            ret.push_back(it->second);

        return ret;
    }
};