#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> players, losses;

        for (auto& p : matches) {
            if (!players[p[0]]) players[p[0]] = 1;
            if (!players[p[1]]) players[p[1]] = 1;

            losses[p[1]]++;
        }

        vector<int> zero, one;

        for (auto it = players.begin(); it != players.end(); it++)
            if (losses[it->first] == 0) zero.push_back(it->first);
            else if (losses[it->first] == 1) one.push_back(it->first);

        sort(zero.begin(), zero.end());
        sort(one.begin(), one.end());
        
        return {zero, one};
    }
};