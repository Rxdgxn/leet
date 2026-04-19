#include "../include.h"

class Solution {
public:
    unordered_map<string, vector<string>> graph;
    vector<string> ret;

    void dfs(string curr) {
        while (!graph[curr].empty()) {
            string next = graph[curr].back();
            graph[curr].pop_back();

            dfs(next);
        }

        ret.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& v : tickets)
            graph[v[0]].push_back(v[1]);

        for (auto& [_, v] : graph)
            sort(v.begin(), v.end(), greater<string>());

        dfs("JFK");

        reverse(ret.begin(), ret.end());
        return ret;
    }
};