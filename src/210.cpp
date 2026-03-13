#include "../include.h"

class Solution {
public:
    unordered_map<int, vector<int>> must_take;
    unordered_set<int> visited, processing;
    bool possible = true;

    void traverse(int c, vector<int>& courses) {
        if (!possible)
            return;

        visited.insert(c);
        processing.insert(c);

        for (int dep : must_take[c]) {
            if (processing.find(dep) != processing.end()) {
                possible = false;
                return;
            }

            if (visited.find(dep) != visited.end())
                continue;

            traverse(dep, courses);
        }

        processing.erase(c);
        courses.emplace_back(c);
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        for (auto& p : prerequisites)
            must_take[p[0]].push_back(p[1]);

        vector<int> ret;
        ret.reserve(n);

        for (int i = 0; i < n; i++) {
            if (visited.find(i) != visited.end())
                continue;

            traverse(i, ret);

            if (!possible)
                return {};
        }

        return ret;
    }
};