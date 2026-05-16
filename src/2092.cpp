#include "../include.h"

class Solution {
public:
    typedef unordered_map<int, vector<int>> Graph;

    vector<int> knows_secret; // time at which person knows the secret

    void dfs(int node, vector<int>& curr_path, unordered_set<int>& visited, bool& update, Graph& g) {
        visited.insert(node);

        if (knows_secret[node] != -1)
            update = true;
        else
            curr_path.push_back(node);

        for (int neigh : g[node]) {
            if (visited.find(neigh) != visited.end())
                continue;

            dfs(neigh, curr_path, visited, update, g);
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, Graph> time_graph;

        for (auto& m : meetings) {
            time_graph[m[2]][m[0]].push_back(m[1]);
            time_graph[m[2]][m[1]].push_back(m[0]);
        }

        vector<int> ret;
        knows_secret = vector<int>(n, -1);

        knows_secret[0] = 0;
        knows_secret[firstPerson] = 0;

        for (auto& [time, g] : time_graph) {
            unordered_set<int> visited;

            for (auto& [node, neighs] : g) {
                if (visited.find(node) != visited.end())
                    continue;

                vector<int> path;
                bool update = false;

                dfs(node, path, visited, update, g);

                if (update) {
                    for (int node : path)
                        knows_secret[node] = time;
                }
            }
        }

        for (int i = 0; i < n; i++)
            if (knows_secret[i] != -1)
                ret.push_back(i);

        return ret;
    }
};