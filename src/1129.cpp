#include "../include.h"

class Solution {
public:
    struct State {
        int u, v;
        int color, dist;
    };

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<pair<int, int>>> graph; // u -> (v, edge_color)

        for (auto& e : redEdges) {
            graph[e[0]].push_back(make_pair(e[1], 0));
        }

        for (auto& e : blueEdges) {
            graph[e[0]].push_back(make_pair(e[1], 1));
        }

        queue<State> q;
        vector<vector<vector<char>>> traversed(2, vector<vector<char>>(101, vector<char>(101, 0))); // (color, u, v)

        unordered_map<int, int> min_distances;

        for (auto& p : graph[0]) {
            q.push({0, p.first, p.second, 1});
        }

        min_distances[0] = 0;

        while (!q.empty()) {
            State s = q.front();
            q.pop();

            traversed[s.color][s.u][s.v] = 1;

            if (min_distances.find(s.v) == min_distances.end()) {
                min_distances[s.v] = s.dist;
            }
            else {
                min_distances[s.v] = min(min_distances[s.v], s.dist);
            }

            for (auto& p : graph[s.v]) {
                if (s.color != p.second && !traversed[p.second][s.v][p.first]) {
                    q.push({s.v, p.first, p.second, s.dist + 1});
                }
            }
        }

        vector<int> ret(n);

        for (int i = 0; i < n; i++) {
            if (min_distances.find(i) == min_distances.end()) {
                ret[i] = -1;
            }
            else {
                ret[i] = min_distances[i];
            }
        }

        return ret;
    }
};