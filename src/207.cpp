#include "../include.h"

class Solution {
public:
    unordered_map<int, vector<int>> depends_on;
    unordered_set<int> solved;

    bool helper(int course, unordered_set<int>& processing) {
        if (solved.find(course) != solved.end())
            return true;

        if (processing.find(course) != processing.end())
            return false;

        processing.insert(course);

        for (int dependency : depends_on[course]) {
            if (!helper(dependency, processing))
                return false;
        }

        solved.insert(course);
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        for (auto& p : prerequisites) {
            depends_on[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < n; i++) {
            unordered_set<int> processing;
            
            if (!helper(i, processing))
                return false;
        }

        return true;
    }
};