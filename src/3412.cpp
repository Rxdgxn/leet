#include "../include.h"

class Solution {
public:
    long long calculateScore(string s) {
        char mirror[26];

        for (int i = 0; i < 26; i++)
            mirror[i] = 'a' + 25 - i;

        unordered_map<char, vector<int>> indices;
        long long score = 0;

        for (int i = 0; i < s.size(); i++) {
            auto& pq = indices[mirror[s[i] - 'a']];

            if (pq.empty()) {
                indices[s[i]].push_back(i);
                continue;
            }

            score += (i - pq.back());
            pq.pop_back();
        }

        return score;
    }
};