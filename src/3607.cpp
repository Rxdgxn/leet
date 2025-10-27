#include "../include.h"

class Solution {
public:
    unordered_map<int, int> status; // on/off
    unordered_map<int, set<int>> grids; // component_id -> components
    unordered_map<int, int> comp_id; // station -> c_id

    unordered_map<int, vector<int>> graph;

    void dfs(int node, int c_id) {
        if (comp_id.find(node) != comp_id.end())
            return;

        grids[c_id].insert(node);
        comp_id[node] = c_id;

        for (int nei : graph[node])
            dfs(nei, c_id);
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        for (auto& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int component_id = 0;

        for (int i = 1; i <= c; i++) {
            status[i] = 1;

            if (comp_id.find(i) == comp_id.end()) {
                dfs(i, component_id);
                component_id++;
            }
        }

        vector<int> ret;

        for (auto& q : queries) {
            if (q[0] == 2) {
                status[q[1]] = 0;
                grids[comp_id[q[1]]].erase(q[1]);
            }
            else {
                if (status[q[1]] == 1) {
                    ret.push_back(q[1]);
                }
                else {
                    if (grids[comp_id[q[1]]].empty()) {
                        ret.push_back(-1);
                    }
                    else {
                        ret.push_back(*grids[comp_id[q[1]]].begin());
                    }
                }
            }
        }

        return ret;
    }
};