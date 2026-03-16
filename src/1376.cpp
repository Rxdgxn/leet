#include "../include.h"

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < n; i++)
            if (i != headID)
                graph[manager[i]].push_back(i);

        int ret = 0;

        queue<pair<int, int>> q; // (id, time)
        q.push({headID, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            ret = max(ret, curr.second);

            for (int child : graph[curr.first])
                q.push({child, curr.second + informTime[curr.first]});
        }

        return ret;
    }
};