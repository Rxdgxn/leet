#include "../include.h"

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    return nullptr;
}();

class Solution {
public:
    vector<int> queryResults(int _limit, vector<vector<int>>& queries) {
        vector<int> ret;
        int colors = 0;
        unordered_map<int, int> ball_color, color_occ;

        for (const auto& q : queries) {
            if (ball_color[q[0]]) {
                color_occ[ball_color[q[0]]]--;

                if (color_occ[ball_color[q[0]]] == 0)
                    colors--;
            }

            ball_color[q[0]] = q[1];
            color_occ[q[1]]++;

            if (color_occ[q[1]] == 1)
                colors++;

            ret.push_back(colors);
        }

        return ret;
    }
};