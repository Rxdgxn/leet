#include "../include.h"

class Solution {
public:
    unordered_map<string, string> edges;
    string c;

    void dfs(string city) {
        if (edges[city].empty()) {
            c = city;
            return;
        }
        
        dfs(edges[city]);
    }

    string destCity(vector<vector<string>>& paths) {
        for (const auto&p : paths)
            edges[p[0]] = p[1];

        dfs(paths[0][0]);

        return c;
    }
};