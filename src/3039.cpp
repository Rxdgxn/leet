#include "../include.h"

class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, pair<int, int>> positions;
        int max_freq = 1;

        for (int i = 0; i < s.size(); i++) {
            if (positions.find(s[i]) == positions.end()) {
                positions[s[i]] = {i, 1};
            }
            else {
                positions[s[i]] = {i, positions[s[i]].second + 1};
                max_freq = max(max_freq, positions[s[i]].second);
            }
        }

        vector<pair<char, int>> rem;

        for (auto& [k, v] : positions) {
            if (v.second == max_freq) {
                rem.push_back({k, v.first});
            }
        }

        sort(rem.begin(), rem.end(), [&](pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        });

        string ret = "";
        for (auto& p : rem) {
            ret += p.first;
        }

        return ret;
    }
};