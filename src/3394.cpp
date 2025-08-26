#include "../include.h"

class Solution {
public:
    typedef pair<int, int> p_int;

    vector<p_int> merge(vector<p_int>& v) {
        sort(v.begin(), v.end());

        vector<p_int> mv;
        p_int prev = {0, 0};

        for (auto& p : v) {
            if (p.first < prev.second) {
                mv.pop_back();
                p_int new_p = {prev.first, max(prev.second, p.second)};
                mv.push_back(new_p);
                prev = new_p;
            }
            else {
                mv.push_back(p);
                prev = p;
            }
        }

        return mv;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<p_int> vertical, horizontal;

        for (auto& rect : rectangles) {
            vertical.push_back({rect[1], rect[3]});
            horizontal.push_back({rect[0], rect[2]});
        }

        auto merged_vertical = merge(vertical);
        auto merged_horizontal = merge(horizontal);

        if (merged_vertical.size() >= 3)
            return true;
        if (merged_horizontal.size() >= 3)
            return true;

        return false;
    }
};